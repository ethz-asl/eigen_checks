#ifndef EIGEN_CHECKS_ENTRYPOINT_H_
#define EIGEN_CHECKS_ENTRYPOINT_H_

#include <gtest/gtest.h>
#include <glog/logging.h>

// Let the Eclipse parser see the macro.
#ifndef TEST
#define TEST(a, b) int Test_##a##_##b()
#endif

#ifndef TEST_F
#define TEST_F(a, b) int Test_##a##_##b()
#endif

#ifndef TEST_P
#define TEST_P(a, b) int Test_##a##_##b()
#endif

#define UNITTEST_ENTRYPOINT \
    int main(int argc, char** argv) { \
  google::InitGoogleLogging(argv[0]); \
  testing::InitGoogleTest(&argc, argv); \
  google::ParseCommandLineFlags(&argc, &argv, true); \
  ::testing::FLAGS_gtest_death_test_style = "threadsafe"; \
  return RUN_ALL_TESTS();\
}

#endif  // EIGEN_CHECKS_ENTRYPOINT_H_
