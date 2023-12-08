
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;
#define ll long long
#define mod 1000000007

bool cmp(pair<int,bool> p1, pair<int,bool> p2) {
    return false;
}

/*
map of L and R endpoints
pad the left end with X in the pre array IF L isn't 0
index L += -X + Y
index R+1 += -Y + Z
*/

int N,X,Y,Z;
int main() {
    cin >> N >> X >> Y >> Z;
    map<ll,ll> pre; //pos, val
    for(int i=0; i<N; i++) {
        int l,r;
        cin >> l >> r;
        // if(l != 0) pre[0] += X;
        pre[0] += X;
        pre[l] += Y - X;
        pre[r+1] += Z - Y;
    }
    
    bool first = true; ll ans = 0, sum = 0;
    for(auto& p : pre) {
        if(first) {
            sum = p.second;
            ans = p.second;
            first = false;
            continue;
        }

        sum += p.second;

        ans = max(sum, ans);
    }

    cout << ans;
}