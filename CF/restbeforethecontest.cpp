#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 505
#define inf 1e15
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
ll n,m,r;
ll arr[mx];
ll dp[mx][60][60];
ll bt(ll pos, ll cur, ll taken){
	if(pos>=n){
		if(taken )return -inf;
		return 0;
	}
	if(dp[pos][cur][taken]!=-1)return dp[pos][cur][taken];
	ll res = -inf;
	if(cur<r && taken)
	res = (cur+1)*arr[pos] + bt(pos+1,cur+1,taken-1);
	res = max(res,bt(pos+1,0,taken));
	return dp[pos][cur][taken]=res;
}
int  main(){
	File_IO();
	cin>>n>>m>>r;
	for(ll i = 0;i<n;i++)cin>>arr[i];
	memset(dp,-1,sizeof(dp));
	ll ans = bt(0,0,m);
	if(ans<0){
		cout<<"-1"<<endl;
	}
	else cout<<ans<<endl;
}