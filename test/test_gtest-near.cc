#include <eigen-checks/entrypoint.h>
#include <eigen-checks/gtest.h>

#include "test_helper.h"

TYPED_TEST(EigenChecks, EigenMatrixNear_Matrix_Equal) {
  EXPECT_TRUE(EIGEN_MATRIX_NEAR(this->ground_truth_matrix_54,
                                this->test_matrix_54_equal,
                                1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixNear_Matrix_NonEqualRandom) {
  EXPECT_FALSE(EIGEN_MATRIX_NEAR(this->ground_truth_matrix_54,
                                 this->test_matrix_54_random,
                                 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixNear_Matrix_OtherSize) {
  EXPECT_FALSE(EIGEN_MATRIX_NEAR(this->ground_truth_matrix_54,
                                 this->test_matrix_D4,
                                 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixNear_Matrix_Near5) {
  EXPECT_TRUE(EIGEN_MATRIX_NEAR(this->ground_truth_matrix_54,
                                this->test_matrix_54_near_e_minus_5,
                                1e-4));
}

TYPED_TEST(EigenChecks, EigenMatrixNear_Vector_Equal) {
  EXPECT_TRUE(EIGEN_MATRIX_NEAR(this->ground_truth_vector_5,
                                this->test_vector_5_equal,
                                1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixNear_Vector_NonEqualRandom) {
  EXPECT_FALSE(EIGEN_MATRIX_NEAR(this->ground_truth_vector_5,
                                 this->test_vector_5_random,
                                 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixNear_Vector_OtherSize) {
  EXPECT_FALSE(EIGEN_MATRIX_NEAR(this->ground_truth_vector_5,
                                 this->test_vector_D,
                                 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixNear_Vector_Near5) {
  EXPECT_TRUE(EIGEN_MATRIX_NEAR(this->ground_truth_vector_5,
                                this->test_vector_5_near_e_minus_5,
                                1e-4));
}

UNITTEST_ENTRYPOINT
