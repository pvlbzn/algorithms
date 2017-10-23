#include <string>

#include "bbalance.hpp"


// Loop based validator using a single counter.
bool Balancer::validate(std::string const& seq) {
    int counter = 0;
    
    for (auto const& ch : seq) {
        if (ch == '{')
            counter += 1;
        if (ch == '}')
            counter -= 1;
    }
    
    return counter == 0 ? true : false;
}


/**
 * Functional-like bracket balancing.
 * 
 * Class fstring safely extends, by wrapping, std::string providing
 * two new functions:
 *      - head()
 *      - tail()
*/
class fstring {
    std::string storage;
public:
    fstring(std::string const& str) : storage(str) {};

    char head() const {
        return storage[0];
    };

    std::string tail() const { 
        return storage.substr(storage.size() - (storage.size() - 1));
    };

    int length() const {
        return storage.length();
    }
};


// Reqursive function for bracket balancing using functional programming API
bool _rvalidate(fstring const& seq, int open) {
    if (seq.length() == 0)
        return open == 0;

    if (seq.head() == '{') {
        return _rvalidate(seq.tail(), open + 1);
    } else if (seq.head() == '}') {
        return open > 0 && _rvalidate(seq.tail(), open - 1);
    } else {
        return _rvalidate(seq.tail(), open);
    }

    return open;
}


// Convinience wrapper, public API
bool Balancer::rec_validate(std::string const& seq) {
    return _rvalidate(fstring(seq), 0);
}
