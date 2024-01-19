//============================================================================
// Name        : Lis.cpp
// Author      : Haidy Sayed Hassan
// Version     :
// Copyright   : Your copyright notice
// Description : Longest Increasing suborder, 2options provided, either take the iputs from the user, or via a random vector generation
//============================================================================

#include<iostream>
#include<vector>
using namespace std;

//Function for random vector generation with a certain length given as a parameter
vector<int> randVecGen(int length){
	vector<int> vect;
	//random generation
	for(int i=0; i<length;i++){
		vect.push_back(rand()%9);
	}
	return vect;
}

//Function for vector Display given the vector to be dispalyed and its length as parameters
void vecDisplay(vector<int> vectDis, int n){
	for(int j=0;j<n;j++){
			std::cout<<vectDis[j]<<" ";
		}
}
//Function for countung the longest increasing suborder taking the vector as a parameter and returning an integer
vector<int> longestIncSeq(vector<int>arr, int n){
	vector<int> lis;
	//std::fill_n(lis,n,1);
	for(int i=0;i<n;i++){
		lis.push_back(1);
	}

	for(int iter1=1;iter1<n;iter1++){
		int maxCount=0;
		for(int iter2=iter1-1;iter2>=0; iter2--){
			if(arr[iter2]<arr[iter1]){
				maxCount=max(maxCount, lis[iter2]);
			}
		}
		lis[iter1]=maxCount+1;
	}
	return lis;

}

int findMax(vector<int>arr, int n){
	int max=0;
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}

int main(){
	//Taking the length of the array
	int n;
	int k;
	std::cin>>n;
	vector<int> arr;
	for(int i=0; i<n;i++){
		cin>>k;
		arr.push_back(k);
	}
	//vector<int> testVect= randVecGen(n);
	std::cout<<"Original Vector "<<endl;
	vecDisplay(arr,n);
	std::cout<<endl;
	arr=longestIncSeq(arr,n);
	std::cout<<"List of increasing orders"<<endl;
	vecDisplay(arr,n);
	std::cout<<endl;
	int LongIncSub=findMax(arr,n);
	std::cout<<"Longest Increasing subsequence is: "<<LongIncSub<<endl;

	return 0;

}

