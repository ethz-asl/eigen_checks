#ifndef EIGEN_CHECKS_GLOG_H_
#define EIGEN_CHECKS_GLOG_H_
#include <limits>
#include <type_traits>

#include <eigen-checks/internal/gtest-equal.h>
#include <glog/logging.h>

#define CHECK_EIGEN_MATRIX_EQUAL(MatrixA, MatrixB)                           \
  do {                                                                       \
    ::testing::AssertionResult result = eigen_checks::internal::MatricesNear(\
        MatrixA, #MatrixA, MatrixB, #MatrixB,                                \
        static_cast<typename std::remove_reference<                          \
        decltype(MatrixA)>::type::Scalar>(0.0), "0.0");                      \
    CHECK(static_cast<bool>(result)) << result.message;                      \
  } while(0);

#define CHECK_EIGEN_MATRIX_EQUAL_DOUBLE(MatrixA, MatrixB)                    \
  do {                                                                       \
    ::testing::AssertionResult result = eigen_checks::internal::MatricesNear(\
        MatrixA, #MatrixA, MatrixB, #MatrixB,                                \
        static_cast<typename std::remove_reference<                          \
        decltype(MatrixA)>::type::Scalar>(                                   \
      eigen_checks::internal::kDefaultPrecision),                            \
      "Floating point precision");                                           \
    CHECK(static_cast<bool>(result)) << result.message;                      \
  } while(0);

#define CHECK_EIGEN_MATRIX_NEAR(MatrixA, MatrixB, Precision)                 \
  do {                                                                       \
    ::testing::AssertionResult result = eigen_checks::internal::MatricesNear(\
        MatrixA, #MatrixA, MatrixB, #MatrixB, Precision, #Precision);        \
    CHECK(static_cast<bool>(result)) << result.message;                      \
  } while(0);

#endif  // EIGEN_CHECKS_GLOG_H_
