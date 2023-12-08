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

const pair<int,int> d[] = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};

int N, M;
vector<vector<bool>> visited(1000,vector<bool>(1000,false));
vector<vector<bool>> grid(1000,vector<bool>(1000,false));

void dfs(int x, int y) {
    visited[x][y] = true;

    for(pair<int,int> dir : d) {
        int dx = x + dir.first;
        int dy = y + dir.second;
        if(dx >= 0 && dx < N && dy >= 0 && dy < M && !visited[dx][dy] && grid[dx][dy]) dfs(dx,dy);  
    }
}

int main() {
    cin >> N >> M;
    int ans = 0;

    for(int i=0; i<N; i++) {
        string s;
        cin >> s;

        int j = 0;
        for(auto c: s) {
            grid[i][j] = c == '.';
            j++;
        }
    }

    for(int y=0; y<M; y++) {
        for(int x=0; x<N; x++) {
            if(!visited[x][y] && grid[x][y]) {
                dfs(x,y);
                ans++;
            }
        }
    }
    cout << ans;
}