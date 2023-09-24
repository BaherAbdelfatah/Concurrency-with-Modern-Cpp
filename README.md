# Concurrency-with-Modern-Cpp
Concurrency with Modern C++ What every professional C++ programmer should know about concurrency. 
Rainer Grimm 
This book is for sale at http://leanpub.com/concurrencywithmodernc

# Source Code
  All source code examples are complete. That means, assuming you have a conforming compiler, you
  can compile and run them. The name of the source file is in the title of the listing. I use the using
  namespace std directive in the source files only if necessary.
  # Run the Programs
    Compiling and running the examples is quite easy for the C++11 and C++14 examples in this book.
    Every modern C++ compiler should support them. For both the GCC¹ and the clang² compiler, the
    C++ standard must be specified as well as the threading library to link against. For example the g++
    compiler from GCC creates an executable program called thread with the following command-line:
    g++ -std=c++14 -pthread thread.cpp -o thread.
    • -std=c++14: use the language standard C++14
    • -pthread: add support for multithreading with the pthread library
    • thread.cpp: source file
    • -o thread: executable program
