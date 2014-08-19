#ifndef EIGEN_CHECKS_GLOG_H_
#define EIGEN_CHECKS_GLOG_H_
#include <limits>
#include <type_traits>

#include <eigen-checks/internal/gtest-equal.h>
#include <glog/logging.h>

// To allow the user to append custom messages we store the result of the
// verification inside a unique local variable to be used in the check and for
// outputting the message.
#define INTERNAL_EIGEN_CHECKS_LOCAL_UNIQUE_VAR(var, line) var ## line
#define INTERNAL_EIGEN_CHECKS_MAKE_VAR(var, line) \
  INTERNAL_EIGEN_CHECKS_LOCAL_UNIQUE_VAR(var, line)

#define INTERNAL_EIGEN_CHECKS_MAKE_GLOG_CHECK(X)                             \
  ::testing::AssertionResult INTERNAL_EIGEN_CHECKS_MAKE_VAR(                 \
      result_, __LINE__) = (X);                                              \
  CHECK(static_cast<bool>(INTERNAL_EIGEN_CHECKS_MAKE_VAR(result_, __LINE__)))\
      << (INTERNAL_EIGEN_CHECKS_MAKE_VAR(result_, __LINE__)).message()

#define CHECK_EIGEN_MATRIX_EQUAL(MatrixA, MatrixB)                           \
  INTERNAL_EIGEN_CHECKS_MAKE_GLOG_CHECK(                                     \
    eigen_checks::internal::MatricesNear(                                    \
    MatrixA, #MatrixA, MatrixB, #MatrixB,                                    \
    static_cast<typename eigen_checks::internal::RemoveCR<                   \
    decltype(MatrixA)>::type::Scalar>(0.0), "0.0"))

#define CHECK_EIGEN_MATRIX_EQUAL_DOUBLE(MatrixA, MatrixB)                    \
  INTERNAL_EIGEN_CHECKS_MAKE_GLOG_CHECK(                                     \
      eigen_checks::internal::MatricesNear(                                  \
        MatrixA, #MatrixA, MatrixB, #MatrixB,                                \
        static_cast<typename std::remove_reference<                          \
        decltype(MatrixA)>::type::Scalar>(                                   \
      eigen_checks::internal::kDefaultPrecision),                            \
      "Floating point precision"))

#define CHECK_EIGEN_MATRIX_NEAR(MatrixA, MatrixB, Precision)                 \
  INTERNAL_EIGEN_CHECKS_MAKE_GLOG_CHECK(                                     \
      eigen_checks::internal::MatricesNear(                                  \
        MatrixA, #MatrixA, MatrixB, #MatrixB, Precision, #Precision))

#endif  // EIGEN_CHECKS_GLOG_H_
