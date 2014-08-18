#ifndef EIGEN_CHECKS_INTERNAL_GTEST_H_
#define EIGEN_CHECKS_INTERNAL_GTEST_H_

#include <Eigen/Dense>
#include <gtest/gtest.h>

namespace eigen_checks {
namespace internal {
constexpr double kDefaultPrecision = 1e-8;

template<typename LHSMatrix, typename RHSMatrix>
::testing::AssertionResult MatricesNear(
    const Eigen::MatrixBase<LHSMatrix>& lhs,
    const std::string& name_lhs,
    const Eigen::MatrixBase<RHSMatrix>& rhs,
    const std::string& name_rhs,
    typename Eigen::MatrixBase<LHSMatrix>::Scalar tolerance) {
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

  if (lhs.isApprox(rhs, tolerance)) {
    return ::testing::AssertionSuccess();
  } else {
    ::testing::AssertionResult failure_reason(false);
    for (int i = 0; i < lhs.rows(); ++i) {
      for (int j = 0; j < lhs.cols(); ++j) {
        const double& lij = lhs(i, j);
        const double& rij = rhs(i, j);
        if (!std::isfinite(lij) ||
            !std::isfinite(rij) ||
            !Eigen::internal::isApprox(lij, rij, tolerance)) {
          if (lhs.rows() == 1) {
            failure_reason <<
                "\nMismatch at position " << j << ": " << lij << " != " << lij;
          } else if (lhs.cols() == 1) {
            failure_reason <<
                "\nMismatch at position " << i << ": " << lij << " != " << rij;
          } else {
            failure_reason << "\nMismatch at "
                << i << "," << j << ": " << lij << " != " << rij;
          }
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
