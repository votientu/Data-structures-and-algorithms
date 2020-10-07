#include <cstdlib>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

long long maxPairwiseProduct(const vector<int>& numbers)
{
	long long maxProduct = 0;
	int size = numbers.size();
	for (int i = 0; i < size; i++)
		for(int j = i+1; j < size; j++)
			if (static_cast<long long>(numbers[i]) * numbers[j] > maxProduct)
				maxProduct = static_cast<long long>(numbers[i]) * numbers[j];
	return maxProduct;
}

long long maxPairwiseProductFast(const vector<int>& numbers)
{
	int max = 0;
	int secondMax = 0;

	int size = numbers.size();

	for (int i = 0; i < size; i++)
		if (numbers[i] > secondMax)
			if (numbers[i] >= max) {
				secondMax = max;
				max = numbers[i];
			}
			else 
				secondMax = numbers[i];

	return static_cast<long long>(max) * secondMax;
}

int main() {
	/*
	int n = 0;
	cin >> n;
	
	vector<int> numbers(n);
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	*/

	// Stress test
	while (true) {
		int n = rand() % 4 + 2;
		cout << n << endl;

		vector<int> a;
		for (int i = 0; i < n; ++i) {
			a.push_back(rand() % 10);
			cout << a[i] << ' ';
		}
		cout << endl;

		long long res1 = maxPairwiseProduct(a);
		long long res2 = maxPairwiseProductFast(a);
		if (res1 != res2) {
			cout << "Wrong answer: " << res1 << ' ' << res2 << endl;
			break;
		}
		else 
			cout << "OK" << endl;
	}

	return 0;
}