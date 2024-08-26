#ifndef __CONVERTERS_CPP
#define __CONVERTERS_CPP

#include "Modeler/converters.h"

namespace CARV_HELPERS
{
    cv::Mat se3ToCvMat(const Sophus::SE3<float>& se3) {
        // Extract rotation matrix and translation vector
        Eigen::Matrix3f R = se3.rotationMatrix();
        Eigen::Vector3f t = se3.translation();

        // Create a 4x4 transformation matrix (CV_32F)
        cv::Mat cvTransform = cv::Mat::eye(4, 4, CV_32F);

        // Copy rotation matrix (3x3) to top-left corner of transformation matrix
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cvTransform.at<float>(i, j) = R(i, j);
            }
        }

        // Copy translation vector (1x3) to the last column of transformation matrix
        for (int i = 0; i < 3; ++i) {
            cvTransform.at<float>(i, 3) = t(i);
        }

        return cvTransform;
    }

    cv::Mat vector3fToCvMat(const Eigen::Vector3f& vector) {
        // Create cv::Mat with 1 row, 3 columns, and CV_32F type
        cv::Mat cvMat(1, 3, CV_32F);

        // Copy data from Eigen vector to cv::Mat
        cvMat.at<float>(0, 0) = vector(0);
        cvMat.at<float>(0, 1) = vector(1);
        cvMat.at<float>(0, 2) = vector(2);

        return cvMat;
    }

    Eigen::Vector3f matToEigenVector3f(const cv::Mat& mat) {
        Eigen::Vector3f eigenVec;

        if (mat.rows == 3 && mat.cols == 1 && mat.type() == CV_32F) {
            eigenVec << mat.at<float>(0, 0), mat.at<float>(1, 0), mat.at<float>(2, 0);
        } else {
            // Handle incorrect dimensions or types
            // For simplicity, here we throw an exception if the input is not as expected
            throw std::invalid_argument("Input cv::Mat is not a 3x1 matrix of type CV_32F");
        }

        return eigenVec;
    }
}

#endif