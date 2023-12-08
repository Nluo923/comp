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

int N;
int main() {
    cin >> N;
    vector<pair<int,bool> > intervals;
    
    for(int i=0; i<N; i++) {
        int a,b;
        cin >> a >> b;
        intervals.push_back({a,true});
        intervals.push_back({b,false});
    }


    sort(intervals.begin(), intervals.end(), cmp);

    int res=0, cnt=0;
    for(pair<int,bool> i : intervals) {
        if(i.second) {
            cnt++;
            res = max(res,cnt);
        } else {
            cnt--;
        }

    }

    cout << res;
}