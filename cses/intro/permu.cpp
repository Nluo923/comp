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

int main() {
    int N; cin >> N;   

    if(N == 1) {
        cout << 1;
        exit(0);
    }

	vector<int> v(N);
	int x=0, l=0;
	for(int i=2; i<=N; i+=2, x++) {
		v[x] = i;
		l = i;
	}
	
	if(l - 2 <= 1) {
		cout << "NO SOLUTION";
	} else {
		for(int i=1; i<=N; i+=2, x++) {
			v[x] = i;
		}

		for(int i : v) {
			cout << i << " ";
		}
	}

}