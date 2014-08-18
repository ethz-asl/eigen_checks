#ifndef EIGEN_CHECKS_INTERNAL_GTEST_H_
#define EIGEN_CHECKS_INTERNAL_GTEST_H_

#include <Eigen/Dense>
#include <gtest/gtest.h>

namespace eigen_checks {
namespace internal {
constexpr double kDefaultPrecision = 1e-10;

template<typename LHSMatrix, typename RHSMatrix>
::testing::AssertionResult MatricesNear(
    const Eigen::MatrixBase<LHSMatrix>& lhs,
    const std::string& name_lhs,
    const Eigen::MatrixBase<RHSMatrix>& rhs,
    const std::string& name_rhs,
    typename Eigen::MatrixBase<LHSMatrix>::Scalar tolerance,
    const std::string& name_tolerance) {
  if (lhs.rows() != rhs.rows()) {
    ::testing::AssertionResult failure_reason(false);
    failure_reason << "Matrices have a different number of rows: "
        << name_lhs << " has " << lhs.rows() << " rows while " << name_rhs
        << " has " << rhs.rows() << " rows." << std::endl;
    return failure_reason;
  }
  if (lhs.cols() != rhs.cols()) {
    ::testing::AssertionResult failure_reason(false);
    failure_reason << "Matrices have a different number of cols: "
        << name_lhs << " has " << lhs.cols() << " cols while " << name_rhs
        << " cols " << rhs.cols() << " cols." << std::endl;
    return failure_reason;
  }

  typedef typename Eigen::MatrixBase<LHSMatrix>::Scalar Scalar;
  const Scalar max_diff = (lhs - rhs).cwiseAbs().maxCoeff();

  if (max_diff <= tolerance) {
    return ::testing::AssertionSuccess();
  } else {
    ::testing::AssertionResult failure_reason(false);
    failure_reason << "The max difference between " << name_lhs << " and "
        << name_rhs << " is " << max_diff << ", which exceeds "
        << tolerance << ", where\n";
    for (int i = 0; i < lhs.rows(); ++i) {
      for (int j = 0; j < lhs.cols(); ++j) {
        const Scalar& lij = lhs(i, j);
        const Scalar& rij = rhs(i, j);
        const Scalar& diff = std::abs(lij - rij);
        if (!std::isfinite(lij) ||
            !std::isfinite(rij) ||
            !diff > tolerance) {
          if (lhs.rows() == 1) {
            failure_reason <<
                "\nposition " << j << " evaluates to " << lij << " and " << lij;
          } else if (lhs.cols() == 1) {
            failure_reason <<
                "\nposition " << i << " evaluates to " << lij << " and " << rij;
          } else {
            failure_reason << "\nposition " << i << "," << j << " evaluates to "
                << lij << " and " << rij;
          }
          failure_reason << " and " << name_tolerance << " evaluates to "
              << max_diff << ".\n";
        }
      }
    }
    failure_reason << "\n";
    return failure_reason;
  }
}
}  // namespace internal
}  // namespace eigen_checks
#endif  // EIGEN_CHECKS_INTERNAL_GTEST_H_
