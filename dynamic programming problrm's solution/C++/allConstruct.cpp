#include <iostream>
#include<map>
#include <vector>
#include <algorithm>
#define pf(a)cout<<#a<<"="<<a<<endl;
using namespace std;
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl

int count1 = 0;

map<string, vector<vector<string>>> memo;

//soltion with dynamic programming....
vector<vector<string>> solve(string targetstr , vector<string> &v) {

	vector<vector<string>> all_list;

	if (memo[targetstr].size() != 0) {
		// cout << "memo used";
		return memo[targetstr];
	}


	if (targetstr == "") {
		all_list.push_back({""});
		return all_list;
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


		if (v[i] == str1) {

			vector<vector<string>> temp = solve(str2, v);

			if (temp.size() == 1 && temp[0][0] != "not found any combination.") {
				memo[str2] = temp;
				temp[0].push_back(v[i]);

				all_list.push_back(temp[0]);

			}

			if (temp.size() > 1) {

				for (int j = 0; j < temp.size(); ++j)
				{
					temp[j].push_back(v[i]);
					all_list.push_back(temp[j]);
					memo[str2] = temp;
				}

			}

		}
	}

	//dont forget this part ,
	//To memoize for pattern which is not found in the solution, I had to do following, In node js code would have been much simpler.
	// otherwise it will take time to answer becasue first if condition is  only checks
	//if patterns are availble in memo if not it will process again for which we alredy had worked for and had not found  so,
	//here i need to give the value that represents that pattern is not available in solution inside memo so we don't have to work again.
	//"not found any combination." - this is the value i have chosen.
	// if condition on line no: 53 - if(temp.size() == 1 && temp2[0][0] != "not found any combination."){} to check.
	//
	//------------------------------------------------
	if (all_list.size() == 0) {

		memo[targetstr] = {{"not found any combination."}};
		all_list = memo[targetstr];
		return all_list;
	} else {
		memo[targetstr] = all_list;
		return all_list;
	}
	//----------------------------------------------

}



int main(int argc, char const * argv[])
{
	int t;
	cin >> t;
	vector<vector<string>> storage;
	while (t--) {
		memo.clear();
		int n;
		cin >> n;
		vector<string> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		string targetstr;
		cin >> targetstr;
		storage = solve(targetstr, v);
		// pf(storage.size());
		cout << ++count1 << endl;

		for (int i = 0; i < storage.size() ; ++i)
		{
			reverse(storage[i].begin(), storage[i].end());
			for (int j = 0; j < storage[i].size(); ++j)
			{
				cout << storage[i][j] << " ";
			}
			cout << endl;
		}

	}
	return 0;
}

//Input
// 5
// 5
// purp p ur le purpl
// purple
// 7
// ab abc cd def abcd ef c
// abcdef
// 7
// bo rd ate t ska sk boar
// skateboard
// 7
// a p ent enter ot o t
// enterpotentpot
// 5
// e ee eee eeee eeeee
// eeeeeeeeeeeeeeeeeeeeeeez


//Output
// 1
// purp le
// p ur p le
// 2
// ab cd ef
// ab c def
// abc def
// abcd ef
// 3
// not found any combination.
// 4
// enter p ot ent p ot
// enter p ot ent p o t
// enter p o t ot ent p ot
// enter p o t ot ent p o t
// 5
// not found any combination.
