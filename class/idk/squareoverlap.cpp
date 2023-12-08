#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;
#define ll long long
#define mod 1000000007


struct Event {
    int x, y1, y2;
    bool isLeft;

    bool operator<(const Event &e) const {return x < e.x;}
};

int N, K;

int main() {
    cin >> N >> K;
    multiset<pair<int,int> > s; 
    vector<Event> events(N);
    
    for (int i=0; i<N; i++) {
        int x,y;
        cin >> x >> y;
        events.push_back({x-K/2 , y-K/2 , y+K/2 , true});
        events.push_back({x+K/2 , y-K/2 , y+K/2 , false});
    }

    sort(events.begin(), events.end());
    s.insert({-10000000, -10000000});
    s.insert({10000000, 10000000});

    int cnt = 0, area = 0;
    for(Event& e : events) {
        if(e.isLeft) {
            s.insert({e.y1, e.x});
            continue;
        }

        s.erase({e.y1, e.x - K});

        auto i = s.lower_bound({e.y1, 0});
        pair<int,int> it = *i;
        int h = max(0, e.y2 - it.first);
        
        if(h > 0) {
            cnt++;
            area = (e.x - it.second) * h;
        }

        it = *prev(i);
        h = max(0, it.first + K - e.y1);
        if(h > 0) {
            cnt++; 
            area = (e.x - it.second) * h;
        }
    }

    if( cnt > 1) cout << -1;
    else cout << area;
}