#include <iostream>

class RLE
{
private:
    std::string data;
public:
    RLE(std::string);

    static RLE encode(std::string s);
    std::string const &get_data();
};
