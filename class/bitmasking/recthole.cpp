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

int N, B;
int main() {
    cin >> N >> B;
    vector<int> acorns(N,0);
    for(int i=0; i<N; i++) {
        cin >> acorns[i];
    }

    int res = 1e6;

    for(int i=1; i<(1<<N); i++) {
        int sum = 0;
        for(int j=0; j<N; j++) {
            if((i & (1 << j)) > 0) {
                sum += acorns[j];
                if(sum-B >= res) break;
            }
        }

        if(sum >= B) {
            res = min(res, sum-B);
        }
    }

    cout << res;
}