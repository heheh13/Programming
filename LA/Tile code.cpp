#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 200005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll dp[100];
int calc(int n){
	if(dp[n]!=-1)return dp[n];
	return dp[n]= calc(n-1)+2*calc(n-2);
}
int main(){
	File_IO();
	memset(dp,-1, sizeof(dp));
	dp[0]=1;
	dp[1]=1;
	int n;
	while(cin>>n){
		cout<<calc(n)+calc(n/2)/2<<endl;
	}
}