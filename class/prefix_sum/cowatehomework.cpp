
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

int N;
int main() {
    cin >> N;
    int scores[N];
    int preSum[N];
    int curMin = 0;
    int mini[N];
    int K[N];
    int maxK = 0;
    vector<int> validK;

    for(int i=0; i<N; i++) {
        cin >> scores[i]; 
    }

    preSum[N-1] = scores[N-1];
    curMin = scores[N-1];
    mini[N-1] = curMin;
    for(int i=N-2; i>=0; i--) {
        preSum[i] = scores[i]+preSum[i+1];
        curMin = min(curMin, scores[i]);
        mini[i] = curMin;
    }

    for(int k=2; k<N-2; k++) {
        int avg = (preSum[k] - mini[k]) / (N - k - 2);
        K[k] = avg;
        maxK = max(k, maxK);
    }

    for(int i=1; i<N; i++) {
        if(K[i] == maxK) validK.push_back(i);
    }

    sort(validK.begin(), validK.end());

    for(int k : validK) cout << k << "\n";
}