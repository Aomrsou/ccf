#include<iostream>
using namespace std;
int result = 0;
int map[101][101] = {{0}};

void writeMap(int x1, int y1, int x2, int y2){
	for(int i = x1; i < x2; i++){
		for(int j = y1; j < y2; j++){
			if(!map[i][j]){
				result++;
				map[i][j] = 1;
			}
		}
	}
}

int main(){
	int n, x1, x2, y1, y2;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		writeMap(x1, y1, x2, y2);
	}
	cout << result << endl;
	return 0;
} 
