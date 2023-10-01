// conditionVariable.cpp

#include <condition_variable>
#include <iostream>
#include <thread>
#include <vector>

std::vector<int> mySharedWork;
std::mutex mutex_;
std::condition_variable condVar;
bool dataReady{false};

void waitingForWork() {
    std::cout << "Waiting " << std::endl;
    std::unique_lock<std::mutex> lock{mutex_};
    condVar.wait(lock, []{ return dataReady; });
    mySharedWork[1] = 2;
    std::cout << "Work done " << std::endl; 
}

void setDataReady() {
    mySharedWork = {1, 0, 3};
    {
        std::lock_guard<std::mutex> lock{mutex_};
        dataReady = true;
    }
    std::cout << "Data prepared" << std::endl;
    condVar.notify_one();
}

int main() {
    std::cout << std::endl;

    std::thread t1{waitingForWork};
    std::thread t2{setDataReady};

    t1.join();
    t2.join();

    for (auto e : mySharedWork) {
        std::cout << e << " ";
    }

    std::cout << "\n\n";
}