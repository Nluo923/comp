#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;
#define ll long long
#define mod 1000000007

int N, I, H, R;
int main() {
    cin >> N >> I >> H >> R;
    set<pair<int,int> > s;

    vector<int> interval(N+1, 0);
    for(int i=0; i<R; i++) {
        int l, r;
        cin >> l >> r;

        pair<set<pair<int,int> >::iterator,bool> ret = s.insert({l,r});

        if(ret.second == false) continue;

        if(l < r) {
            interval[l]--;
            interval[r-1]++;
        } else {
            interval[r]--;
            interval[l-1]++;
        }
    }

    vector<int> ans(N+1, H);
    int preSum = 0;
    for(int i=1; i<N+1; i++) {
        ans[i] += preSum;
        preSum += interval[i];
    }

    for(int i=1; i<N+1; i++) {
        cout << ans[i] << "\n";
    }
}

/*
1 | 6
2 | 6-
3 | 6
4 | 6--
5 | 6-
6 | 6-
7 | 6
8 | 6
9 | 6
*/