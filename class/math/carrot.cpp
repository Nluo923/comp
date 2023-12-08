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

    int x = N/8*15;
    int r = N%8;
    int a[] = {-1,1,2,4,7,8,11,13,14};

    cout << x + a[r];
}