
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;
#define ll long long
#define mod 1000000007

bool cmp(pair<int,bool> p1, pair<int,bool> p2) {
    return false;
}

int N;
int main() {
    cin >> N;

    //valid intvl = S <= W && even
    // sort >> coord compress pair{pos, isWhite} >> presum by isWhite
    vector<pair<int, bool>> orig(N);
    for(int i=0; i<N; i++) {
        char c;
        cin >> orig[i].first >> c;
        orig[i].second = (c=='W');
    }
    sort(orig.begin(), orig.end());

    map<int,int> firstSeen;

}