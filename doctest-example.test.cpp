// https://github.com/matepek/catch2-with-gmock

// NOTE that next line includes gmock and catch2 headers automatically.
#include "ThirdParty/Catch2TestWithMainAndGMock.hpp"

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

  SECTION("success") {
    auto mockGuard = MockVerifyAndClearExpectationsGuard(mock1, mock2);

    EXPECT_CALL(mock1, Bar).WillOnce(::testing::Return(true));

    REQUIRE(true == foo1.Bar());
  }

  SECTION("failure #1") {
    auto mockGuard = MockVerifyAndClearExpectationsGuard(mock1, mock2);

    EXPECT_CALL(mock1, Bar).WillOnce(::testing::Return(true));
  }

  SECTION("failure #2") {
    auto mockGuard = MockVerifyAndClearExpectationsGuard(mock1, mock2);

    EXPECT_CALL(mock2, Bar).WillOnce(::testing::Return(true));
  }
}