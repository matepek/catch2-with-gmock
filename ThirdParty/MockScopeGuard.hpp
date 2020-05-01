// https://github.com/matepek/catch2-with-gmock

#include "gmock/gmock.h"

///

class VerifyAndClearMockExpectationsScopeGuard {
  void* _mock_ptr;

 public:
  template <class MockT>
  VerifyAndClearMockExpectationsScopeGuard(MockT& mock) : _mock_ptr(&mock) {}

  ~VerifyAndClearMockExpectationsScopeGuard() {
    ::testing::Mock::VerifyAndClearExpectations(_mock_ptr);
  }
};

///

template <class... Args>
std::vector<VerifyAndClearMockExpectationsScopeGuard> MockScopeGuard(
    Args&... args) {
  return std::vector<VerifyAndClearMockExpectationsScopeGuard>({args...});
}
