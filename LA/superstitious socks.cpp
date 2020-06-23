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
ll arr[mx];
std::vector<pair<ll, pair<ll,ll> > > v;
int main(){
	File_IO();
	optimizar;
	ll n,m;
	while(cin>>n>>m){
		if(n==0 && m==0)return 0;
		
		for(ll i = 0;i<n;i++)cin>>arr[i];
		sort(arr,arr+n);
		ll  t  = n*n;
		//cout<<t<<endl;
		ll bal;
		if(t>2e6)bal = (2000000/n);
		else bal = n;
		//cout<<bal<<endl;
		for(ll j = 1;j<=min(n,bal);j++){
			for(ll i = 0;i<n-j;i++){
				ll val = abs(arr[i]-arr[i+j]);
				v.push_back({val,{arr[i],arr[i+j]}});
				//cout<<arr[i]<<" "<<arr[j+i];
			}
		}
		sort(v.begin(),v.end());
		//cout<<v.size()<<endl;
		/*for(auto x:v){
			cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
		}*/
		//prllf("%d %d\n",v[m-1].second.first,v[m-1].second.second);
		/*if(m>v.size()){
			return 0;
		}*/
		cout<<v[m-1].second.first<<" "<<v[m-1].second.second<<endl;
		v.clear();
	}
}