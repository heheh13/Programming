#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100000
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int  main(){
	File_IO();
	optimizar;
	ll n;
	cin>>n;
	ll arr[n];
	map<ll,ll>mp;
	for(ll i = 0;i<n;i++){
		cin>>arr[i];
		mp[arr[i]]++;
	}
	ll ans = 0;
	map<ll,ll>used;

	for(ll i = 0;i<n;i++){
		mp[arr[i]]--;
		if(mp[arr[i]]==0){
			mp.erase(arr[i]);
		}
		if(!used[arr[i]])ans+=mp.size();
		used[arr[i]]=1;
	}
	cout<<ans;
}