// Produces-consumer problem.
//
// Wiki: https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem
//
// Problem describles two processes:
//      - producer
//      - consumer
// who share a common, fixed-size buffer user as a queue. The producer's
// job is to generate data and put it into the buffer. At the same time
// consumer is consuming the data removing it from the buffer.
// The problem is to make sure that the producer won't try to add data
// into the buffer if it's full and that the consumer won't try to remove
// data from an empty buffer.

#include <string>
#include <random>
#include <iostream>
#include <queue>


class Product
{
private:
    std::string data;
public:
    Product(int len);
    std::string get_data() { return data; }
};

Product::Product(int len)
{
    std::string name;

    std::random_device r;
    std::default_random_engine engine(r());
    std::uniform_int_distribution<int> distributor(65, 90);
    
    for (int i = 0; i < len; i++)
        name += char(distributor(engine));
    
    data = name;
}


class Producer
{
public:
    static Product produce(int, std::queue<Product>&);
};

Product Producer::produce(int len, std::queue<Product>& q)
{
    auto p = Product(len);
    q.push(p);
    return p;
}



class Consumer
{
    public:
    static Product consume(std::queue<Product>&);
};

Product Consumer::consume(std::queue<Product>& q)
{
    auto p = q.front();
    q.pop();
    return p;
}

// Queue copy is passed, therefore that one will only print
// elements and won't affect source data structure content.
void print_queue(std::queue<Product> q)
{
    while (!q.empty()) {
        auto p = q.front();
        std::cout << p.get_data() << std::endl;
        q.pop();
    }
}

int main()
{
    std::queue<Product> stock;

    for (int i = 0; i < 15; i++) {
        auto p = Producer::produce(6, stock);
        std::cout << "product " << p.get_data() << " has been produced" << std::endl;
    }
    
    for (int i = 0; i < 15; i++) {
        auto p = Consumer::consume(stock);
        std::cout << "product " << p.get_data() << " has been consumed" << std::endl;
    }
}
