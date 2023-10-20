//
// (C) 2022-2023, E. Wes Bethel
// benchmark-* harness for running different versions of the sum study
//    over different problem sizes
//
// usage: no command line arguments
// set problem sizes, block sizes in the code below

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>

#include "sum_direct.cpp"
//#include "sum_vector.cpp"
//#include "sum_indirect.cpp"

extern void setup(int64_t N, uint64_t A[]);
extern int64_t sum(int64_t N, uint64_t A[]);

/* The benchmarking program */
int main(int argc, char** argv)
{
    std::cout << std::fixed << std::setprecision(10);

#define MAX_PROBLEM_SIZE 1 << 28  //  256M
    std::vector<int64_t> problem_sizes{ MAX_PROBLEM_SIZE >> 5, MAX_PROBLEM_SIZE >> 4, MAX_PROBLEM_SIZE >> 3, MAX_PROBLEM_SIZE >> 2, MAX_PROBLEM_SIZE >> 1, MAX_PROBLEM_SIZE};

    std::vector<uint64_t> A(MAX_PROBLEM_SIZE);

    int64_t t;
    int n_problems = problem_sizes.size();


    const double million = 1000000;
    const double bytesAccessed = 8;
    const double billion = 1000000000;

    /* For each test size */
    for (int64_t n : problem_sizes)
    {
        printf("Working on problem size N=%lld \n", n);

        // invoke user code to set up the problem
        setup(n, &A[0]);
        // insert your timer code here



        // invoke method to perform the sum
        std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
        t = sum(n, &A[0]);
        std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
        //  std::cout << "The sum is: " << t << std::endl;
        std::chrono::duration<double> elapsedTime = end - start;

        std::cout << "Time elapsed: " << elapsedTime.count() << std::endl;


        std::cout << "The MFLOP/s is: " << ((n / million) / elapsedTime.count()) << std::endl;


      
        std::cout << "% Membory bandwith utilized : " << ((((n * 8) / billion) / elapsedTime.count()) / 204.8) << std::endl;

        if (A[0] == 0)
        {
            std::cout << "no memory had been accessed." << std::endl;
        }
        else
        {
            std::cout << "Memory latency is: " << elapsedTime.count() / n  << std::endl;
        }

        // insert your end timer code here, and print out elapsed time for this problem size


        printf(" Sum result = %lld \n", t);
        printf("\n");
    } // end loop over problem sizes
}

// EOF
