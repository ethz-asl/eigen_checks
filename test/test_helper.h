#ifndef EIGEN_CHECKS_TEST_HELPER_H_
#define EIGEN_CHECKS_TEST_HELPER_H_
#include <limits>
#include <random>

#include <Eigen/Dense>
#include <gtest/gtest.h>
#include <glog/logging.h>

#include <eigen-checks/internal/gtest-equal.h>

template <typename Scalar>
class EigenChecks : public testing::Test {
 protected:
  virtual void SetUp() {
    int random_seed_ = 42;
    std::mt19937 gen(random_seed_);
    std::normal_distribution<> dis(10.0, 5.0);
    Eigen::Matrix<Scalar, 5, 1> perturbance_v;
    perturbance_v << dis(gen), dis(gen), dis(gen), dis(gen), dis(gen);
    perturbance_v /= perturbance_v.maxCoeff();

    ground_truth_vector_5 << dis(gen), dis(gen), dis(gen), dis(gen), dis(gen);

    test_vector_D.resize(4, Eigen::NoChange);
    test_vector_D.template block<4, 1>(0, 0) =
        ground_truth_vector_5.template block<4, 1>(0, 0);

    test_vector_5_random << dis(gen), dis(gen), dis(gen), dis(gen), dis(gen);

    test_vector_5_near_e_minus_5 = ground_truth_vector_5;
    test_vector_5_near_e_minus_5 +=
        perturbance_v * static_cast<Scalar>(1e-5);

    test_vector_5_equal = ground_truth_vector_5;

    test_vector_5_equal_floating_point = ground_truth_vector_5;
    test_vector_5_equal_floating_point +=
        perturbance_v * static_cast<Scalar>(0.9 *
            eigen_checks::internal::kDefaultPrecision);

    // Test matrix.
    Eigen::Matrix<Scalar, 5, 4> perturbance_m;
    perturbance_m <<
        dis(gen), dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen), dis(gen);
    perturbance_m /= perturbance_m.maxCoeff();

    ground_truth_matrix_54 <<
        dis(gen), dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen), dis(gen);

    test_matrix_D4.resize(4, Eigen::NoChange);
    test_matrix_D4.template block<4, 4>(0, 0) =
        ground_truth_matrix_54.template block<4, 4>(0, 0);

    test_matrix_54_random <<
        dis(gen), dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen), dis(gen);

    test_matrix_54_near_e_minus_5 = ground_truth_matrix_54;
    test_matrix_54_near_e_minus_5 +=
        perturbance_m * static_cast<Scalar>(1e-5);

    test_matrix_54_equal = ground_truth_matrix_54;

    test_matrix_54_equal_floating_point = ground_truth_matrix_54;
    test_matrix_54_equal_floating_point +=
        perturbance_m * static_cast<Scalar>(0.9 *
            eigen_checks::internal::kDefaultPrecision);
  }

 protected:
  Eigen::Matrix<Scalar, 5, 1> ground_truth_vector_5;
  Eigen::Matrix<Scalar, Eigen::Dynamic, 1> test_vector_D;
  Eigen::Matrix<Scalar, 5, 1> test_vector_5_random;
  Eigen::Matrix<Scalar, 5, 1> test_vector_5_near_e_minus_5;
  Eigen::Matrix<Scalar, 5, 1> test_vector_5_equal;
  Eigen::Matrix<Scalar, 5, 1> test_vector_5_equal_floating_point;
  Eigen::Matrix<Scalar, 5, 4> ground_truth_matrix_54;
  Eigen::Matrix<Scalar, Eigen::Dynamic, 4> test_matrix_D4;
  Eigen::Matrix<Scalar, 5, 4> test_matrix_54_random;
  Eigen::Matrix<Scalar, 5, 4> test_matrix_54_near_e_minus_5;
  Eigen::Matrix<Scalar, 5, 4> test_matrix_54_equal;
  Eigen::Matrix<Scalar, 5, 4> test_matrix_54_equal_floating_point;
};

typedef ::testing::Types<double, float> ScalarTypes;
TYPED_TEST_CASE(EigenChecks, ScalarTypes);

#define GLOG_TEST_EXPECT_DEATH_DIFFERENT_SIZE(X) \
  EXPECT_DEATH(X), "^Matrices have a different$")

#define GLOG_TEST_EXPECT_DEATH_DIFFERENT_DATA(X) \
  EXPECT_DEATH(X), "^The maximum difference$")

#endif  // EIGEN_CHECKS_TEST_HELPER_H_
