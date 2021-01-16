#include<iostream>
using namespace std;
int map[2560][1440] = {{0}};
int window[11][4] = {{0}};

void writeMap(int *index, int num){ 
	for(int i = index[0]; i <= index[2]; i++){
		for(int j = index[1]; j <= index[3]; j++){
			map[i][j] = num;
		}
	}
}

int main(){
	int n, m, windowNum = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){ // input windows 
		for(int j = 0; j < 4; j++){
			cin >> window[windowNum][j]; 
		}
		writeMap(window[windowNum], i); // initial windows 
		windowNum++;
	}
	int x, y, point;
	for(int j = 0; j < m; j++){ // µã»÷Î»ÖÃ 
		cin >> x >> y;
		if(map[x][y]){
			point = map[x][y];
			cout << point << endl;
			writeMap(window[point], point);
		} else {
			cout << "IGNORED" << endl;
		}
	}
	return 0;
} 
