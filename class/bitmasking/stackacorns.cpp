#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
#define ll long long
#define mod 1000000007

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    return (p1.first==p2.first) ? p1.first < p2.first : p1.second < p2.second;
}

int N;
int main() {
    cin >> N;

    vector<pair<int,int> > acorns(N);
    for(int i=0; i<N; i++) {
        cin >> acorns[i].first >> acorns[i].second;
    }

    sort(acorns.begin(), acorns.end());

    int max_size = 0;
    for(int i=0; i<(1<<N); i++) {
        int prev_depth = -1;
        int prev_width = -1;
        int size = 0;
        bool bad = false;

        for(int j=0; j<N; j++) {
            if(((i & (1 << j)) > 0)) {
                // if(i == 54) cout << acorns[j].second << " ";
                if(prev_depth >= acorns[j].second || prev_width >= acorns[j].first) {
                    bad = true;
                    // cout << "bad " << bitset<6>(i) << "\n";
                    break;
                }
               
                size++;
                prev_depth = acorns[j].second;
                prev_width = acorns[j].first;
            }
        }

        if(bad) continue;
        // cout << "good " << bitset<6>(i) << " -> " << size << "\n";
        max_size = max(size, max_size);
    }

    cout << max_size;
}