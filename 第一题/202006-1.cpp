#include<iostream>
using namespace std;

int n,m,anum = 0,bnum = 0; // n个点，m条线 
int apoint[1001][2] = {0};
int bpoint[1001][2] = {0};
int fun(int a, int b, int c){
	int num = 0;
	int r2 = 0;
	int side = 0;
	side = (a+b*apoint[0][0]+c*apoint[0][1] > 0);
	for(int i = 1; i < anum; i++){ // 判断所有a类点在同一侧 
		r2 = (a+b*apoint[i][0]+c*apoint[i][1] > 0);                            
		if(side != r2){
			return 0;
		}
	}
	side = (a+b*bpoint[0][0]+c*bpoint[0][1] > 0);
	for(int i = 1; i < bnum; i++){
		r2 = (a+b*bpoint[i][0]+c*bpoint[i][1] > 0);
		if(side != r2){
			return 0;
		}
	}
	return 1;
}

int main(){
	cin >> n >> m;
	int tempx,tempy;
	char temptype;
	for(int i = 0; i < n; i++){ // 录入点 0,1是坐标，2是类别 
		scanf("%d%d %c", &tempx, &tempy, &temptype);
		if(temptype == 'A'){ // A类 
			apoint[anum][0] = tempx;
			apoint[anum++][1] = tempy;
		} else { // B类 
			bpoint[bnum][0] = tempx;
			bpoint[bnum++][1] = tempy;
		}
	}
	int a,b,c;
	for(int i = 0; i < m; i++){ // 对m条直线判断  z = a+b*x+c*y
		cin >> a >> b >> c;
		cout << (fun(a, b, c) ? "Yes" : "No") << endl;
	}
	return 0;
}
