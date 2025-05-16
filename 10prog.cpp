#include <iostream>
#include <vector>
using namespace std;

void knapsack(const vector<int>& weight, const vector<int>& profit, int capacity) {
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], profit[i - 1] + dp[i - 1][w - weight[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum Profit: " << dp[n][capacity] << "\n";

    cout << "Selected items: ";
    for (int i = n, w = capacity; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item" << i << " ";
            w -= weight[i - 1];
        }
    }
    cout << "\n";
}

int main() {
    vector<int> weight{2, 3, 4, 1};
    vector<int> profit{3, 4, 5, 3};
    int capacity = 5;
    knapsack(weight, profit, capacity);
}
