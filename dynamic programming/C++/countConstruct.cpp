#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define pf(a) cout<<#a<<"="<<a<<endl;

map<string, int> memo;

int solve(string targetstr , vector<string> &v) {
	// pf(targetstr);
	int count = 0;
	if (memo[targetstr] > 0 ) {
		return memo[targetstr];
	}
	if (memo[targetstr] == -1) {
		return 0;
	}

	if (targetstr == "") {
		return 1;
	}
	int target_size = targetstr.size();
	for (int i = 0; i < v.size(); ++i)
	{
		int size = v[i].size();

		if (size > target_size) {
			continue;
		}

		string str1 = targetstr;
		string str2 = targetstr;
		str1.erase(size, targetstr.size());
		str2.erase(0, size);

		int temp;
		if (v[i] == str1) {

			temp = solve(str2, v);
			count += temp;
		}

	}
	if (count == 0) {
		memo[targetstr] = -1;
		return 0;
	} else {
		memo[targetstr] = count;
		return count;
	}

}

int main(int argc, char const * argv[])
{

	int t;
	cin >> t;
	while (t--) {
		memo.clear();
		int n;
		cin >> n;
		int count = 0;
		vector<string> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}

		string targetstr;
		cin >> targetstr;
		cout <<  solve(targetstr, v ) << endl;
	}
	return 0;
}

//Input
// 5
// 5
// purp p ur le purpl
// purple
// 5
// ab abc cd def abcd
// abcdef
// 7
// bo rd ate t ska sk boar
// skateboard
// 7
// a p ent enter ot o t
// enterpotentpot
// 6
// e ee eee eeee eeeee eeeeee
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef