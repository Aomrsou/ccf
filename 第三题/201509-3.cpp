#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<string, string>parm;
string model[101] = {""};
string str;
int main(){
	int m, n; // m 模板行数， n 变量数 
	cin >> m >> n;
	cin.get();
	for(int i = 0; i < m; i++){
		getline(cin, model[i]);
	}
	for(int i = 0; i < n; i++){ // 键值对设置
		getline(cin, str);
		int space = str.find(' ');
		parm["{{ " + str.substr(0, space) + " }}"] 
			= str.substr(space + 2, str.length() - space - 3);
	}
	for(int i = 0; i < m; i++){
		int p1 = 0, p2 = 0;
		while((p1 = model[i].find("{{", p1)) != -1){
			p2 = model[i].find("}}", p1);
			p2 += 2;
			string key = model[i].substr(p1, p2 - p1);
			
			model[i] = model[i].replace(p1, key.length(), parm[key]); // 直接换
			p1 = p1 + parm[key].length(); // 加上替换之后的子串的长度 
		}
		cout << model[i] << endl;
	}
	return 0;
}
/*
	Tips:
		今天玥宝要学习 str.find("xxx", position);   是string str;
		position就是从position之后开始寻找，跟这道题非常契合，巧用更新position即可
		以及 
		str.replace(从哪开始换, 换多长, 要换成哪个字符串);
	核心思路:
		要注意到以下三点：
		1°如果标记中的变量没有定义，则生成空串，相当于把标记从模板中删除
		2°模板不递归生成。也就是说，如果变量的值中包含变量本身，不再做进一步的替换。
		3°一句话中可能有好几个变量，相同或不相同，能用或不能用
		综上所述，我们的思路是，置position初始为0，每次找到变量后判断是哪种变量
		然后position加上 被置换字符串的长度，接着 find，直到找不到 
*/ 
