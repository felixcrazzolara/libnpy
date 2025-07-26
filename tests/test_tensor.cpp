#include <catch2/catch_test_macros.hpp>

#include "npy.hpp"

#include <utility>

TEST_CASE("Test index set") {
    npy::Tensor t({1, 1}, npy::dBool);
    t.zero_();
    REQUIRE( t.at<bool>(std::pair{0,0}) == false );
    t.at<bool>(std::pair{0,0}) = true;
    REQUIRE( t.at<bool>(std::pair{0,0}) == true );
}
