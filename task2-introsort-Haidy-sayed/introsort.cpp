#include <bits/stdc++.h>
using namespace std;


// Function to perform heapsort on the given range of elements
void heapsort(vector<int>::iterator begin, vector<int>::iterator end)
{
    make_heap(begin, end);
    sort_heap(begin, end);
}

int main(){
	for(int i=0; i<10; i++){
		print(i)
	}
return 0;
}

/**
 * implement introsort algorithm
 * 
 * @param
 *  a --> int array to be sorted
 *  begin --> iterator points to the lower index
 *  end --> iterator points to the maximum index
 *  max_depth --> number of maximum recursion depth before changing to heapsort
 * 
 * @return
 * 
*/
void introsort(vector<int> a, vector<int>::iterator begin, vector<int>::iterator end, int max_depth){
    
}
