#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
#define ll long long
#define mod 1000000007

bool cmp(pair<int,bool> p1, pair<int,bool> p2) {
    return false;
}

int N, X;
int main() {
    cin >> N >> X;
    vector<int> a(N);
    
    for(int i=0; i<N; i++) {
        cin >> a[i]; 
    }

    auto get_subset_sums = [&](int l, int r) -> vector<long long> {
        int range = r - l + 1;
        vector<long long> out;

        for(int i = 0; i < (1 << range); i++) {
            long long s = 0;

            for(int j = 0; j < range; j++) {
                if((i & (1 << j)) > 0) { s += a[l+j]; }
            }
            out.push_back(s);
        } 

        return out;
    };

    vector<long long> setLeft = get_subset_sums(0, N/2 - 1); 
    vector<long long> setRight = get_subset_sums(N/2, N - 1);
    sort(setLeft.begin(), setLeft.end()); 
    sort(setRight.begin(), setRight.end()); 

    long long ans = 0;

    for(long long i : setLeft) {
        // find complement
        auto lb = lower_bound(setRight.begin(), setRight.end(), X - i);
        auto ub = upper_bound(setRight.begin(), setRight.end(), X - i);

        ans += (ub - setRight.begin()) - (lb - setRight.begin());
    }

    cout << ans;
}