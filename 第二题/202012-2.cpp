#include<iostream>
#include<algorithm>
using namespace std;
int m, errors = 0, rights = 0, allError = 0, allRight = 0;
typedef struct {
	long long y;
	int result;
}Data;

bool cmp(Data a, Data b){
	return a.y < b.y;
}

int main(){
	cin >> m;
	Data *data = (Data *)malloc(sizeof(Data) * m);
	Data *dataSum = (Data *)malloc(sizeof(Data) * m);
	for(int i = 0; i < m; i++){
		cin >> data[i].y >> data[i].result;
		dataSum[i].y = data[i].y;
	}
	sort(data, data + m, cmp);
	sort(dataSum, dataSum + m, cmp);
	
	dataSum[0].result = 0;
	allError = data[0].result ? 0 : 1;
	
	for(int i = 1; i < m; i++){ // 统计i元素之前 有多少个挂科
		if(dataSum[i].y != dataSum[i-1].y){
			errors = allError;
		}
		dataSum[i].result = errors;
		if(!data[i].result){ // 挂科
			allError++;
		}
	}
	allRight = data[m - 1].result ? 1 : 0;
	dataSum[m - 1].result += allRight;
	
	for(int i = m - 2; i >= 0; i--){ // 统计i元素之后 有多少个不挂科
		if(data[i].result){ // 不挂科
			allRight++;
		}
		if(dataSum[i].y != dataSum[i+1].y){
			rights = allRight;
		}
		dataSum[i].result += rights;
	}
	int index = 0;
	long long value = 0;
	for(int i = 0; i < m; i++){ // 找到得分最高的数 最后输出 
		if(dataSum[i].result >= index){
			index = dataSum[i].result;
			value = dataSum[i].y;
		}
	}
	cout << value << endl;
	return 0;
}


/*
	絮絮叨叨：
		这题可太牛逼了，暴力只能得70分
		玥宝应该在拿到70分之后再来看如何拿100分 
	核心思想：
		后30分只能用“前缀和”思想来解决，此处先百度“前缀和”
		录入数据后，新开一个 dataSum数组，用来存每个阈值 以及该阈值对应的正确个数
		即 有多少个阈值小于它且挂科，大于等于它且不挂科，我用了两个for循环分别统计这两个数字之和
		然后遍历一遍找到正确数最多的阈值，输出之，总的来说不算难，但是暴力解决不了问题了已经 
*/
