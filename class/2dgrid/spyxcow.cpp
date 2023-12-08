#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;
#define ll long long
#define mod 1000000007

struct compareX { 
    bool operator()(const pair<int, int>& value, const int& key) { 
        return (value.first < key); 
    } 
    bool operator()(const int& key, const pair<int, int>& value) { 
        return (key < value.first); 
    } 
}; 
 
struct compareY { 
    bool operator()(const pair<int, int>& value, const int& key) { 
        return (value.second < key); 
    } 
    bool operator()(const int& key, const pair<int, int>& value) { 
        return (key < value.second); 
    } 
}; 
 

/*
When checking new values if 100 subtract one subarray to prevent dupes.
Mark 100s as visited, if so have them as a bound.

Find biggest subarray bounded by bad numbers then calc subgrids in it.
*/


int N;
int main() {
    cin >> N;
    vector<vector<int>> grid(N, vector(N, 0));
    vector<pair<int,int>> safe;
    map<pair<int,int>, pair<int,int>> dupes;
    
    for(int j=0; j<N; j++) {
        for(int i=0; i<N; i++) {
            cin >> grid[i][j];
            if(grid[i][j] == 100) safe.push_back({i,j});
        }
    }

    sort(safe.begin(), safe.end());

    long long cnt = 0;

    for(pair<int,int> p : safe) {
        // up
        int o_min_x = 0, o_max_x = N-1;

        for(int x=p.first-1; x>=0; x--) {
            if(grid[x][p.second] < 100) {
                o_min_x = x;
                break;
            }

            cnt++;

            if(grid[x][p.second] == 100) dupes.insert({{x,p.second}, {p.first,p.second}});
        }


        for(int x=p.first+1; x<N; x++) {
            if(grid[x][p.second] < 100) {
                o_max_x = x;
                break;
            }

            cnt++;

            if(grid[x][p.second] == 100) dupes.insert({{x,p.second}, {p.first,p.second}});
        }

        int min_x = o_min_x, max_x = o_max_x;

        for(int y=p.second-1; y>=0; y--) {
            // this square.
            if(grid[p.first][y] < 100) break;

            cnt++;

            // left x
            for(int x=p.first-1; x>=min_x; x--) {
                if(grid[x][y] < 100) {
                    min_x = x+1;
                    break;
                }

                if(grid[x][y] == 100) dupes.insert({{x,y}, {p.first,p.second}});

                cnt++;
            }

            // right x
            for(int x=p.first+1; x<=max_x; x++) {
                if(grid[x][y] < 100) {
                    max_x = x-1;
                    break;
                }

                if(grid[x][y] == 100) dupes.insert({{x,y}, {p.first,p.second}});

                cnt++;
            }
        }

        // down
        min_x = o_min_x, max_x = o_max_x;
        for(int y=p.second+1; y<N; y++) {
            // this square.
            if(grid[p.first][y] < 100) break;

            cnt++;

            // left x
            for(int x=p.first-1; x>=min_x; x--) {
                if(grid[x][y] < 100) {
                    min_x = x+1;
                    break;
                }
                
                if(grid[x][y] == 100) dupes.insert({{x,y}, {p.first,p.second}});
                
                cnt++;
            }

            // right x
            for(int x=p.first+1; x<=max_x; x++) {
                if(grid[x][y] < 100) {
                    max_x = x-1;
                    break;
                }

                if(grid[x][y] == 100) dupes.insert({{x,y}, {p.first,p.second}});

                cnt++;
            }
        }
    }
    
    for(auto dupe : dupes) {
        if(dupes.count(dupe.second)) {
            cnt--;
            dupes.erase(dupe.second);
        }
    }

    cout << cnt;

}