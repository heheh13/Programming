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
int n,m;
int arr[101];
long long dp[101][1<<11][10];
string bin(int num){
	string res;
	while(num){
		res+=num%2+'0';
		num/=2;
	}
	reverse(res.begin(),res.end());
	//cout<<res<<endl;
	return res;
}
int bt(int pos , int mask,int lst){
	//dbg(pos,bin(mask));
	if(pos>=m){
		
		
		if(mask==(1<<n)-1){
			return 1;
		}
		return 0;
	}
	if(~dp[pos][mask][lst]){
		return dp[pos][mask][lst];
	}
	long long  ans = (mask==(1<<n)-1);

	for(int i = 0;i<n;i++){
		if(abs(lst-i)==1){
			ans+=bt(pos+1,mask|(1<<i),i);
			ans%=mod;
		}
	}
	return dp[pos][mask][lst]=ans%mod;
}
int main(){
	File_IO();
	optimizar;
	int ts ;
	
	cin>>ts;
	while(ts--){

		cin>>n>>m;
		ll ans = 0;
		memset(dp,-1,sizeof(dp));
		for(int i = 1;i<n;i++){
			memset(dp,-1,sizeof(dp));	
			ans+=bt(1,1<<i,i)%mod;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	
}