#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
#define ll long long
#define mod 1000000007

int N;

bool cmp(const std::pair<int,int> &l, const std::pair<int,int> &r) {return l.second < r.second;}

int main() {
    cin >> N;
    vector< pair<int,int> > pointsX(N);
    vector< pair<int,int> > pointsY(N);
    for(int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        
        pointsX[i].first = x;
        pointsX[i].second = y;
        pointsY[i].first = x;
        pointsY[i].second = y;
    }
    
    sort(pointsX.begin(),pointsX.end());

    sort(pointsY.begin(),pointsY.end(), cmp);

    int ans = N;

    for(int i=0; i<N; i++) {
        int x1 = pointsX[i].first + 1;

        int A = i+1, B = N - A, C = 0, D = 0;

        ans = min(ans, max(A,B));

        for(int j=0; j<N; j++) {
            int x2 = pointsY[j].first;
            int y2 = pointsY[j].second;

            if(x2 < x1) {
                C++; 
                A--;
            } else {
                D++;
                B--;
            }
            
            if(C >= ans || D >= ans) break;

            ans = min(ans, max(A, max(B, max(C, D)) ) );
        }
    }

    cout << ans;
}