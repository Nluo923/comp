#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
#define ll long long
#define mod 1000000007

int N, K;
int main() {
    cin >> N >> K;
    vector<int> b(N), o(N);
    for(int i=0; i<K; i++) {
        int l, r;
        cin >> l >> r;
        b[l-1]++;
        b[r]--;
    }

    o[0] = b[0];
    for(int i=1; i<N; i++) {
        o[i] = o[i-1] + b[i];
    }

    sort(o.begin(), o.end());

    cout << o[N/2];
}