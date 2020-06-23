#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define MAX 65555
#define mod  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
ll nums[] ={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,37};
bool check[MAX];
std::vector<ll > prime;
void seive(){
	for(ll i = 3;i*i<=MAX;i+=2){
		if(!check[i]){
			for(ll j = i*i ;j<MAX;j +=2*i){
				check[j]=1;
			}
		}
	}
	prime.push_back(2);
	for(ll i = 3;i<MAX;i+=2){
		if(!check[i])prime.push_back(i);
	}
}

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
bool status[100500];
int  segment_seive(ll l, ll r){
	
	memset(status,1,sizeof(status));
	for(ll i = 0;prime[i]*prime[i]<=r;i++){
		ll base = (l/prime[i])*prime[i];
		if(base<l)base+=prime[i];
		for(ll j = base; j<=r ;j+=prime[i]){
			status[j-l]=false;
		}
		if(base == prime[i])status[base-l]=true;
	}
	ll cnt = 0;
	for(ll i = 0;i<r-l+1;i++){
		if(status[i]){
			//mp[i+l]=true;
			continue;
		}
		if(!status[i]&&(l+i)&1)cnt++;
	}
	return cnt;
}
int main(){
	File_IO();
	seive();
	ll base,mini, maxi;
	bool newline = false;
	while(scanf("%lld %lld %lld",&base,&mini,&maxi) && mini+maxi+base){
		if(mini>maxi)swap(mini,maxi);
		if(newline)printf("\n");
		newline = true;
		ll ans = segment_seive(mini,maxi);
		printf("There are %lld odd non-prime numbers between %lld and %lld.\n",ans,mini,maxi);
		ll ck = mini;
		if(mini%2==0)mini++;
		std::vector<ll> spct;
		for(ll i = mini;i<=maxi;i+=2){
			if(status[i-ck])continue;
			if(suspects(base,i)&&!status[i-ck]){
				spct.push_back(i);
			}
		}
		if(spct.size()){

			printf("%lld suspects fail in base %lld:\n",(ll)spct.size(),base);
			for(auto x :spct)
				printf("%lld\n",x);
		}
		else{
			printf("There are no failures in base %lld.\n",base);
		}
		
	}
}