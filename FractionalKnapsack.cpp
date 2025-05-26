#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define N 1000005
#define MOD 1000000007

bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    return ((1.0 * a.first)/a.second) > ((1.0 * b.first)/b.second);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/GREEDY-ALGORITHMS/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/GREEDY-ALGORITHMS/output.txt", "w", stdout);
    #endif

    vector<pair<ll,ll> >input = {{60, 10}, {100, 20}, {120, 30}};

    ll capacity = 50;

    //sort on the basis of value/weight

    sort(input.begin(), input.end(), comp);

    long double value = 0.0;
    long double capacity_taken = 0.0;

    for(auto item : input) {
        long double remaining  = capacity-capacity_taken;

        if(remaining >= item.second) {
            value+=item.first;
            capacity_taken+=item.second;
        } else {
            value +=(((1.0 *remaining)/item.second)*item.first);
            break;
        }
    }

    cout << fixed << setprecision(4) << value << endl;
    return 0;
}