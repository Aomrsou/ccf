#include<iostream>
#include<cstring>
using namespace std;

typedef long long L;

L dp[1005][6];
const L MOD = 1000000007;

int main() {
	int n;
	cin >> n;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][3] = (dp[i - 1][1] + dp[i - 1][3] * 2) % MOD;
		dp[i][4] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] * 2) % MOD;
		dp[i][5] = (dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5] * 2) % MOD;
	}
	cout << dp[n][5] << endl;
	return 0;
}
/*
	核心思路:
		是我不擅长的dp了，一共六种状态 
		ps:0在1前,2在3前,0不能打头 
		综上:必然是2打头，从全是2开始
			一直往后面<b>追加<b>字符，可追加两种的就x*2，否则就+x 
		直接dp就好 
		s0: 只有2
		s1: 只有2 0  s0 + "0" || s1 + "0" || s1 + "2"
		s2: 只有2 3  s0 + "3" || s2 + "3"
		s3: 只有2 0 1  s1 + "1" || s3 + "2" || s3 + "1"
		s4: 只有2 0 3  s1 + "3" || s2 + "0" || s4 + "0" || s4 + "3"
		s5: 任意数字   s3 + "3" || s4 + "1" || s5 + "1" || s5 + "3"
*/

