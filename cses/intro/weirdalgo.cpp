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

long long N;
int main() {
    cin >> N;

    for(; N != 1; (N % 2 == 0) ? N/=2 : N=(N*3)+1) {
        cout << N << " ";
    };
    cout << 1;
}