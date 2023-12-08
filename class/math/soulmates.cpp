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

int N;
int main() {
    cin >> N;
    vector<pair<int,int>> pairs(N);
    for(int i=0; i<N; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    for(auto p : pairs) {
        //get to lowest by div and add 1
        int steps = 0;
        vector<int> AC, CB;
        
        int a = p.first;
        AC.push_back(a);
        while(a > 1) {
            if(a % 2 == 0) a /= 2;
            else a++;

            AC.push_back(a);
        }

        int b = p.second;
        CB.push_back(b);
        while(b > 1) {
            if(b % 2 == 0) b /= 2;
            else b--;

            CB.push_back(b);
        }

        int res = 1e6; int j = 0;
        for(int i=0; i<AC.size(); i++) {
            if(AC[i] > b) continue;
            int temp = AC[i] + (b - AC[i]);
            while(j < CB.size() && CB[j] > AC[i]) j++;

            if(j < CB.size() && AC[i] == CB[j]) {
                res = min(res, AC[i] + CB[j]);
            }
        }

        cout << temp;
    }
}