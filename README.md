# Catch2 with GMock

This is an example how to use [Catch2](https://github.com/catchorg/Catch2) with [GMock](https://github.com/google/googletest).

It also contains some example how to use [DOCTest](https://github.com/onqtam/doctest) with GMock.

Note: You might have to call `testing::Mock::VerifyAndClearExpectations(mockPtr)` at the end of every `SECTION`.

Start [here](./catch2-example.test.cpp).

# Remark

This is an experimental repository. It works for me, but not overly tested.
Feel free to improve it by creating issue or PR.

The integration works with VSCode [Catch2, Google Test and DOCest Explorer](https://marketplace.visualstudio.com/items?itemName=matepek.vscode-catch2-test-adapter).

There is a DOCTest [skeleton](./doctest-example.test.cpp) too.
