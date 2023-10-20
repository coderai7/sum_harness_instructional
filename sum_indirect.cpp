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
	printf(" inside sum_indirect problem_setup, N=%lld \n", N);
	int64_t sum = 0;
	for (int i = 0; i < N; i++)
	{
		A[i] = (static_cast<uint64_t>(rand() % 9)) + 1;
		//  std::cout << *(A + i) << std::endl;

	}
	printf("Done, with setting up.");;
}

int64_t
sum(int64_t N, uint64_t A[])
{
	printf(" inside sum_indirect perform_sum, N=%lld \n", N);

	//  int64_t* indirect = (int64_t*)A;
	int64_t sum = 0;

	int64_t index = A[0];

	/*
	int index = *(indirect + 0);


	for (int i = 0; i < N; i++)
	{
		sum += *(A + index);
		index = *(A + index);

	}
	*/

	for (int i = 0; i < N; i++)
	{
		sum += A[index];
		index = A[index];

	}

	return sum;
}

