
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
#define ll long long
#define mod 1000000007

using pl = pair<long long, long long>;

pl operator+(pl a, pl b) {return {a.first+b.first, a.second+b.second};}
pl operator-(pl a, pl b) {return {a.first-b.first, a.second-b.second};}

vector<pair<pl, int>> get_subsets(const vector<pl> &dirs) {
	vector<pair<pl, int>> v{{}};
	for (const pl &d : dirs) {
		v.resize(2 * v.size());
		for (int i = 0; i < v.size() / 2; i++) {
			v[i + v.size() / 2] = {v[i].first + d, v[i].second + 1};
		}
	}
	sort(v.begin(), v.end());
	return v;
}

int N;
int main() {
    pl goal;
    vector<pl> dirs(N);

    cin >> N;
    cin >> goal.first >> goal.second;

    for(auto &d : dirs) cin >> d.first >> d.second;
    vector<pair<pl,int> > left = get_subsets(vector<pl>(begin(dirs), begin(dirs) + N/2));
    vector<pair<pl,int> > right = get_subsets(vector<pl>(begin(dirs) + N/2, end(dirs)));

    reverse(right.begin(), right.end());

    vector<ll> ans(N+1);
    vector<int> assoc;
    pl rest_prev{1e18, 1e18};
    int ib = 0;

    for (const auto &[offset, num] : left) {
		const pl rest = goal - offset;
		if (rest != rest_prev) {
			rest_prev = rest;
			assoc = vector<int>(N - N / 2 + 1);
			for (; ib < right.size() && right.at(ib).first > rest; ++ib);
			for (; ib < right.size() && right.at(ib).first == rest; ++ib) {
				++assoc.at(right.at(ib).second);
			}
		}
		for (int i = 0; i < assoc.size(); i++) {
			ans[i + num] += assoc[i];
		}
	}
    for (int i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}
}