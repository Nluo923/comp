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

int N, K;
const int SIZE = 1005;
int main() {
    cin >> N >> K;

    vector<vector<int>> rects(SIZE, vector<int>(SIZE,0));

    for(int i=0; i<N; i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rects[x1][y1]++;
        rects[x2][y1]--;
        rects[x1][y2]--;
        rects[x2][y2]++;
    }

    int ans = 0;

    vector<vector<int>> presum(SIZE, vector<int>(SIZE,0));
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(i>0) presum[i][j] += presum[i-1][j];
            if(j>0) presum[i][j] += presum[i][j-1];
            if(i>0 && j>0) presum[i][j] -= presum[i-1][j-1];
            presum[i][j] += rects[i][j];

            ans += (presum[i][j] == K);
        }
    }
    
    cout << ans;
}