#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll dp[1000][1000] = {0};

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

//dynamic programming
//1.memoization
//	dp[m][n]; storing state value......

ll travel(int m, int n) {
	if (m == 1 || n == 1 ) {
		return 1;
	}
	if (m == 0 || n == 0) {
		return 0;
	}
	if (dp[m][n] == 0) {
		//n-1 for going left to right and m-1 for going down to up
		//as it is bottom up approach to this solution.
		dp[m][n] = travel(m - 1, n) + travel(m, n - 1);
	}
	return dp[m][n];
}

void solve() {
	int n, m;
	cin >> m >> n;
	cout << travel(m, n);
}


int main(int argc, char const *argv[])
{
	fastIO();
	solve();
	return 0;
}