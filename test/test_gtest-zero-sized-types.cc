#include <eigen-checks/entrypoint.h>
#include <eigen-checks/gtest.h>

#include "test_helper.h"

TEST(EigenChecks, EigenMatrixEqualGtest_Zero_Sized_Dynamic_Matrix) {
  Eigen::Matrix2Xd A;
  Eigen::Matrix2Xd B(2, 3);
  EXPECT_FALSE(EIGEN_MATRIX_NEAR(A, B, 0.01));
  EXPECT_TRUE(EIGEN_MATRIX_NEAR(A, A, 0.01));
}

TEST(EigenChecks, EigenVectorEqualGtest_Zero_Sized_Dynamic_Vector) {
  Eigen::VectorXd A;
  Eigen::VectorXd B(3);
  EXPECT_FALSE(EIGEN_MATRIX_NEAR(A, B, 0.01));
  EXPECT_TRUE(EIGEN_MATRIX_NEAR(A, A, 0.01));
}

UNITTEST_ENTRYPOINT
