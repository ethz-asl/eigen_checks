#include <eigen-checks/entrypoint.h>
#include <eigen-checks/glog.h>
#include <gtest/gtest.h>

#include "test_helper.h"

TEST(EigenChecks, EigenMatrixEqualGlog_Zero_Sized_Dynamic_Matrix) {
  Eigen::Matrix2Xd A;
  Eigen::Matrix2Xd B(2, 3);
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(CHECK_EIGEN_MATRIX_NEAR(A, B, 0.01));
  GLOG_TEST_EXPECT_NO_DEATH(CHECK_EIGEN_MATRIX_NEAR(A, A, 0.01));
}

TEST(EigenChecks, EigenVectorEqualGlog_Zero_Sized_Dynamic_Vector) {
  Eigen::VectorXd A;
  Eigen::VectorXd B(3);
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(CHECK_EIGEN_MATRIX_NEAR(A, B, 0.01));
  GLOG_TEST_EXPECT_NO_DEATH(CHECK_EIGEN_MATRIX_NEAR(A, A, 0.01));
}

UNITTEST_ENTRYPOINT

