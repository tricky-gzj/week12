#include<iostream>
#include<fstream>
#include<vector>
#include<std_lib_facilities.h>;
using namespace std;
long find(vector<string> x, string a) {
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == a) return i;
	}
	return -1;
}

void vector_copy(vector<int>a, vector<int>b) {
	for (int i = 0; i < a.size(); i++) {
		b.push_back(a[i]);
	}
}


int main() {
	ifstream fin;
	vector<string> suffix;
	vector<int> suffix_count;
	vector<int> count_copy;
	vector<string> same_suffix;
	fin.open("EnglishWords.txt");
	if (!fin.is_open()) { exit(EXIT_FAILURE); }
	string str;
	string tmp_str;
	int n;
	cout << "the number of letters of suffix:";
	cin >> n;
	//char line[100];
	while (getline(fin,str)) {
		int size = str.size();
		if (size < n) { continue; }
		else {
			tmp_str = str.substr(size - n, size);
			if (find(suffix, tmp_str) < 0) { suffix.push_back(tmp_str); suffix_count.push_back(1); }
			else {
				int t = find(suffix, tmp_str);
				suffix_count[t] += 1;
			}
		}
	}
	vector_copy(suffix_count, count_copy);
	sort(count_copy.begin(), count_copy.end());
	int t1 = count_copy.size();
	for (int i = t1-1; i >t1-11; i--) {
		for (int j = 0; j < suffix_count.size(); j++) {
			if (suffix_count[j] == count_copy[i]) {
				cout << "suffix:" << suffix[j] << endl;
				cout << "numbers:" << suffix_count[j] << endl;
			}
		}
	}//Êä³ötop10ºÍsuffix
	fin.close();
	fin.open("EnglishWords.txt");
	cout << "please enter the suffix(with the same length):";
	string _suffix;
	cin >> _suffix;
	while (getline(fin, str)) {
		int size = str.size();
		if (size < n) continue;
		else {
			if (str.substr(size - n, size) == _suffix) {
				same_suffix.push_back(str);
			}
		}
	}
	sort(same_suffix.begin(), same_suffix.end());
	for (int i = same_suffix.size() - 1; i >= 0; i--) {
		cout << same_suffix[i] << endl;
	}
	fin.close();
	system("pause");
	return 0;
}