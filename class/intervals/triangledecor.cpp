#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
#define ll long long
#define mod 1000000007

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    return (p1.first==p2.first) ? p1.second > p2.second : p1.first < p2.first;
}

int N;
int main() {
    cin >> N;
    vector<pair<int,int> > intervals(N);
    for(int i=0; i<N; i++) {
        int x,y;
        cin >> x >> y;
        intervals[i] = {x-y, x+y};
    }

    sort(intervals.begin(), intervals.end(), cmp);

    int endX = intervals[0].first;
    int cnt = 0;

    for(int i=0; i<N; i++) {
        int x2 = intervals[i].second;
        if(x2 <= endX) {
            cnt++;
        } else {
            endX = x2;
        }
    }

    cout << N - cnt;
}