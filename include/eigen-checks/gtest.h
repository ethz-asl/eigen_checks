#ifndef EIGEN_CHECKS_GTEST_H_
#define EIGEN_CHECKS_GTEST_H_
#include <eigen-checks/internal/gtest-equal.h>

#define EIGEN_MATRIX_EQUAL(MatrixA, MatrixB) \
  eigen_checks::internal::matricesNear(MatrixA, #MatrixA, MatrixB, #MatrixB,\
      static_cast<decltype(MatrixA)::Scalar>(0.0));

#define EIGEN_MATRIX_EQUAL_DOUBLE(MatrixA, MatrixB) \
  eigen_checks::internal::matricesNear(MatrixA, #MatrixA, MatrixB, #MatrixB, \
      eigen_checks::internal::kDefaultPrecision);

#define EIGEN_MATRIX_NEAR(MatrixA, MatrixB, Precision) \
  eigen_checks::internal::matricesNear(MatrixA, #MatrixA, MatrixB, #MatrixB, \
                                       Precision);

#endif  // EIGEN_CHECKS_GTEST_H_
