#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n, l, t, temp, direction = 0, ball = 1, index = 0;
	cin >> n >> l >> t;
	int result[n] = {0};
	int position[n] = {0};
	int tmp[n] = {0}; // 正确的相对位置 
	for(int i = 0; i < n; i++){
		cin >> position[i];
	}
	for(int i = 0; i < n; i++){ // 计算每个球最后处于哪个位置（乱序） 
		temp = position[i];
		direction = (temp + t) / l;
		temp = (temp + t) % l;
		if(direction & 1){ // 奇数则 从右往左  
			temp = l - temp;
		} else { // 偶数则 从左往右 （默认即是如此 写这句方便理解 
			
		} 
		result[i] = temp;
	}
	int min = 1001, minIndex = 0;
	for(int i = 0; i < n; i++){ // 对球所处的相对位置做排序 如初始化球号 3 2 1 则输出的时候要按1 2 3对应的位置 
		for(int j = 0; j < n; j++){
			if(position[j] < min){
				min = position[j];
				minIndex = j;
			}
		}
		tmp[i] = minIndex;
		min = 1001;
		position[minIndex] = 1001;
	}
	sort(result, result + n); // 排序它 
	
	for(int i = 0; i < n; i++){ // 对应输出即为所求 
		for(int j = 0; j < n; j++){
			if(tmp[j] == i){
				cout<< result[j] << " ";
				break;
			}
		}
	}
	return 0;
} 

/*
	核心思想：
		计算每颗球最后的位置（算完为乱序，因为假设他们相遇后不相撞 而是擦肩而过
		记录初始位置
		根据初始相对位置 看下边吧 我说不明白 嘴瓢了 _(:з」∠)_ 
		 https://blog.csdn.net/SongBai1997/article/details/81175312
*/

