#include<iostream>
#include<cstring>
using namespace std;
string strs[105];
string h[13] = {"<h1>","<h2>","<h3>","<h4>","<h5>","<h6>",
"</h1>","</h2>","</h3>","</h4>","</h5>","</h6>"};

string inlineOperate(string str){ // 处理行内 
	int p1 = 0, p2 = 0;
	while((p1 = str.find('_', p1)) != -1){ // 强调 
		str.replace(p1, 1, "<em>");
		p2 = str.find('_', p1+1);
		str.replace(p2, 1, "</em>");
	}
	p1 = 0, p2 = 0;
	if((p1 = str.find('[', p1)) != -1){ // 超链接 
		p2 = str.find(']', p1+1);
		string link = str.substr(p1 + 1, p2 - p1 - 1);
		str.replace(p1, p2 - p1 + 1, ""); // 保存完以后删掉
		p1 = 0, p2 = 0;
		p1 = str.find('(', p1);
		str.replace(p1, 1, "<a href=\"");
		link = "\">" + link + "</a>";
		p2 = str.find(')', p1 + 1);
		str.replace(p2, 1, link);
	}
	return str;
}

int main(){
	string line, lastLine;
	int pFlag = 0, uFlag = 0, flag = 0;
	while(getline(cin, line)){
		if(line != ""){ // 非空行 
			if(line[0] == '#'){ // 标题
				int i = 0, p1 = 0; // i个# 
				while(line[++i] == '#'){}
				while((p1 = line.find("  ")) != -1){ // 去除空格 
					line.replace(p1, 2, " ");
				}
				line.replace(0, i, "#");
				line.replace(0, 2, "");
				line = h[i-1] + line + h[i+5];
			} else if(line[0] == '*'){ // 无序列表
				int p1 = 0;
				while((p1 = line.find("  ")) != -1){ // 去除空格 
					line.replace(p1, 2, " ");
				}
				line.replace(0, 2, ""); // 去除前两个
				line = "<li>" + line + "</li>";
			} else { // 段落
				if(!pFlag){ // 打头的p
					line = "<p>" + line;
					pFlag++;
				}
			}
		} else { // 段落结束 
			pFlag = 0;
		}
		strs[flag++] = inlineOperate(line);
	}
	uFlag = 0, pFlag = 0;
	for(int i = 0; i < flag; i++){
		if(strs[i].substr(0, 2) == "<p"){ // 段首启动
			pFlag = 1;
			for(int j = i+1; j < flag;j++){
				if(strs[j] == ""){
					strs[j-1] = strs[j-1] + "</p>";
					i = j;
					pFlag = 0;
					break;
				}
			}
		}else if(strs[i].substr(0, 2) == "<l"){ // li
			if(!uFlag){
				strs[i] = "<ul>\n" + strs[i];
				uFlag++;
			}
			for(int j = i+1; j < flag; j++){
				if(strs[j] == ""){
					strs[j-1] = strs[j-1] + "\n</ul>";
					i = j;
					uFlag = 0;
					break;
				}
			}
		}
	}
	for(int i = 0; i < flag; i++){ // 用作输出 
		if(i == flag-1){
			if(pFlag){
				strs[i] = strs[i] + "</p>";
			}else if(uFlag){
				strs[i] = strs[i] + "\n</ul>";
			}
		}
		if(strs[i] != ""){
			cout << strs[i] << endl;
		}
	}
	return 0;
} 

/*
	难点：
		怎么区分两个自然段 以及 一个自然段什么时候结束 
		if(line == ""){ // 判断空行 
			
		}
	PS: only 90 score! i can not get 100
		
# Heading

## Sub-heading

Pragragajsdl arer asdpsdpted
by a blan kienk.

Text asdfjklas _asdtr_.

Bullet list:

* asdfjkla
* asdjflk
* piajsdt

A [link](http://www.xxx.com).
*/
