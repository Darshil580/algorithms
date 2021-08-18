#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
using namespace std;
#define ll long long
#define print(a)  if(a.empty())cout<<"NULL";        \
	else                  \
    for (auto x : a)      \
        cout << #a<<" = "<< x << " "; \
    cout << endl          \

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<vector<int>> x(1000);

vector<int>  bestsum(ll* dp, int sum, vector<int>* v) {

	vector<int> y(1);
	// cout << "sum=" << sum << endl;
	// if (dp[sum] != 0) {
	// 	return (dp[sum] == 1 ? true : false);
	// }

	if (sum == 0) {
		y[0] = 0;
		return y;
	}
	for (int i = 0; i < v->size(); ++i)
	{

		int remiander =  sum - (*v)[i];
		// cout << "remiander=" << remiander << "\n" ;
		if (remiander >= 0) {

			y = bestsum(dp, remiander, v);
			// cout << y[0] << endl;
			if (y[0] == 0) {
				y.push_back((*v)[i]);
				// print(y);
			}
			else if (y[0] == 1) {
				continue;
			}
		}
		if (y[0] == 0) {

			x.push_back(y);

		}
	}
	int index = 0;
	for (int i = 0; i < x.size() - 1; ++i)
	{
		if (x[i].size() > x[i + 1].size()) {
			index = i + 1;
		}
		else {
			index = i;
		}
	}
	if (y[0] == 0) {
		return x[index];
	}
	else {
		y[0] = 1;
		return y;
	}

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
	int sum, count = 0;
	cin >> sum;
	int n;
	cin >> n;
	ll dp[1000] = {0};
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	print(bestsum(dp, sum, &v ));
	// cout << ( ? "true\n" : "false\nNULL");
	// print(x);
	// cout << endl;
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