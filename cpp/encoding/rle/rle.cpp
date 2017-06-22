#include <string>

#include "rle.hpp"


RLE::RLE(std::string d)
{
    data = d;
}


std::string const &RLE::get_data()
{
    return data;
}


RLE RLE::encode(std::string s)
{
    std::string enc;

    for (int i = 1; i < s.length(); i++) {
        char c = s[i-1];
        int counter = 1;

        while (i < s.length() and s[i] == c) {
            counter++;
            i++;
        }

        enc += std::to_string(counter);
        enc += c;
    }

    return RLE(enc);
}
