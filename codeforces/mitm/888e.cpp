#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;
#define ll long long
#define mod 1000000007

bool cmp(pair<int,bool> p1, pair<int,bool> p2) {
    return false;
}

long long N, M;
int main() {
    cin >> N >> M;
    vector<int> a(N);
    
    for(int i=0; i<N; i++) {
        cin >> a[i]; 
    }

    auto get_subset = [&](int l, int r, set<long long> &out) {
        int range = r - l + 1;

        for(int i = 0; i < (1 << range); i++) {
            long long sum = 0;

            for(int j = 0; j < range; j++) {
                if((i & (1 << j)) > 0) { sum = sum + a[l+j]; }
            }
            out.insert(sum % M);
        } 
    };

    set<long long> setLeft;
    get_subset(0, N/2 - 1, setLeft); 

    long long ans = *setLeft.rbegin();

    for(int i = 0; i < (1 << (N/2 - 1)); i++) { 
        int cur = 0;

        for(int j = 0; j < N/2 - 1; j++) {
            if((i & (1 << j)) > 0) { cur += a[N/2 + j]; }
        }

        cur %= M;

        ans = max(ans, *prev(lower_bound(setLeft.begin(), setLeft.end(), M - cur)) + cur);
    }

    cout << ans;
}