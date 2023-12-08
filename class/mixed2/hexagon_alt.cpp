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

int K, H, L;
int main() {
    cin >> K >> H >> L;
    const int NUM = 3*K*(K-1)+1;

    pair<int,int> locs[NUM];
    int dists[4*K-3][2*K-1];

    int cnt = 1;
    for(int col = 0; col < K; col++) {
        int y_i = 2*K + col;
        for(int j=0; j<K+col; j++) {
            int y = y_i - j*2;
            locs[cnt-1] = {col, y};
            cnt++;
        }  
    }

    for(int col = K; col < K*2-1; col++) {
        int y_i = 2*K + col;
        for(int j=0; j<K+col; j++) {
            int y = y_i - j*2;
            locs[cnt-1] = {col, y};
            cnt++;
        }  
    }
}