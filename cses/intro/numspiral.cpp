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

int T;
int main() {
    cin >> T;
    //find nearest square and travel there
    
    for(int t=0; t<T; t++) {
        int x, y;
        cin >> y >> x;

        ll nearest_sq, dist;
        ll band = max(x,y);

        nearest_sq = band*band;

        if(band % 2 == 1) dist = y + band - x - 1;
        if(band % 2 == 0) dist = x + band - y - 1;

        cout << nearest_sq - dist << "\n";
    }
}