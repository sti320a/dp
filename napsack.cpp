#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

const int n=6, W=8;
const int w[n] = {2,1,3,2,1,5}, v[n]={3,2,6,1,3,85};

int rec(int i, int cap) {
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
    return res;
}

int main() {
    cout << rec(0, W) << endl;
}
