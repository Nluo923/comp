#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <string>

using namespace std;
#define ll long long
#define mod 1000000007

int N, M;
int main() {
    cin >> N >> M;
    vector<int> freqL(M+1,0); 
    vector<int> freqR(M+1,0); 

    for(int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        freqL[a]++;
        freqR[b]++;
    }

    vector<int> diff(2*M+1,0); 
    for(int i=0; i<=M; i++) {
        for(int j=0; j<=M; j++) {
            diff[i+j] += freqL[i]*freqL[j];
        }
    }
    for(int i=0; i<=M; i++) {
        for(int j=0; j<=M; j++) {
            diff[i+j+1] -= freqR[i]*freqR[j];
        }
    }
    long long sum = 0;
    string s = "";
    for(int i=0; i<=2*M; i++) {
        sum += diff[i];
        s += to_string(sum) + "\n";
    }

    cout << s;
}

// int main() {
//     cin >> N >> M;
//     vector<pair<int,int> > freq(M+1);
//     for(int i=0; i<N; i++) {
//         int a,b;
//         cin >> a >> b;
//         freq[a].first++;
//         freq[b+1].second--;
//     } 

//     int diffA[2*M+1]; memset(diffA, 0, 2*M*sizeof(int));

//     for(int i=0; i<M; i++) {
//         for(int j=0; j<M; j++) {
//             diffA[i+j] += freq[i].first*freq[j].first;
//             diffA[i+j+1] -= freq[i].second*freq[j].second;
//         }
//     }   

//     int sum = 0;
//     for(int i=0; i<2*M; i++) {
//         sum += diffA[i];
//         cout << sum << "\n";
//     }


// }
