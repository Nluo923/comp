#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
#define mod 1000000007

vector<int> cards;
int N, K, L;

// 56 2 2 2
bool check(int r) {
    // even if all upgrades were used, it will fail
    if(r - cards[r-1] > K) return false;

    // are the K upgrades enough
    int e = 0;
    for(int i=r-1; i>=0; i--) {
        e += max(0, r - cards[i]);

        if(e > K*L) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> K >> L;    
    for(int i=0; i<N-1; i++) {
        int t;
        cin >> t;
        cards.push_back(t);
    }

    sort(cards.begin(), cards.end(), greater<int>());

    //binary search for an r
    // r cant exceed n
    int low = 0, high = N, r;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(check(mid)) {
            r = mid;
            low = mid+1;
        } else {
            high = mid-1;
        } 
    }

    cout << r;
}