#include <iostream>
#include <algorithm>
using namespace std;

const int n=6, W=8;
const int w[n] = {2,1,3,2,1,5}, v[n]={3,2,6,1,3,85};

int dp[10][10];

int rec(int i, int cap) {
    if (dp[i][cap] != -1) {
        return dp[i][cap];
    }

    int res;
    if (i == n) {
        res = 0;
    } else if (cap < w[i]) {
        res = rec(i + 1, cap);
    } else {
        res = max(
            rec(i + 1, cap),
            rec(i + 1, cap - w[i]) + v[i]
        );
    }
    return dp[i][cap] = res;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cout << rec(0, W) << endl;
}
