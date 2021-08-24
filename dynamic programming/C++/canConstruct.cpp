#include <iostream>
#include <vector>
#include <map>
#include <string>
// #include <string>
using namespace std;
#define ll long long
#define pf(a)cout<<#a<<"="<<a<<endl;
void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

map<string, int> memo;

//attempt 2 different strategy with dp.
bool canConstruc(string targetstr, vector<string> &v) {

	if (memo[targetstr] == 1) {
		return true;
	}
	else if (memo[targetstr] == -1) {
		return false;
	}

	if (targetstr == "") {
		return true;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		int size = v[i].size();

		if (size > targetstr.size()) {
			continue;
		}
		string str1 = targetstr;
		string str2 = targetstr;
		str1.erase(size, targetstr.size());
		str2.erase(0, size);

		if (v[i] == str1) {
			if (canConstruc(str2, v)) {
				memo[targetstr] = 1;
				memo[str2] = 1;
				return true;
			}
			else {
				continue;
			}
		}
		else {
			continue;
		}
	}
	memo[targetstr] = -1;
	return false;

}



void solve() {

	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < v.size(); ++i)
	{
		cin >> v[i];
	}
	string targetstr;
	cin >> targetstr;
	cout << ((canConstruc(targetstr, v)) ? "true" : "false") << endl;
}



int main(int argc, char const *argv[])
{
	fastIO();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

//Input
// 4
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




//Divide and conqure with dp used  in below commented function
// bool canConstruc(string targetstr, vector<string> &v) {

// 	// pf(targetstr);
// 	if (memo[targetstr] == 1) {
// 		// cout << "true" << endl;
// 		return true;
// 	}
// 	else if (memo[targetstr] == -1) {
// 		// cout << "false" << endl;
// 		return false;
// 	}


// 	if (targetstr.size() == 1) {
// 		for (int i = 0; i < v.size(); ++i)
// 		{
// 			// pf(memo[targetstr]);
// 			if (targetstr == v[i]) {
// 				memo[targetstr] = 1;
// 				// cout << "true" << endl;
// 				return true;
// 			}
// 			else {
// 				continue;
// 			}
// 		}
// 		memo[targetstr] = -1;
// 		// cout << "false" << endl;
// 		return false;
// 	}

// 	for (int i = 0; i < v.size(); ++i)
// 	{
// 		if (targetstr == v[i]) {
// 			memo[targetstr] = 1;
// 			// cout << "true" << endl;
// 			return true;
// 		}
// 		else {
// 			continue;
// 		}
// 	}


// 	int x = 0, mid = targetstr.size() / 2;
// 	if (targetstr.size() % 2 == 0) {
// 		x = 0;
// 	} else {
// 		x = 1;
// 	}


// 	string str1 = targetstr.substr(0, mid + x );
// 	string str2 = targetstr.substr(mid + x, targetstr.size());

// 	// pf(str1);
// 	// pf(str2);
// 	// cout << str1 << endl << str2 << endl;

// 	bool a1 = canConstruc(str1, v);
// 	// pf(a1);
// 	bool a2 = canConstruc(str2, v);


// 	// pf(a2);

// 	if (a1 == true && a2 == true) {
// 		memo[targetstr] = 1;
// 		return true;
// 	}

// 	if (targetstr.size() == 2) {
// 		memo[targetstr] = -1;
// 		// cout << "false" << endl;
// 		return false;
// 	}

// 	if (targetstr.size() == 3) {
// 		memo[targetstr] = -1;
// 		// cout << "false" << endl;
// 		return false;
// 	}

// 	string str21 = str1;
// 	string str12 = str2;
// 	str12.erase(0, 1);
// 	str21.erase(str1.size() - 1, str1.size());

// 	str1 = str1 + str2[0];
// 	str2 = str1[str1.size() - 2] + str2;
// 	// str21.erase(str1.size() - 2, str1.size());

// 	bool a = (canConstruc(str1, v) && canConstruc(str12, v)) ? true : false;
// 	bool b = (canConstruc(str2, v) && canConstruc(str21, v)) ? true : false;
// 	if ((a) || (b)) {
// 		if (a == true) {
// 			memo[str1] = 1;
// 			memo[str12] = 1;
// 			// cout << "true" << endl;
// 			return true;
// 		} else {
// 			memo[str2] = 1;
// 			memo[str21] = 1;
// 			// cout << "true" << endl;
// 			return true;
// 		}
// 	}
// 	else {
// 		if (a == false) {
// 			memo[str1] = -1;
// 			memo[str12] = -1;
// 			// cout << "false" << endl;
// 			return false;
// 		} else {
// 			memo[str2] = -1;
// 			memo[str21] = -1;
// 			// cout << "false" << endl;
// 			return false;
// 		}
// 	}
// 	return false;
// }