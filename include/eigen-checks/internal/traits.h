#ifndef EIGEN_CHECKS_INTERNAL_TRAITS_H_
#define EIGEN_CHECKS_INTERNAL_TRAITS_H_

namespace eigen_checks {
namespace internal {
template<typename T>
struct RemoveCR {
  typedef T type;
};

template<typename T>
struct RemoveCR<T&> {
  typedef T type;
};

template<typename T>
struct RemoveCR<const T> {
  typedef T type;
};

template<typename T>
struct RemoveCR<const T&> {
  typedef T type;
};
}  // namespace internal
}  // namespace eigen_checks
#endif  // EIGEN_CHECKS_INTERNAL_TRAITS_H_
