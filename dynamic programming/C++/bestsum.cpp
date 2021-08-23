#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
using namespace std;
#define pf(val) cout<<#val <<"="<< val<<endl;
#define ll long long
#define print(a)  if(a[0]==0)cout<<"Not Possible";        \
	else                  \
for (int i = 0; i < a.size() - 1; ++i)  \
	cout << a[i + 1] << " "; \
cout << endl;        \

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<int> z(1);
//my solution for the problem
vector<int>  bestsum(vector<vector<int>> &dp, int sum, vector<int> *v) {
	// cout << (*dp)[sum][0];

	if (dp[sum][0] == 1) {
		return dp[sum];
	}

	// pf(sum);
	vector<vector<int>> x;
	if (sum == 0) {

		z[0] = 1;
		return z;
	}

	int flag = 0;
	for (int i = 0; i < v->size(); ++i)
	{
		int remiander =  sum - (*v)[i];
		if ( remiander >= 0)  {
			// pf(remiander);
			z = bestsum(dp, remiander, v);
			if (z[0] == 1) {
				// dp[sum].push_back((*v)[i]);
				z.push_back((*v)[i]);
				flag = 1;
				// return z;
			}

		}
		if (flag == 1) {
			x.push_back(z);
			// cout << "x=size = " << x.size() << endl;
			// for (int k = 0; k < x.size(); ++k)
			// {
			// 	cout << k << "=";
			// 	for (int j = 0; j < x[k].size(); ++j)
			// 	{
			// 		cout << x[k][j] << " ";
			// 	}
			// 	cout << endl;
			// }
			flag = 0;
		}
		z.clear();
		z.push_back(0);
	}
	if (x.size() == 1) {
		return x[0];
	}
	if (x.size() > 1) {
		int index = -1;
		vector<int> temp = x[0];
		for (int i = 0; i < x.size() - 1; ++i)
		{
			if (temp.size() > x[i + 1].size()) {
				temp = x[i + 1];
			}
		}
		x.clear();
		z = temp;
	}
	dp[sum] = z;
	return dp[sum];

}




//Inputs
// 4
// 7 4
// 5 3 4 7
// 8 3
// 2 3 5
// 8 3
// 1 4 5
// 100 4
// 1 2 5 25

void solve() {

	int sum, count = 0;
	cin >> sum;
	int n;
	cin >> n;
	vector<vector<int>> dp(1000, vector<int>(1));
	vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	z = bestsum(dp, sum, &v);
	print(z);
	// print(bestsum(dp, sum, &v));
	// z.clear();
	// z.push_back(0);

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



//alternative solution without dynamic programming but with clear code from online dude.

// vector<int> bestsum( int targetsum, vector<int>* number) {
// 	if (targetsum == 0) {
// 		z[0] = 1;
// 		return z;
// 	}
// 	if (targetsum < 0) {
// 		z[0] = -1;
// 		return z;
// 	}

// 	vector<int> short_combination;
// 	short_combination.push_back(-1);
// 	for (int i = 0; i < number->size(); ++i)
// 	{
// 		int remiander =  targetsum - (*number)[i];
// 		vector<int> remiander_combination = bestsum(remiander, number);
// 		if (remiander_combination[0] != -1) {
// 			remiander_combination.push_back((*number)[i]);
// 			vector <int> combination = remiander_combination;
// 			if (short_combination[0] == -1 || short_combination.size() > combination.size()) {
// 				short_combination = combination;
// 			}
// 		}
// 	}
// 	return short_combination;
// }
