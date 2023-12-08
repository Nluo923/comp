#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
#define ll long long
#define mod 1000000007

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    return (p1.first==p2.first) ? p1.first < p2.first : p1.second < p2.second;
}

int N;
int main() {
    N = 20;

    int switches = 0;

    for(int i=19; i>=0; i--) {
        int b;
        cin >> b;
        switches = switches | (b << i);
    }

    // cout << bitset<20>(switches);
    int min_change = 21;
    for(int i=0; i<(1<<N); i++) {
        int curr = switches;
        for(int j=0; j<N; j++) {
            if(((i & (1 << j)) > 0)) {  
                if(j == 0) {
                    curr = curr ^ ((1 << 19) + (1 << 18)); // 11...
                    break;
                }

                if(j == 19) {
                    curr = curr ^ ((1 << 0) + (1 << 1)); // ...11
                    break;
                }

                curr = curr ^ ((1 << (j-1)) + (1 << j) + (1 << (j+1)));
            }
        }

        if(__builtin_popcount(curr) == 0) {
            min_change = min(min_change, __builtin_popcount(i));
        };
    }

    cout << min_change;
}