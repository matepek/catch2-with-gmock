# https://github.com/matepek/catch2-with-gmock

cmake_minimum_required(VERSION 3.12)

project(Catch2WithGMock
        VERSION 0.0.1.1
        DESCRIPTION "Catch2 with GMock"
        HOMEPAGE_URL "https://github.com/matepek/catch2-with-gmock"
        LANGUAGES CXX)

############
# For Catch2

include("ThirdParty/GoogleTest.cmake")
include("ThirdParty/Catch2Test.cmake")

add_executable(catch2-example.test "catch2-example.test.cpp")
target_link_libraries(catch2-example.test PRIVATE ThirdParty.Catch2 ThirdParty.GoogleMock)

#########
# DOCTest

include("ThirdParty/DOCTest.cmake")

add_executable(doctest-example.test "doctest-example.test.cpp")
target_link_libraries(doctest-example.test PRIVATE ThirdParty.Catch2 ThirdParty.GoogleMock)
