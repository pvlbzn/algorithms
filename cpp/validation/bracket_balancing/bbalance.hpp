#ifndef BBALANCE_H
#define BBALANCE_H

#include <string>

class Balancer {
public:
    static bool validate(std::string const& seq);
    static bool rec_validate(std::string const& seq);
};

#endif
