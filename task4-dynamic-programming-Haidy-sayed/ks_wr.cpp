#include<iostream>
#include<vector>
using namespace std;

// Returns the maximum value with knapsack of
// W is the max weight of the knapsack, n is the number of inputs per line, vector val for the values for each weight, vector wt for weights
int KnapSackRep(int W, int n, vector<int> val, vector<int> wt)
{
    // maxValStor a vector to hold the maximum value for each weight and its corresponding value
    vector<int> maxValStor;
    for(int i=0;i<W+1;i++){
    	//filling the vector with zeros
    	maxValStor.push_back(0);
    }

  //finding the max possible value to be stored from each weight and returning the maximum one
    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
        	 maxValStor[i] = max(maxValStor[i], maxValStor[i-wt[j]] + val[j]);

    return maxValStor[W];
}
// a function to read the vectors for values and weights to minimize the code lines inside the main
vector<int> read(int n){
	vector<int> vect;
	int temp;
	for (int i=0;i<n;i++){
		std::cin>>temp;
		vect.push_back(temp);
	}
	return vect;
}

// Driver program
int main()
{
   int n,W;
   std::cin>>n>>W;
   vector<int> vals=read(n);
   vector<int> weight=read(n);
   std::cout<<KnapSackRep(W,n,vals,weight);
    return 0;
}
