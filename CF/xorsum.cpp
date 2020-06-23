#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
ll arr[22][22];
map<ll , ll>mp[25][25],xp[25][25];
ll n,m,k;
ll ans =0;
void bt1(ll i,ll j, ll sum){
	if(i+j>=n+2)return;
	if(i+j==n+1){
		//mp[sum^arr[i][j]]++;
		mp[i][j][sum^arr[i][j]]++;
		return ;
	}
	if(j<n)bt1(i,j+1,sum^arr[i][j]);
	if(i<n)bt1(i+1,j,sum^arr[i][j]);
}
void bt2(ll i,ll j, ll sum){
	if(i+j<n+1)return ;
	if(i+j==n+1){
		//cout<<mp[i][j][k]<<endl;
		if(mp[i][j].count(sum^k))
			ans+=mp[i][j][sum^k];
		//xp[i][j][sum^arr[i][j]]++;
		return ;
	}
	if(j>0)bt2(i,j-1,sum^arr[i][j]);
	if(i>0)bt2(i-1,j,sum^arr[i][j]);
}
int main(){
	File_IO();
	optimizar;
	//ll n,m,k;
	cin>>n>>m>>k;
	for(ll i = 1; i<=n; i++){
		for(ll j =1; j<=m; j++){
			cin>> arr[i][j];
		}
	}
	bt1(1,1,0);
	bt2(n,m,0);
	cout<<ans<<endl;
	ll i = 0,j=0,k=0;
	//cout<<mp[i][j][k]<<endl;
}