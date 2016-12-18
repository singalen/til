#include <vector>
#include <string>
#include <math.h>
#include <iostream>
#include <set>

using std::string;

#include "plf_colony.h"


typedef void function_t(int iterations);

long benchmark(function_t f, int iterations) {
	long            ms; // Milliseconds
	time_t          s;  // Seconds
	struct timespec spec;
	
	clock_gettime(CLOCK_REALTIME, &spec);
	
	s  = spec.tv_sec;
	ms = lround(spec.tv_nsec / 1.0e6);
	
	f(iterations);
	
	clock_gettime(CLOCK_REALTIME, &spec);
	return lround(spec.tv_nsec / 1.0e6) - ms;
}

void benchmark_print(function_t f, int iterations, string title) {
	long ms = benchmark(f, iterations);
	std::cout << title << ' ' << iterations << " times took " << ms << " ms\n";
}

std::multiset<int> subject_multiset;
plf::colony<int> subject_colony;

void multiset_int_insertion(int iterations) {
	for (int i=0; i<iterations; i++) {
		int item = random() % INT_MAX;
		subject_multiset.insert(item);
	}
}

void colony_int_insertion(int iterations) {
	for (int i=0; i<iterations; i++) {
		int item = random() % INT_MAX;
		subject_colony.insert(item);
	}
}

void multiset_int_removal(int iterations) {
	for (int i=0; i<iterations; i++) {
		int item = random() % INT_MAX;
		subject_multiset.erase(subject_multiset.begin());
	}
}

void colony_int_removal(int iterations) {
	for (int i=0; i<iterations; i++) {
		int item = random() % INT_MAX;
		subject_colony.erase(subject_colony.begin());
	}
}

int main(int argc, char* argv[]) {
	benchmark_print(multiset_int_insertion, 100000, "multiset insertion");
	benchmark_print(colony_int_insertion, 100000, "colony insertion");
	benchmark_print(multiset_int_removal, 100000, "multiset removal");
	benchmark_print(colony_int_removal, 100000, "colony removal");
	
	return 0;
}
