#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;
#define ll long long
#define mod 1000000007

bool cmp(pair<int,bool> p1, pair<int,bool> p2) {
    return false;
}

const int MAX_N = 2e5;

int N;
int ans = 0;
bool seen[MAX_N+1] = {false};
vector<int> children[MAX_N+1];

void dfs(int pre, int cur) { 
    for(auto &c : children[cur]) {
        if(pre == c) continue;

        dfs(cur, c);
        if(!seen[c] && !seen[cur]) {
            seen[cur] = seen[c] = 1;
            ans++;
        }
    }
}

int main() {
    cin >> N;
    for(int i=0; i<N-1; i++) {
        int n, k;
        cin >> n >> k;
        children[n].push_back(k);
        children[k].push_back(n);
    }

    dfs(0, 1);
    cout << ans;
}