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

ll N;
int main() {
    cin >> N;
    ll fullsum = (N*(N+1))/2;
    ll sum = 0;
    for(int i=0; i<N-1; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    cout << fullsum - sum;
}