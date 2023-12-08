#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
#define ll long long
#define mod 1000000007

bool cmp(pair<int,bool> p1, pair<int,bool> p2) {
    return false;
}

const pair<int,int> adj[] = {
    {-1, -1},
    {0, -1},
    {-1, 0},
    {1, 0},
    {1, 1},
    {0, 1}
};

int K, H, L;
int main() {
    cin >> K >> H >> L;
    const int NUM = 3*K*(K-1)+1;
    
    int grid[2*K-1][2*K-1]; for(int i=0; i<2*K-1; i++) for(int j=0; j<2*K-1; j++) grid[i][j] = 0;
    vector<pair<int,int>> locs(NUM+1);

    //neighbor is adjacent excluding top right and bottom left
    /*
    # # .
    # O #
    . # #

    # # #
    # # # #
    # # # # # 
      # # # #
        # # #
    */

    int idx = 1;
    int x = 0;
    int height = K;
    int y_i = height-1;
    for(; x<K*2-1; x++) {
        for(int y=y_i; y>=y_i-height+1; y--) {
            locs[idx] = {x,y};
            grid[y][x] = idx++;
        }

        if(x < K-1) {
            height++;
            y_i++;
        } else {
            height--;
        } 
    }

    // for(auto &x : grid) {
    //     for(int i : x) {
    //         cout << ((i > 0 && i <= NUM) ? i : 0) << " ";
    //     }
    //     cout << "\n\n";
    // } 

    int dists[NUM+1]; for(int &x : dists) x = 1e5;
    dists[H] = 0;
    // bfs and update dists to min dist

    queue<int> qi;
    qi.push(H);

    while(!qi.empty()) {
        int cur_idx = qi.front();
        pair<int,int> cur_loc = locs[cur_idx];
        int cur_dist = dists[cur_idx]; 
        qi.pop();

        for(auto a : adj) {
            int dx = a.first + cur_loc.first;
            int dy = a.second + cur_loc.second;

            if(0 > dx || dx >= K*2-1 || 0 > dy || dy >= K*2-1) continue;
            if(grid[dy][dx] <= 0) continue;
            if(dists[grid[dy][dx]] <= cur_dist + 1) continue; // don't search if dist is gonna be worse

            dists[grid[dy][dx]] = cur_dist + 1;
            qi.push(grid[dy][dx]); 
        }
    }

    vector<int> ans;
    for(int i=0; i<NUM+1; i++) {
        if(dists[i] == L) ans.push_back(i);
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for(auto &i : ans) cout << i << "\n";
}