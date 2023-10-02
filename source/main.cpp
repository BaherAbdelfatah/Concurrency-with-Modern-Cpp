#include <iostream>
#include <thread>
#include <functional>
#include <future>

int main() {
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    std::cout << std::boolalpha << "future state: " << fut.valid() << std::endl;
    prom.set_value(1);
    std::cout << std::boolalpha << "future state: " << fut.valid() << std::endl;
    fut.get();
    std::cout << std::boolalpha << "future state: " << fut.valid() << std::endl;
    return 0;
}