// packagedTaskReuse.cpp

#include <functional>
#include <future>
#include <iostream>
#include <utility>
#include <vector>

void calcProducts(std::packaged_task<int(int, int)>& task, const std::vector<std::pair<int, int>>& pairs) {
    for (auto& pair : pairs) {
        auto fut = task.get_future();
        task(pair.first, pair.second);
        std::cout << pair.first << " * " << pair.second << " = " << fut.get() << std::endl;
        task.reset();
    }
}

int main() {
    std::cout << std::endl;

    std::vector<std::pair<int, int>> allPairs;
    allPairs.push_back(std::make_pair(1,2));
    allPairs.push_back(std::make_pair(2,3));
    allPairs.push_back(std::make_pair(3,4));
    allPairs.push_back(std::make_pair(4,5));

    std::packaged_task<int(int, int)> task{[](int fir, int sec){
        std::cout << std::this_thread::get_id() << std::endl;
        return fir * sec;
    }};

    std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;

    calcProducts(task, allPairs);

    std::cout << std::endl;

    std::thread t(calcProducts, std::ref(task), allPairs);
    t.join();

    std::cout << std::endl;
}