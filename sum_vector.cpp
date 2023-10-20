#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>



void
setup(int64_t N, uint64_t A[])
{
	printf(" inside sum_vector problem_setup, N=%lld \n", N);
	int64_t sum = 0;
	for (int i = 0; i < N; i++)
	{
		A[i] = (static_cast<uint64_t>(rand() % 9)) + 1;
		//  std::cout << *(A + i) << std::endl;

	}
	printf("Done, with setting up.");
}

int64_t
sum(int64_t N, uint64_t A[])
{
	printf(" inside sum_vector perform_sum, N=%lld \n", N);

	int64_t sum = 0;

	//std::cout << A << std::endl;

	//int64_t* vector = (int64_t *)A;


	for (int i = 0; i < N; i++) {
		sum += A[i];
		// std::cout << sum << std::endl;
	}

	std::cout << " inside direct sum: " << sum << std::endl;

	return sum;
}

