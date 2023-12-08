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

const int MAX_N = 2e5;

int N, ans = 0, goal = 0;
int hays[MAX_N];
vector<int> children[MAX_N];
int root_idx = 1;

int dfs(int cur, int parent) {
    if(children[cur].size() == 0) {
        return hays[cur];
    }

    int sum = 0;
    for(int child_idx : children[cur]) {
        sum += dfs(child_idx, parent);
    }

    return sum + hays[cur];
}

int main() {
    cin >> N;

    for(int i=0; i<N; i++) {
        int n;
        cin >> n;
        goal += n;    
    } goal /= N;

    for(int i=0; i<N-1; i++) {
        int c, t;
        cin >> c >> t;  
        children[c].push_back(t);
    }

    dfs(root_idx, -1);   
}