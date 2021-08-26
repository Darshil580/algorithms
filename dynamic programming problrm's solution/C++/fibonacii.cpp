#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

//slow for a larger number like 50 or 45  etc.
//classic fibonacii logic.........
// int fib(ll n) {
// 	if (n <= 2)
// 		return 1;
// 	else
// 		return fib(n - 1) + fib(n - 2);
// }


//dynamic programming
//1.memoization
//	dp[n]; storing state value......

int fib(ll* dp, ll n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	if (dp[n] == 0) {
		dp[n] = fib(dp, n - 1) + fib(dp, n - 2);
	}
	return dp[n];
}

void solve() {
	ll n;
	cin >> n;
	ll dp[n + 1] = {0};
	dp[1] = dp[2] = 1;
	cout << fib(dp, n);
}


int main(int argc, char const *argv[])
{
	// cout << fib(45);
	fastIO();
	solve();
	return 0;
}


//Input
// 55

//Output
// 2144908973


