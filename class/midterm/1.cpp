#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>

using namespace std;
#define ll long long
#define mod 1000000007


struct Event {
    int x, h, i;
    bool isLeft;
};

bool cmp(Event e1, Event e2) {
    return (e1.x == e2.x) ? e1.isLeft : e1.x < e2.x;
}

inline bool operator<(const Event& lhs, const Event& rhs)
{
  return lhs.h < rhs.h;
}

int N;
int main() {
    cin >> N;
    vector<Event> events;
    for(int i=0; i<N; i++) {
        int a, b, h;
        cin >> a >> b >> h;
        events.push_back({a, h, i, true});
        events.push_back({b, h, i, false});
    }

    sort(events.begin(), events.end(), cmp);

    // for(Event e : events) cout << e.x << " " << e.h << " " << e.isLeft << " \n";

    int x = 0, prevX = 0, h = 0, prevH = 0, sum = 0;
    bool first = true;
    set<Event> set;
    for(Event e : events) {
        if(e.isLeft) set.insert(e);
        // else {
        //     for(auto e1 = set.begin(); e1 != set.end(); ++e1) {
        //         if((*e1).i == e.i) events.erase(e1);
        //     }
        // }

        x = (*set.rbegin()).x;
        h = (*set.rbegin()).h;

        if(first) {
            first = false;
            prevX = x;
            prevH = h;
            continue;
        }
        
        sum += (x-prevX)*prevH;

        prevX = x;
        prevH = h;
    }

    cout << sum;
}