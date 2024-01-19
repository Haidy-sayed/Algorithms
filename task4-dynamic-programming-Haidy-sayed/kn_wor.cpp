#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int Knap_sack_wr(int W, int l, vector<int> values, vector<int> weights)
{
	int i, w;
	vector<vector<int>> K(l + 1, vector<int>(W + 1));

	// Build table K[][] in bottom up manner
	for (i = 0; i <= l; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (weights[i - 1] <= w)
				K[i][w] = max(values[i - 1] +
					K[i - 1][w - weights[i - 1]],
					K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[l][W];



}
int main()
{
	int n, W;
	std::cin >> n >> W;
	vector<int> val_vector;
	vector<int> weight_vector;
	int temp;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		val_vector.push_back(temp);
	}
	for (int j = 0; j < n; j++) {
		std::cin >> temp;
		weight_vector.push_back(temp);
	}
	std::cout << Knap_sack_wr(W, n, val_vector, weight_vector);
	return 0;
}