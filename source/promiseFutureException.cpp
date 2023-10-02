// promiseFutureException.cpp

#include <exception>
#include <future>
#include <iostream>
#include <thread>
#include <utility>

struct Div
{
    void operator()(std::promise<int> &&intPromise, int a, int b)
    {
        try
        {
            if (0 == b)
            {
                std::string errMess = std::string{"Illegal division by zero: "} +
                                      std::to_string(a) + "/" + std::to_string(b);
                throw std::runtime_error(errMess);
            }
            intPromise.set_value(a / b);
        }
        catch (...)
        {
            intPromise.set_exception(std::current_exception());
        }
        // Instead of try catch block
        // intPromise.set_exception(std::make_exception_ptr(std::runtime_error(errMess)));
    }
};

void executeDivision(int num, int denum)
{
    std::promise<int> divPromise;
    std::future<int> divResult = divPromise.get_future();

    Div div;
    std::thread divThread{div, std::move(divPromise), num, denum};

    // get the result or the exception
    try
    {
        std::cout << num << "/" << denum << " = " << divResult.get() << std::endl;
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }

    divThread.join();
}

int main()
{
    std::cout << std::endl;

    executeDivision(20, 0);
    executeDivision(20, 10);

    std::cout << std::endl;
}