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
    vector<int> pre1(N); // P win vs E
    vector<int> pre2(N); // E win vs T
    vector<int> pre3(N); // T win vs P

    char ci;
    cin >> ci;

    if(ci == 'E') {
        pre1[0]++;  
    } else if(ci == 'T') {
        pre2[0]++;
    } else {
        pre3[0]++;
    }

    for(int i=1; i<N; i++) {
        char c;
        cin >> c;
        if(c == 'E') {
            pre1[i]++;  
        } else if(c == 'T') {
            pre2[i]++;
        } else {
            pre3[i]++;
        }

        pre1[i] += pre1[i-1];
        pre2[i] += pre2[i-1];
        pre3[i] += pre3[i-1];
    }

    
}