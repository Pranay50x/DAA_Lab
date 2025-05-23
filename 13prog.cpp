#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> val = {10, 20, 50, 60},
                wt  = { 2,  3,  4,  5};
    int W = 8, n = val.size();

    // DP table: dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; ++i)
        for (int w = 1; w <= W; ++w)
            dp[i][w] = (wt[i-1] <= w)
                ? max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w])
                : dp[i-1][w];

    int res = dp[n][W], w = W, totalW = 0;
    cout << "Maximum value that can be stolen: " << res << "\n"
         << "Items selected (weight, value):\n";

    // Trace back to find which items were included
    for (int i = n; i > 0 && res > 0; --i) {
        if (res != dp[i-1][w]) {
            cout << "  Item " << i
                 << ": (Weight=" << wt[i-1]
                 << ", Value="  << val[i-1] << ")\n";
            totalW += wt[i-1];
            res   -= val[i-1];
            w     -= wt[i-1];
        }
    }
    cout << "Total weight: " << totalW << "\n";
    return 0;
}
