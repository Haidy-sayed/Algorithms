#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "naive_inversion.hpp"
#include "dandq_inversion.hpp"

#define ARRAY_SIZE 1e6
using namespace std;

/**
 * generate a 1d-vector with size = variable size
 *
 * @return
 * a 1d vector with size 128*128 contains random numbers
 *
 */
vector<int> generate_random_vector()
{

    vector<int> randVec;

    for (int i =0; i < ARRAY_SIZE; i++){
            int b = rand() ;
            randVec.push_back(b);
            cout << randVec[i] << endl;
        }
    return randVec;
}

/**
 * driving stress test for both algorithms
 *
 * generate a 1d-vector with fixed size 128*128
 * compare their output and runnig time
*/
int naive_counting_inversions(vector<int> a);
int dandq_counting_inversions(vector<int> a);
int main(int argc, char **argv)
{
	vector<int> a= generate_random_vector();

    while (true)
    {
        vector<int> a = generate_random_vector();
        int naive_result, dandq_result;

        auto naive_start = std::chrono::high_resolution_clock::now();
        naive_result = naive_counting_inversions(a);
        auto naive_finish = std::chrono::high_resolution_clock::now();

        auto dandq_start = std::chrono::high_resolution_clock::now();
        dandq_result = dandq_counting_inversions(a);
        auto dandq_finish = std::chrono::high_resolution_clock::now();

        auto naive_time = (naive_finish - naive_start).count();
        auto dandq_time = (dandq_finish - dandq_start).count();

        if (dandq_result == naive_result)
        {
            cout << "equivalent ";
            cout << "naive_time ==> " << naive_time;
            cout << "dandq_time ==> " << dandq_time;
            cout << "performance enhancment ==> " << float(naive_time) / dandq_time << endl;
        }
        else
        {
            cout << "error, check your inputs and algortihms " << endl;
            // you may want to store your variables in a file to re-run the test on the same inputs;
            break;
        }
    }
    return 0;
}
