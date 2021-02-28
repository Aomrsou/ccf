#include<iostream>
#include<map>
#include<cstring>
using namespace std;

map<string, string> result, stf;


string getStr(int *p, string temp){
	int i = *p;
	i++;
	string str = "";
	while(i < temp.length()){
		if(temp[i] == '\"'){
			break;
		}
		if(temp[i] == '\\'){
			i++;
		}
		str += temp[i];
		i++;
	}
	
	*p = i + 1;
	return str;
}

int main(){
	int n, m; // n行输入 m个输出 
	string path = "", str = "", tempStr = ""; 
	cin >> n >> m;
	cin.get();
	for(int i = 0; i < n; i++){ // 全搞成一行 
		getline(cin, tempStr);
		str += tempStr;
	}
	for(int i = 1; i < str.length() - 1; i++){ // 忽略首尾的括号 
		if(str[i] == ' ' || str[i] == ','){
			continue;
		}
		string key; 
		if(str[i] == '\"'){ // 开始收集字符串 并更新 i值 
			key = getStr(&i, str);
		}
		
		if(str[i] == ':') { // 分情况 
			i++;
			while(str[i] == ' '){
				i++;
			}
			
			if(str[i] == '\"'){ // 录入键值对 
				string value = getStr(&i, str);
				result[path + "." + key] = value;
				
				if(str[i] == '}') { // 如果结束 顺便退级 
					path = stf[path];
				} 
			}else if(str[i] == '{'){ // 开新副本  更新path
				stf[path + "." + key] = path;
				path = path + "." + key;
				result[path] = "likezhangyue";
			}
		
		} else if(str[i] == '}') { // 这里务必要判断呀 是2阶以上 
			path = stf[path];
		}
	}
	string key = ".";
	for(int i = 0; i < m; i++){
		getline(cin, tempStr);
		
		if(result[key + tempStr] == ""){
			cout << "NOTEXIST" << endl; 
		} else if(result[key + tempStr] == "likezhangyue"){
			cout << "OBJECT" << endl;
		} else {
			cout << "STRING " << result[key + tempStr] << endl; 
		}
	}
	return 0;
} 
/*
	核心思路:
		1. 保存所有.xx.xx.xx作为key，直接存value
		2. 遍历字符串时小心转义字符 
		3. 就是硬暴力 无敌的 
	Tips:
		全搞成一行  方便!!!方便极了！！！ 
		
*/ 

/*
16 5
{
	"a": {
		"b": {
			"c":"d"
		}
	},
	"e":{
		"f": {
			"g": {
				"h":"xx"
				}
			}
		}
	},
	"x": "z" 
}
e
e.f
e.f.g
e.f.g.h
x
*/
