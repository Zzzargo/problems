#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.empty()) return 0;

    // This will work like a state machine rather than a DP algorithm
    int buy1 = INT_MAX;  // Price at which the stock was bought the first time
    int sell1 = 0;  // Price at which the stock was sold the first time
    int buy2 = INT_MAX;
    int sell2 = 0;

	// In a nutshell, minimize the buy prices and maximize the sell ones, taking into account the previous price
    for (int price : prices) {
        buy1 = min(buy1, price);
        
        sell1 = max(sell1, price - buy1);

		// Use the profit made on the first attempt of getting rich
        buy2 = min(buy2, price - sell1);
        
        sell2 = max(sell2, price - buy2);
    }

    return sell2;
}

int main() {
	vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
	cout << "Max profit: " << maxProfit(prices) << endl;
}
