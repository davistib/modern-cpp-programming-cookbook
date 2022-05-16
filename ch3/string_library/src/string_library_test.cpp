// Define unit tests for the string_library

#include <string>

#include "../../../external/catch2/catch.hpp"

#include "string_library.hpp"

// #####################################################################################################################

using namespace std::string_literals;

TEST_CASE( "Convert a string to all upper case", "[]" ) {
    std::string lt = "lower CASE text";
    auto ut{ string_library::to_upper(lt) };

    REQUIRE( ut == "LOWER CASE TEXT" );
}

TEST_CASE( "Convert a string to all lower case", "[]" ) {
    std::string lt = "lower CASE text";
    auto ut{ string_library::to_lower(lt) };

    REQUIRE( ut == "lower case text" );
}

TEST_CASE( "Reverses a string", "[]" ) {
    std::string lt = "boobytrap";
    auto ut{ string_library::reverse(lt) };

    REQUIRE( ut == "partyboob" );
}

TEST_CASE( "Trims trailing whitespace from a string", "[]" ) {
    std::string lt = "trailing whitespace     ";
    auto ut{ string_library::trim(lt) };
    REQUIRE( ut == "trailing whitespace" );
}

TEST_CASE( "Trims leading and trailing whitespace from a string", "[]" ) {
    std::string lt = "     trailing whitespace     ";
    auto ut{ string_library::trim(lt) };
    REQUIRE( ut == "trailing whitespace" );
}

TEST_CASE( "Trims only leading whitespace from a string", "[]" ) {
    std::string lt = "     trailing whitespace     ";
    auto ut{ string_library::trim_left(lt) };
    REQUIRE( ut == "trailing whitespace     " );
}

TEST_CASE( "Trims only trailing whitespace from a string", "[]" ) {
    std::string lt = "     trailing whitespace     ";
    auto ut{ string_library::trim_right(lt) };
    REQUIRE( ut == "     trailing whitespace" );
}

TEST_CASE( "Trims leading characters from a string", "[]" ) {
    std::string lt = "## comment";
    auto ut{ string_library::trim_left(lt, "#"s) };
    REQUIRE( ut == " comment" );
}

TEST_CASE( "Trims trailing characters from a string", "[]" ) {
    std::string lt = "comment %!#*";
    auto ut{ string_library::trim_right(lt, "*!#%"s) };
    REQUIRE( ut == "comment " );
}

TEST_CASE( "Remove's all whitespace from string", "[]" ) {
    std::string lt = "w h i t e s p a c e";
    auto ut{ string_library::remove(lt, ' ') };
    REQUIRE( ut == "whitespace" );
}

TEST_CASE( "Split a string by space delimeter", "[]" ) {
    std::string lt = "a string with spaces";
    auto ut{ string_library::split(lt, ' ') };
    REQUIRE( ut.size() == 4 );
    REQUIRE( ut[1] == "string" );
}

TEST_CASE( "Split a string by comma delimeter", "[]" ) {
    std::string lt = "1,2,3,4,5";
    auto ut{ string_library::split(lt, ',') };
    REQUIRE( ut.size() == 5 );
    REQUIRE( ut[1] == "2" );
}
