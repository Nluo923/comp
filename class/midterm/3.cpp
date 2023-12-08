
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
#define ll long long
#define mod 1000000007

struct Module{
    int x,y;
    bool w,n,e,s;
};

inline Module getModule(int y, int x, int n) {
    return {y, x, 1 == (n & 1), 1 == ((n >> 1) & 1), 1 == ((n >> 2) & 1), 1 == ((n >> 3) & 1)};
}

bool cmp(pair<int,bool> p1, pair<int,bool> p2) {
    return false;
}

int M, N;
int main() {
    cin >> M >> N;
    Module building[N][M];
    vector<vector<int> > visited(N, vector<int>(M, -1));

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int x;
            cin >> x;
            building[i][j] = getModule(i, j, x); 
        }
    }

    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++) {
            if(visited[y][x] != -1) continue;

            int idx = y*100 + x; 
            stack<Module> frontier;
            
            frontier.push(building[y][x]);
            visited[y][x] == idx;
            
            int tx, ty; //w n ss
            while(!frontier.empty()) {
                tx = frontier.top().x;
                ty = frontier.top().y;
                visited[ty][tx] = idx;

                frontier.pop();

                if(tx>0 && visited[ty][tx-1] == -1 && !building[ty][tx].w) { // w
                    frontier.push(building[ty][tx-1]);
                }
                if(ty>0 && visited[ty-1][tx] == -1 && !building[ty][tx].n) { // n
                    frontier.push(building[ty-1][tx]);
                }
                if(tx<M-1 && visited[ty][tx+1] == -1 && !building[ty][tx].e) { // e
                    frontier.push(building[ty][tx+1]);
                }
                if(ty<N-1 && visited[ty+1][tx] == -1 && !building[ty][tx].s) { // s
                    frontier.push(building[ty+1][tx]);
                }
            }
        }
    }

    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++) {
            cout << visited[y][x] << " ";
        }
        cout << "\n";
    }

    cout << building[0][0].e;
}