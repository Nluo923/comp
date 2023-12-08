#include <stack>
#include <array>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int N, W;
	cin >> N >> W;
	stack<int> s;
	s.push(0);
	
	int ans = 0;

	for(int i=0; i<N; i++) {
		int x, h;
		cin >> x >> h;
		
		while (h < s.top()) {
			ans++;
			s.pop();
		}

		if(h > s.top()) {
			s.push(h);
		}

	}

	cout << s.size() + ans - 1;
}
