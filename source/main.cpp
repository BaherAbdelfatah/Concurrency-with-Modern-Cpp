#include <iostream>
#include <thread>
#include <functional>

int main() {
    std::string s{"C++11"};

    std::thread t1{[=]{ std::cout << s << std::endl; }};
    t1.join();

    std::thread t2{[&]{ std::cout << s << std::endl; }};
    t2.detach();
}

class Account{};

void transferMoney(int amount, Account& from, Account& to) {}


void func() {
    Account account1, account2;
    std::thread thr1(transferMoney, 50, std::ref(account1), std::ref(account2));
    thr1.detach();
}