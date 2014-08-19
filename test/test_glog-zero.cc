#include <eigen-checks/entrypoint.h>
#include <eigen-checks/glog.h>

#include "test_helper.h"

TYPED_TEST(EigenChecks, EigenMatrixZeroGLog_Matrix_Equal) {
  GLOG_TEST_EXPECT_NO_DEATH(
      CHECK_EIGEN_MATRIX_ZERO(this->ground_truth_matrix_54_zero, 1e-5));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGLog_Matrix_NonEqualRandom) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(
      CHECK_EIGEN_MATRIX_ZERO(this->test_matrix_54_random, 1e-5));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGLog_Matrix_OtherSize) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_SIZE(
      CHECK_EIGEN_MATRIX_ZERO(this->test_matrix_D4, 1e-5));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGLog_Matrix_Near5) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(
      CHECK_EIGEN_MATRIX_ZERO(this->test_matrix_54_near_e_minus_5, 1e-5));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGLog_Vector_Equal) {
  GLOG_TEST_EXPECT_NO_DEATH(
      CHECK_EIGEN_MATRIX_ZERO(this->ground_truth_vector_5_zero, 1e-5));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGLog_Vector_NonEqualRandom) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(
      CHECK_EIGEN_MATRIX_ZERO(this->ground_truth_vector_5, 1e-5));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGLog_Vector_OtherSize) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(
      CHECK_EIGEN_MATRIX_ZERO(this->ground_truth_vector_5, 1e-5));
}

TYPED_TEST(EigenChecks, EigenMatrixZeroGLog_Vector_Near5) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(
      CHECK_EIGEN_MATRIX_ZERO(this->ground_truth_vector_5, 1e-5));
}

UNITTEST_ENTRYPOINT
