#include <eigen-checks/entrypoint.h>
#include <eigen-checks/gtest.h>

#include "test_helper.h"

TYPED_TEST(EigenChecks, EigenMatrixEqual_Matrix_Equal) {
  EXPECT_TRUE(EIGEN_MATRIX_EQUAL(this->ground_truth_matrix_54,
                                 this->test_matrix_54_equal));
}

TYPED_TEST(EigenChecks, EigenMatrixEqual_Matrix_NonEqualRandom) {
  EXPECT_FALSE(EIGEN_MATRIX_EQUAL(this->ground_truth_matrix_54,
                                  this->test_matrix_54_random));
}

TYPED_TEST(EigenChecks, EigenMatrixEqual_Matrix_OtherSize) {
  EXPECT_FALSE(EIGEN_MATRIX_EQUAL(this->ground_truth_matrix_54,
                                  this->test_matrix_D4));
}

TYPED_TEST(EigenChecks, EigenMatrixEqual_Matrix_Near5) {
  EXPECT_FALSE(EIGEN_MATRIX_EQUAL(this->ground_truth_matrix_54,
                                  this->test_matrix_54_near_e_minus_5));
}

TYPED_TEST(EigenChecks, EigenMatrixEqual_Vector_Equal) {
  EXPECT_TRUE(EIGEN_MATRIX_EQUAL(this->ground_truth_vector_5,
                                 this->test_vector_5_equal));
}

TYPED_TEST(EigenChecks, EigenMatrixEqual_Vector_NonEqualRandom) {
  EXPECT_FALSE(EIGEN_MATRIX_EQUAL(this->ground_truth_vector_5,
                                  this->test_vector_5_random));
}

TYPED_TEST(EigenChecks, EigenMatrixEqual_Vector_OtherSize) {
  EXPECT_FALSE(EIGEN_MATRIX_EQUAL(this->ground_truth_vector_5,
                                  this->test_vector_D));
}

TYPED_TEST(EigenChecks, EigenMatrixEqual_Vector_Near5) {
  EXPECT_FALSE(EIGEN_MATRIX_EQUAL(this->ground_truth_vector_5,
                                  this->test_vector_5_near_e_minus_5));
}

UNITTEST_ENTRYPOINT
