// https://github.com/matepek/catch2-with-gmock

// NOTE that next line includes gmock and doctest headers automatically.
#include "ThirdParty/DOCTestWithMainAndGMock.hpp"
#include "ThirdParty/MockScopeGuard.hpp"

using namespace std;

///

class Foo {
 public:
  virtual ~Foo() {}
  virtual bool Bar() const = 0;
};

class MockFoo : public Foo {
 public:
  MOCK_METHOD(bool, Bar, (), (const, override));
};

///

TEST_CASE("example #1") {
  ::testing::StrictMock<MockFoo> mock1, mock2;
  Foo& foo1 = mock1;

  SUBCASE("success") {
    auto mockGuard = MockScopeGuard(mock1, mock2);

    EXPECT_CALL(mock1, Bar).WillOnce(::testing::Return(true));

    REQUIRE(true == foo1.Bar());
  }

  SUBCASE("failure #1") {
    auto mockGuard = MockScopeGuard(mock1, mock2);

    EXPECT_CALL(mock1, Bar).WillOnce(::testing::Return(true));
  }

  SUBCASE("failure #2") {
    auto mockGuard = MockScopeGuard(mock1, mock2);

    EXPECT_CALL(mock2, Bar).WillOnce(::testing::Return(true));
  }
}