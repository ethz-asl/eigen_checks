#include <eigen-checks/entrypoint.h>
#include <eigen-checks/glog.h>

#include "test_helper.h"

TYPED_TEST(EigenChecks, EigenMatrixNearGLog_Matrix_Equal) {
  GLOG_TEST_EXPECT_NO_DEATH(CHECK_EIGEN_MATRIX_NEAR(this->ground_truth_matrix_54,
                                              this->test_matrix_54_equal,
                                              1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixNearGLog_Matrix_EqualFloatingPoint) {
  GLOG_TEST_EXPECT_NO_DEATH(
      CHECK_EIGEN_MATRIX_NEAR(this->ground_truth_matrix_54,
                        this->test_matrix_54_equal_floating_point, 1e-9));
}

TYPED_TEST(EigenChecks, EigenMatrixNearGLog_Matrix_NonEqualRandom) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(CHECK_EIGEN_MATRIX_NEAR(
      this->ground_truth_matrix_54, this->test_matrix_54_random, 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixNearGLog_Matrix_OtherSize) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_SIZE(
      CHECK_EIGEN_MATRIX_NEAR(this->ground_truth_matrix_54,
                              this->test_matrix_D4, 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixNearGLog_Matrix_Near5) {
  GLOG_TEST_EXPECT_NO_DEATH(CHECK_EIGEN_MATRIX_NEAR(
      this->ground_truth_matrix_54, this->test_matrix_54_near_e_minus_5, 1e-4));
}

TYPED_TEST(EigenChecks, EigenMatrixNearGLog_Vector_Equal) {
  GLOG_TEST_EXPECT_NO_DEATH(CHECK_EIGEN_MATRIX_NEAR(
      this->ground_truth_vector_5, this->test_vector_5_equal, 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixNearGLog_Vector_EqualFloatingPoint) {
  GLOG_TEST_EXPECT_NO_DEATH(
      CHECK_EIGEN_MATRIX_NEAR(this->ground_truth_vector_5,
                              this->test_vector_5_equal_floating_point,
                              1e-9));
}

TYPED_TEST(EigenChecks, EigenMatrixNearGLog_Vector_NonEqualRandom) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(CHECK_EIGEN_MATRIX_NEAR(
      this->ground_truth_vector_5, this->test_vector_5_random, 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixNearGLog_Vector_OtherSize) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_SIZE(CHECK_EIGEN_MATRIX_NEAR(
      this->ground_truth_vector_5, this->test_vector_D, 1e-8));
}

TYPED_TEST(EigenChecks, EigenMatrixNearGLog_Vector_Near5) {
  GLOG_TEST_EXPECT_NO_DEATH(
      CHECK_EIGEN_MATRIX_NEAR(this->ground_truth_vector_5,
                        this->test_vector_5_near_e_minus_5, 1e-4));
}

UNITTEST_ENTRYPOINT
