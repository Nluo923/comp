#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <cstring>

using namespace std;
#define ll long long
#define mod 1000000007

bool cmp(pair<int,bool> p1, pair<int,bool> p2) {
    return false;
}

const int MAX_N = 2e5;

int N, farthest, dist;
vector<int> adj[MAX_N+1];
int visited[MAX_N+1] = {false};

int main() {
    cin >> N;
    if(N == 1) {
        cout << 0;
        exit(0);
    }

    for(int i=0; i<N; i++) {
        int n, j; cin >> n >> j;
        adj[n].push_back(j);
        adj[j].push_back(n);
    }

    queue<int> q;
    q.push(1);

    int cur;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        visited[cur] = true;
        for(int &a : adj[cur]) {
            if(visited[a]) continue;

            q.push(a);
        }
    }
    
    // cur will be farthest node at end of bfs
    // go again to farthest

    memset(visited, false, sizeof(visited));

    queue<int> dq;
    dq.push(0);
    q.push(cur);
    int cur_dist = 0, max_dist = 0;

    while(!q.empty()) {
        cur = q.front();
        q.pop();
        cur_dist = dq.front();
        dq.pop();
        max_dist = max(max_dist,cur_dist);

        visited[cur] = true;
        for(int &a : adj[cur]) {
            if(visited[a]) continue;

            q.push(a);
            dq.push(cur_dist+1);
        }
    }

    cout << max_dist;
} 