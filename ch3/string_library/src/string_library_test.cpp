// Define unit tests for the string_library

#include "../../../external/catch2/catch.hpp"

#include "string_library.hpp"

// #####################################################################################################################

TEST_CASE( "Convert a string to all upper case", "[]" ) {
    std::string lt = "lower CASE text";
    auto ut{ string_library::to_upper(lt) };

    REQUIRE( ut == "LOWER CASE TEXT" );
}
