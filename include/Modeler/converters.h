#ifndef __CONVERTERS_H
#define __CONVERTERS_H

#include <opencv2/core/core.hpp>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <Eigen/Dense>
#include "sophus/se3.hpp"



namespace CARV_HELPERS
{
    cv::Mat se3ToCvMat(const Sophus::SE3<float>& se3);

    cv::Mat vector3fToCvMat(const Eigen::Vector3f& vector);

    Eigen::Vector3f matToEigenVector3f(const cv::Mat& mat);
}

#endif