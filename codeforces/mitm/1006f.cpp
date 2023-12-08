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

long N, M, K;
int main() {

    cin >> N >> M >> K;
    vector<vector<int >> a(N, vector<int>(M));
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> a[i][j];
        }
    }

    auto get_subset = [&](int l, int r) -> vector<long long> {
        int range = r - l + 1;
        vector<long long> out;

        for(int i = 0; i < (1 << range); i++) {
            long sum = 0;

            for(int j = 0; j < range; j++) {
                if((i & (1 << j)) > 0) { sum = sum ^ a[l+j]; }
            }
            out.push_back(s);
        } 

        return out;
    };

    vector<long long> setLeft = get_subset(0, N/2 - 1); 
    vector<long long> setRight = get_subset(N/2, N - 1);
    sort(setLeft.begin(), setLeft.end()); 
    sort(setRight.begin(), setRight.end()); 
}