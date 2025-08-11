#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N;
	int arr[301];
	int dp[301];
	
	cin >>N;
	
	for(int i=1;i<=N;i++){
		int tmp;
		cin >> tmp;
		arr[i]=tmp;
	}
	
	dp[1]=arr[1];
	dp[2]=arr[1]+arr[2];
	dp[3]=max(arr[1]+arr[3],arr[2]+arr[3]);
	
	for(int i=4;i<=N;i++){
		dp[i]=max(dp[i-2]+arr[i],
					dp[i-3]+arr[i-1]+arr[i]);
	}
	cout << dp[N] <<"\n";
}