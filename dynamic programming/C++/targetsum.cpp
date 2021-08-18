#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
using namespace std;
#define ll long long
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl




void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


//Non Dynamic Programming Logic...........................

// bool checksum(ll* dp, int sum, vector<int>* v) {
// 	// cout << "sum=" << sum << endl;
// 	if (sum == 0) {
// 		return true;
// 	}
// 	for (int i = 0; i < v->size(); ++i)
// 	{
// 		int remiander =  sum - (*v)[i];
// 		if ( remiander >= 0 && checksum(dp, remiander, v)) {
// 			return true;
// 		}
// 	}
// 	return false;
// }

// adding dynamic programming to the logic.....................
bool checksum(ll* dp, int sum, vector<int>* v) {
	// cout << "sum=" << sum << endl;
	if (dp[sum] != 0) {
		return (dp[sum] == 1 ? true : false);
	}

	if (sum == 0) {
		dp[sum] = 1;
		return true;
	}
	for (int i = 0; i < v->size(); ++i)
	{
		int remiander =  sum - (*v)[i];
		if ( remiander >= 0 && checksum(dp, remiander, v)) {
			dp[sum] = 1;
			return true;
		}
	}
	dp[sum] = -1;
	return false;
}

//Inputs
// 5
// 7 2
// 2 3
// 7 4
// 5 3 4 7
// 7 2
// 2 4
// 8 3
// 2 3 5
// 300 2
// 7 14


void solve() {
	int sum;
	cin >> sum;
	int n;
	cin >> n;
	ll dp[1000] = {0};
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	cout << (checksum(dp, sum, &v) ? "true" : "false") << endl;
	// cout << "end";
}

int main(int argc, char const * argv[])
{
	fastIO();
	int T;
	cin >> T;
	// print(dp);
	while (T--) {
		solve();
	}
	return 0;
}