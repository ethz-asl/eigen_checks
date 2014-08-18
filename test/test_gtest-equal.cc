#include <eigen-checks/entrypoint.h>
#include <eigen-checks/gtest.h>

#include "test_helper.h"

TYPED_TEST(EigenChecks, EigenMatrixEqual_Equal) {
  EXPECT_TRUE(EIGEN_MATRIX_EQUAL(this->ground_truth_vector_5,
                                 this->test_vector_5_equal));
}

TYPED_TEST(EigenChecks, EigenMatrixEqual_NonEqualRandom) {
  EXPECT_FALSE(EIGEN_MATRIX_EQUAL(this->ground_truth_vector_5,
                                  this->test_vector_5_random));
}

TYPED_TEST(EigenChecks, EigenMatrixEqual_OtherSize) {
  EXPECT_FALSE(EIGEN_MATRIX_EQUAL(this->ground_truth_vector_5,
                                  this->test_vector_D));
}

TYPED_TEST(EigenChecks, EigenMatrixEqual_Near5) {
  EXPECT_FALSE(EIGEN_MATRIX_EQUAL(this->ground_truth_vector_5,
                                  this->test_vector_5_near_e_minus_5));
}

TYPED_TEST(EigenChecks, EigenMatrixEqual_Near8) {
  EXPECT_FALSE(EIGEN_MATRIX_EQUAL(this->ground_truth_vector_5,
                                  this->test_vector_5_near_e_minus_8));
}

TYPED_TEST(EigenChecks, EigenMatrixEqual_EqualFloatingPoint) {
  EXPECT_FALSE(EIGEN_MATRIX_EQUAL(this->ground_truth_vector_5,
                                  this->test_vector_5_equal_floating_point));
}

UNITTEST_ENTRYPOINT


//Eigen::Matrix<Scalar, 5, 4> ground_truth_matrix_54;
//Eigen::Matrix<Scalar, Eigen::Dynamic, 4> test_matrix_D4;
//Eigen::Matrix<Scalar, 5, 4> test_matrix_54_random;
//Eigen::Matrix<Scalar, 5, 4> test_matrix_54_near_e_minus_8;
//Eigen::Matrix<Scalar, 5, 4> test_matrix_54_near_e_minus_5;
//Eigen::Matrix<Scalar, 5, 4> test_matrix_54_equal;
//Eigen::Matrix<Scalar, 5, 4> test_matrix_54_equal_floating_point;
