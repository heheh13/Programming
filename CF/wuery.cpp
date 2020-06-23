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
ll dp[20][2][4];
std::vector<ll> arr;
ll bt(ll pos,bool small,ll cnt){
	if(cnt>3)return 0;
	if(pos>=arr.size()){
		if(cnt<=3)return 1;
		return 0;
	}
	ll sesh = small ? 9 : arr[pos];
	if(dp[pos][small][cnt]!=-1)return dp[pos][small][cnt];
	ll ans = 0;
	for(ll i =0;i<=sesh;i++){
		/*mask[pos]=i;*/
		ans +=bt(pos+1,small | i<arr[pos],cnt+(i!=0));
	}
	return dp[pos][small][cnt]=ans;
}
int  main(){
	File_IO();
	int t;
	cin>>t;
	while(t--){

		ll a,b;
		cin>>a>>b;
		arr.clear();
		while(b){
			arr.push_back(b%10);
			b/=10;
		}
		memset(dp,-1,sizeof(dp));
		reverse(arr.begin(),arr.end());
		ll ans = bt(0,0,0);
		//cout<<ans<<endl;
		arr.clear();
		a--;
		while(a){
			arr.push_back(a%10);
			a/=10;
		}
		reverse(arr.begin(),arr.end());
		memset(dp,-1,sizeof(dp));
		ll res = bt(0,0,0);
		//cout<<res<<endl;
		cout<<ans-res<<endl;
	}
}