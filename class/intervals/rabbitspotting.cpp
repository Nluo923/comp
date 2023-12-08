#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
#define ll long long
#define mod 1000000007

bool cmp(pair<int,bool> p1, pair<int,bool> p2) {
    if (p1.first != p2.first) return (p1.first < p2.first);

    return (p1.second && !p2.second);
}

int N, A, B;
int main() {
    cin >> N >> A >> B;
    vector<pair<int,int> > rabbits(N+2);
    vector<pair<int,int> > intervals;
    
    for(int i=0; i<N; i++) {
        string str;
        int x;
        cin >> str >> x;
        rabbits[i].first = x;
        rabbits[i].second = (str == "S") ? 1 : 0;
    }

    rabbits[N].first = 0; rabbits[N].second = 0;
    rabbits[N+1].first = 1e9+5; rabbits[N+1].second = 1e9+5;

    sort(rabbits.begin(), rabbits.end());

    rabbits.erase(unique(rabbits.begin(), rabbits.end()), rabbits.end());
    // for(pair<int,int> p : rabbits) cout << p.first << "," << p.second << "\n";

    N+=2;

    for(int i=1; i<N; i++) {
        if(rabbits[i].second == 0) continue;

        int x1 = rabbits[i-1].first, x2 = rabbits[i].first, x3 = rabbits[i+1].first;
        int mid1 = (x1+x2)/2, mid2 = (x2+x3)/2;
        if((x2-x1) % 2 == 1) mid1++;
        if(mid1 > B || mid2 < A) continue;

        pair<int,int> interval = {max(A, mid1), min(B, mid2)};
        intervals.push_back(interval);
    }

    int res = intervals[0].second - intervals[0].first + 1;
    for(int i=1; i<size(intervals); i++) {
        res += intervals[i].second - intervals[i].first + 1;
        if(intervals[i].first == intervals[i-1].second) res--;
    }

    cout << res;
}
