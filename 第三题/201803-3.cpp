#include<iostream>
#include<string>
#include<set>
using namespace std;

int isNum(string str) {
	int result = 1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < '0' || str[i] > '9') {
			result = 0;
			break;
		}
	}
	return result;
}

string getNum(string str) {
	int flag = 0;
	while (str[flag] == '0') {
		flag++;
	}
	return str.substr(flag);
}

const string C = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM-_./";
int main() {
	int n, m;
	string R[100], N[100], Q[100], P;
	set<char> S;
	cin >> n >> m;
	cin.get();
	for (int i = 0; i < n; i++) {
		cin >> R[i] >> N[i]; // R 是参数路径 N是名字
	}
	for (int i = 0, f, p1, p2; i < m; i++) { // f -1不匹配 1匹配 0未知
		cin >> Q[i]; // Q是待匹配路径
		f = 0;
		S.clear();
		S.insert(C.begin(), C.end());
		S.insert(Q[i].begin(), Q[i].end());
		if (S.size() == C.size()) { // 没有非法字符
			for (int j = 0; j < n && f < 1; j++) { // 对比第j个R和Q是否匹配
				int k = 0, nk = Q[i].size(), l = 0, nl = R[j].size();
				P = "";
				f = 0;
				string K = Q[i], L = R[j], s1, s2;
				while (k < nk && l < nl && f == 0) {
					p1 = k + 1;
					k = K.find('/', p1);
					s1 = K.substr(p1, (k == string::npos ? k = nk : k) - p1);
					p2 = l + 1;
					l = L.find('/', p2);
					s2 = L.substr(p2, (l == string::npos ? l = nl : l) - p2);
					if (s1 != "" && s2 == "<int>" && isNum(s1)) {
						P += " " + getNum(s1);
					}
					else if (s1 != "" && s2 == "<str>") {
						P += " " + s1;
					}
					else if (s1 != "" && s2 == "<path>") {
						P += " " + K.substr(p1, nk - p1);
						f = 1; // 一定匹配
					}
					else if (s2 != s1){
						f = -1;
					}
				}
				if (f != -1 && k == nk && l == nl || f == 1) {
					f = 1;
					cout << N[j] << (P.size() > 0 ? P : "") << endl;
				}
			}
		}
		if (f < 1) cout << "404" << endl;
	}
	return 0;
}

/*
	Tips:
		今天玥宝可以学C++11标准下的#include<unordered_set> 
		此题用来暴力判断合法字符
		unordered_set<char> S;
		S.insert(string.begin(), string.end());
		S.clear();
	核心思路：
		两个for循环 遍历之，重要的是字符串的处理
		★ 对于<path>来说，他必是结尾，不用考虑斜杠
		string::npos  字符串查找 找不到的返回值为这个 而非有符号-1
*/
