#include <eigen-checks/entrypoint.h>
#include <eigen-checks/gtest.h>

#include "test_helper.h"

TYPED_TEST(EigenChecks, EigenMatrixZeroGTest_Matrix_Equal) {
  EXPECT_TRUE(EIGEN_MATRIX_ZERO(this->ground_truth_matrix_54_zero, 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGTest_Matrix_NonEqualRandom) {
  EXPECT_FALSE(EIGEN_MATRIX_ZERO(this->test_matrix_54_random, 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGTest_Matrix_OtherSize) {
  EXPECT_FALSE(EIGEN_MATRIX_ZERO(this->test_matrix_D4, 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGTest_Matrix_Near5) {
  EXPECT_FALSE(EIGEN_MATRIX_ZERO(this->test_matrix_54_near_e_minus_5, 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGTest_Vector_Equal) {
  EXPECT_TRUE(EIGEN_MATRIX_ZERO(this->test_vector_5_equal, 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGTest_Vector_NonEqualRandom) {
  EXPECT_FALSE(EIGEN_MATRIX_ZERO(this->test_vector_5_random, 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGTest_Vector_OtherSize) {
  EXPECT_FALSE(EIGEN_MATRIX_ZERO(this->test_vector_D, 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGTest_Vector_Near5) {
  EXPECT_FALSE(EIGEN_MATRIX_ZERO(this->test_vector_5_near_e_minus_5, 1e-8));
}

UNITTEST_ENTRYPOINT
