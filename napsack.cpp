#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

const int n=6, W=8;
const int w[n] = {2,1,3,2,1,5}, v[n]={3,2,6,1,3,85};

int rec(int i, int cap) {
    if (i == n) {
        return 0;
    } else if (cap < w[i]) {
        return rec(i + 1, cap);
    } else {
        return max(
            rec(i + 1, cap),
            rec(i + 1, cap - w[i]) + v[i]
        );
    }
}

int main() {
    // memset(dp, -1, sizeof(dp));
    cout << rec(0, W) << endl;
}
