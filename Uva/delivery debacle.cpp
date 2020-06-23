#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100001000
#define mod  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
#define MAXN 100005
typedef long long ll;


ll dp[41];
ll calc(int n){
	for(int i  = 3;i<=n;i++){
		dp[i]=2* (dp[i-1]+dp[i-2])+ 2*(dp[i-2]+dp[i-3]) - dp[i-1];
	}
	return 0;
}
int main(){
	 File_IO();
	 optimizar;
	int t;
	cin>>t;
	dp[0]=1;
	dp[1]=1;
	dp[2]=5;
	calc(40);
	while(t--){
		int  n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
	///for(int i = 0;i<30;i++)cout<<dp[i]<<endl;
}