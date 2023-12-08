#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;
#define ll long long
#define mod 1000000007

int N, K;
int main() {
    cin >> N >> K;

    map<int,int> m;
    
    int curX = 0;

    for(int i=0; i<N; i++) {
        int d, x1, x2; char dir;
        cin >> d >> dir;

        if(dir == 'L') {
            x1 = curX - d;
            x2 = curX;
            curX = x1;
        } else {
            x1 = curX;
            x2 = curX + d;
            curX = x2;
        }

        m[x1]++;
        m[x2]--;
    }

    int res = 0, cnt = 0;
    curX = 0;
    int preX = -1e9 - 5;

    for(pair<int,int> e : m) {
        curX = e.first;
        int val = e.second;

        if(cnt >= K) {
            res += curX - preX;
        }

        cnt += val;
        preX = curX;
    }

    cout << res;
}