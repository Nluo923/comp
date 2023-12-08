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
vector<int> children[MAX_N+1]; 
int known[MAX_N+1] = {-1};

int dfs(int cur) {
    if(children[cur].empty()) return 0;

    int sum = 0;
    for(int child : children[cur]) {
        if(known[child] == -1) sum += known[child] + 1;
        else {
            known[child] = dfs(child);
            sum += known[child] + 1;
        }
    }

    return sum;
}

int main() {
    cin >> N;

    for(int i=2; i<=N; i++) {
        int n;
        cin >> n;
        children[n].push_back(i);
    }

    cout << dfs(1) << " ";
    for(int i=2; i<=N; i++) {
        cout << known[i] << " ";
    }
}