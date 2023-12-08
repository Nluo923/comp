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

string s;
int main() {
    cin >> s;
    
    char prev = s[0];
    int combo=1, maxcombo=1;
    for(int i=1; i<s.length(); i++) {
        if(prev == s[i]) {
            combo++;
            maxcombo = max(maxcombo, combo);
        }            
        else {
            maxcombo = max(maxcombo, combo);
            combo = 1;
        }
        
        prev = s[i];
    }

    cout << maxcombo;
}