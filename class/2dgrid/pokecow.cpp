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

    vector<pair<int,int>> points(N);
    for(int i=0; i<N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());
    for(int i=0; i<N; i++) {
        points[i].first = i;
    }
    sort(points.begin(), points.end(), [](pair<int,int> p1, pair<int,int> p2) { return p1.second < p2.second; });
    for(int i=0; i<N; i++) {
        points[i].second = i;
    }

    sort(points.begin(), points.end());

    vector<vector<int>> presumL(N, vector<int>(N+1));
    vector<vector<int>> presumG(N, vector<int>(N+1));

    for(int i=0; i < N; i++) {
        int y = points[i].second;
        for(int x=1; x<=N; x++) {
            presumL[y][x] = presumL[y][x-1] + (points[x-1].second < y);
            presumG[y][x] = presumG[y][x-1] + (points[x-1].second > y);
        }
    }

    long long ans = 0;

    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            int low = min(points[i].second, points[j].second);
            int hi = max(points[i].second, points[j].second);

            long long lower = 1 + presumL[low][j+1] - presumL[low][i];
            long long higher = 1 + presumG[hi][j+1] - presumG[hi][i];
            ans += lower*higher;
        }
    }

    ans += N + 1;

    cout << ans;
}