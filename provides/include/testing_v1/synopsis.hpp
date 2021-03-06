#pragma once

#include "testing_v1/private.hpp"

// test.hpp ====================================================================

/// A minimalist test framework.
namespace testing_v1 {

/// Holds a registered test action and should only be used at namespace scope.
template <class Action> struct test_t : Private::test_t<Action> {
  /// Constructs a test from the given action.
  template <class ForwardableAction> test_t(ForwardableAction &&action);

  /// Tests are not CopyConstructible.
  test_t(const test_t &) = delete;

  /// Tests are not CopyAssignable.
  test_t &operator=(const test_t &) = delete;
};

/// Creates and registers a test action and should only be used at namespace
/// scope.
template <class Action> test_t<std::decay_t<Action>> test(Action &&action);

/// Prints `FAIL` and `exit(1)`s the program if the result is false.
void verify(bool result);

} // namespace testing_v1

/// Runs all registered test actions.  Usually there should only be a single
/// test action per test program.
int main();
