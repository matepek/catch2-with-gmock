# https://github.com/matepek/catch2-with-gmock

cmake_minimum_required(VERSION 3.12)

project(NBSChorusConnect
        VERSION 0.0.1.0
        DESCRIPTION "Catch2 with GMock"
        HOMEPAGE_URL "https://github.com/matepek/catch2-with-gmock"
        LANGUAGES CXX)

#

include("ThirdParty/GoogleTest.cmake")
include("ThirdParty/Catch2Test.cmake")

#

add_executable(catch2example.test "catch2example.test.cpp")
target_link_libraries(catch2example.test PRIVATE ThirdParty.Catch2 ThirdParty.GoogleMock)
