#include <iostream>
#include <vector>
using namespace std;

/**
 * implement the naive solution to counting inversions problem
 *
 * @param
 *  a --> 1d array
 *
 * @return
 * the number of inversions in the array
*/
/* The naive counting inversion function,
 * using naiveCounter for counting the number of inversions inside the vector
 * using countI for interating on each elemnt inside the vector
 * using countJ for iterating on other elements for comparison
 */
int naive_counting_inversions(vector<int> a){
	int naiveCounter=0;
		for (int countI=0; countI< a.size() ;countI++){
			for (int countJ=countI+1;countJ< a.size();countJ++){
				if(a[countI]> a[countJ]){
					naiveCounter++;
				}
			}
		}
		return naiveCounter;

}
