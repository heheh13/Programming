#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define MAX 93000
#define mod  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
ll nums[] ={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,37};
ll mul_mod(ll a, ll b,ll m){
	ll res = 0;
	a= a%m;
	while(b>0){
		if(b&1) res = (res+a)%m;
		a = (a*2)%m;
		b/=2;
	}
	return res %m;
}
ll bigmod(ll b,ll p, ll m){
	if(p ==0)return 1%m;
	if(p%2==0){
		ll x = bigmod(b,p/2,m);
		return mul_mod(x,x,m);
	}
	return mul_mod(b,bigmod(b,p-1,m),m);
}
bool miller_rabin(ll d,ll n,ll i){
	ll  a =nums[i];
	if(nums[i]>=n)return true;
	ll x = bigmod(a,d,n);
	if(x==1 || x==n-1)return true;
	while(d!=n-1){
		x = mul_mod(x,x,n)%n;
		d*=2;
		if(x == 1)return false;
		if(x == n-1)return true;
	}
	return false;
}
bool isprime(ll n){
	ll d = n-1;
	while(d%2==0)d/=2;
	for(ll i = 0;i<12;i++){
		if(!miller_rabin(d,n,i)){
			return false;
		}
	}
	return true;
}
map<ll,bool>mp;
bool suspects_miller_rabin(ll d,ll n,ll base){
	ll  a =base;
	ll x = bigmod(a,d,n);
	if(x==1 || x==n-1)return true;
	while(d!=n-1){
		x = mul_mod(x,x,n)%n;
		d*=2;
		if(x == 1)return false;
		if(x == n-1)return true;
	}
	return false;
}
bool suspects(ll base,ll n){
	ll d = n-1;
	while(d%2==0){
		d/=2;
	}
	if(suspects_miller_rabin(d,n,base))return true;
	return false;
}
int main(){
	File_IO();
	// double t1 =clock();
	// for(int i = 2;i<=1024;i++){
	// 	if(isprime(i))cout<<i<<endl;
	// }
	cout<<1000000<<endl;
	for(int i = 1;i<=1000000;i++){
		cout<<i<<endl;
	}
	// mp.clear();
	// ll base,mini, maxi;
	// cin>>base>>mini>>maxi;
	// if(mini%2==0)mini++;
	// for(ll i= max(mini,3LL) ;i<=maxi;i+=2){
	// 	if(isprime(i)){
	// 		mp[i]=1;
	// 		//cout<<i<<endl;
	// 	}
	// }
	// // 


	
	// double t2 = clock();
	// cout<<(t2-t1)/CLOCKS_PER_SEC<<endl;
	// // cout<<spct.size()<<endl;
	// // for(auto x:spct){
	// // 	cout<<x<<endl;
	// // }
}