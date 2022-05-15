// Define a simple string library
//
// This templated string library includes a few useful functions for manipulating any string type.
// All functions are inlined, and return a modified copy of the input string.

#include <algorithm>
#include <string>

// #####################################################################################################################

namespace string_library {

// Type Aliases ####################################################################################

//TODO: look up basic_string and related types used here
template <class CharT>
using tstring = std::basic_string<CharT, std::char_traits<CharT>, std::allocator<CharT>>;

template <class CharT>
using tstringstream = std::basic_stringstream<CharT, std::char_traits<CharT>, std::allocator<CharT>>;

// Library #########################################################################################

template <class CharT>
tstring<CharT> to_upper(tstring<CharT> text);

template <class CharT>
tstring<CharT> to_lower(tstring<CharT> text);

template <class CharT>
tstring<CharT> reverse(tstring<CharT> text);

template <class CharT>
tstring<CharT> trim(tstring<CharT> const& text);

template <class CharT>
tstring<CharT> trim(tstring<CharT> const& text, tstring<CharT> const& chars);

template <class CharT>
tstring<CharT> trim_left(tstring<CharT> const& text);

template <class CharT>
tstring<CharT> trim_left(tstring<CharT> const& text, tstring<CharT> const& chars);

template <class CharT>
tstring<CharT> trim_right(tstring<CharT> const& text);

template <class CharT>
tstring<CharT> trim_right(tstring<CharT> const& text, tstring<CharT> const& chars);

template <class CharT>
tstring<CharT> remove(tstring<CharT> text, CharT const ch);

template <class CharT>
tstring<CharT> split(tstring<CharT> text, CharT const delimiter);

// Implementation ###################################################################################

// inline functions must be defined in the header file to actually be inlined

template <class CharT>
inline
tstring<CharT> to_upper(tstring<CharT> text) {
    std::transform(std::begin(text), std::end(text), std::begin(text), toupper);
    return text;
}

template <class CharT>
inline
tstring<CharT> to_lower(tstring<CharT> text) {
    std::transform(std::begin(text), std::end(text), std::begin(text), tolower);
    return text;
}

template <class CharT>
inline
tstring<CharT> reverse(tstring<CharT> text) {
    std::reverse(std::begin(text), std::end(text));
    return text;
}

template <class CharT>
inline
tstring<CharT> trim(tstring<CharT> const& text) {
    auto first{ text.find_first_not_of(' ') };
    auto last{ text.find_last_not_of(' ') };
    return text.substr(first, last - first + 1);
}

template <class CharT>
inline
tstring<CharT> trim(tstring<CharT> const& text, tstring<CharT> const& chars) {
    auto first{ text.find_first_not_of(chars) };
    auto last{ text.find_last_not_of(chars) };
    return text.substr(first, last - first + 1);
}

template <class CharT>
inline
tstring<CharT> trim_left(tstring<CharT> const& text) {
    auto first{ text.find_first_not_of(' ') };
    return text.substr(first, text.size() - first);
}

template <class CharT>
inline
tstring<CharT> trim_left(tstring<CharT> const& text, tstring<CharT> const& chars) {
    auto first{ text.find_first_not_of(chars) };
    return text.substr(first, text.size() - first);
}

template <class CharT>
inline
tstring<CharT> trim_right(tstring<CharT> const& text) {
    auto last{ text.find_last_not_of(' ') };
    return text.substr(0, last + 1);
}

template <class CharT>
inline
tstring<CharT> trim_right(tstring<CharT> const& text, tstring<CharT> const& chars) {
    auto last{ text.find_last_not_of(chars) };
    return text.substr(0, last + 1);
}

template <class CharT>
inline
tstring<CharT> remove(tstring<CharT> text, CharT const ch) {
    auto start = std::remove_if(
        std::begin(text),
        std::end(text),
        [=](CharT const c) {return c == ch;}
    );
    text.erase(start, std::end(text));
    return text;
}

template <class CharT>
inline
std::vector<tstring<CharT>> split(tstring<CharT> text, CharT const delimiter) {
    auto stream = tstringstream<CharT>{ text };
    auto tokens = std::vector<tstring<CharT>>{};
    auto token = tstring<CharT>{};
    while (std::getline(stream, token, delimiter)) {
        if (!token.empty()) tokens.push_back(token);
    }
    return tokens;
}

}
