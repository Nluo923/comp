
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

int main() {
    int N, Q;
    int lastSeen[26] = {-1};
    int solL[26];
    cin >> N >> Q;
    string fence;
    cin >> fence;
    const char *fenceArr = fence.c_str();
    for(int i=0; i<fence.length(); i++) {
        
    }

    for(int i=1; i<N; i++) {
        solL[i] = solL[i-1];
    }
}