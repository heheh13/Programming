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
ll f(ll n){
	return (n*(n+1))/2;
}
int  main(){
	File_IO();
	ll n,m;
	cin>>n>>m;
	ll arr[n];
	for(ll i = 0; i<n ; i++)cin>>arr[i];
	sort(arr,arr+n);
	ll left = 0;
	ll sum = 0;
	for(ll i = 0;i<n;i++){
		if(m==0)break;
		ll dur = arr[i]-left-1;
		if(dur>0){
			ll dif = min(m,dur);
			m-=dif;
			ll a= f(left+dif);
			ll b = f(left);
			sum+=a-b;
			left = arr[i];
		}
		else left = arr[i];

	}
	if(m>0){
		sum+= f(left+m)-f(left);
	}
	cout<<sum<<endl;
}