#ifndef EIGEN_CHECKS_GLOG_H_
#define EIGEN_CHECKS_GLOG_H_
#include <glog/logging.h>
#include <limits>
#include <eigen-checks/internal/gtest-equal.h>
#include <eigen-checks/internal/traits.h>

// We invoke the check method twice. Once to get the bool and once to obtain
// the message we want to output. This way we allow the user to append custom
// messages without declaring local variables.
#define EIGEN_CHECKS_INTERNAL_MAKE_GLOG_CHECK(X)                             \
  CHECK(static_cast<bool>(X)) << (X).message()

#define CHECK_EIGEN_MATRIX_EQUAL(MatrixA, MatrixB)                           \
  EIGEN_CHECKS_INTERNAL_MAKE_GLOG_CHECK(                                     \
    eigen_checks::internal::MatricesNear(                                    \
    MatrixA, #MatrixA, MatrixB, #MatrixB,                                    \
    static_cast<typename eigen_checks::internal::RemoveCR<                   \
    decltype(MatrixA)>::type::Scalar>(0.0), "0.0"))

#define CHECK_EIGEN_MATRIX_EQUAL_DOUBLE(MatrixA, MatrixB)                    \
  do {                                                                       \
    ::testing::AssertionResult result = eigen_checks::internal::MatricesNear(\
        MatrixA, #MatrixA, MatrixB, #MatrixB,                                \
        static_cast<typename eigen_checks::internal::RemoveCR<               \
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
