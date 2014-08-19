#include <eigen-checks/entrypoint.h>
#include <eigen-checks/glog.h>

#include "test_helper.h"

TYPED_TEST(EigenChecks, EigenMatrixEqualDoubleGLog_Matrix_Equal) {
  GLOG_TEST_EXPECT_NO_DEATH(
      CHECK_EIGEN_MATRIX_EQUAL_DOUBLE(this->ground_truth_matrix_54,
                                      this->test_matrix_54_equal));
}

TYPED_TEST(EigenChecks, EigenMatrixEqualDoubleGLog_Matrix_NonEqualRandom) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(
      CHECK_EIGEN_MATRIX_EQUAL_DOUBLE(this->ground_truth_matrix_54,
                                      this->test_matrix_54_random));
}

TYPED_TEST(EigenChecks, EigenMatrixEqualDoubleGLog_Matrix_OtherSize) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_SIZE(
      CHECK_EIGEN_MATRIX_EQUAL_DOUBLE(this->ground_truth_matrix_54,
                                      this->test_matrix_D4));
}

TYPED_TEST(EigenChecks, EigenMatrixEqualDoubleGLog_Matrix_Near5) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(
      CHECK_EIGEN_MATRIX_EQUAL_DOUBLE(this->ground_truth_matrix_54,
                                      this->test_matrix_54_near_e_minus_5));
}

TYPED_TEST(EigenChecks, EigenMatrixEqualDoubleGLog_Vector_Equal) {
  GLOG_TEST_EXPECT_NO_DEATH(
      CHECK_EIGEN_MATRIX_EQUAL_DOUBLE(this->ground_truth_vector_5,
                                      this->test_vector_5_equal));
}

TYPED_TEST(EigenChecks, EigenMatrixEqualDoubleGLog_Vector_NonEqualRandom) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(
      CHECK_EIGEN_MATRIX_EQUAL_DOUBLE(this->ground_truth_vector_5,
                                      this->test_vector_5_random));
}

TYPED_TEST(EigenChecks, EigenMatrixEqualDoubleGLog_Vector_OtherSize) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(
      CHECK_EIGEN_MATRIX_EQUAL_DOUBLE(this->ground_truth_vector_5,
                                      this->test_vector_D));
}

TYPED_TEST(EigenChecks, EigenMatrixEqualDoubleGLog_Vector_Near5) {
  GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(
      CHECK_EIGEN_MATRIX_EQUAL_DOUBLE(this->ground_truth_vector_5,
                                      this->test_vector_5_near_e_minus_5));
}

UNITTEST_ENTRYPOINT
