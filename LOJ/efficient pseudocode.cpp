#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 61722
#define SZ 3
#define sc(a) scanf("%lld",&a)
#define mod 1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
bitset<mx>check;
std::vector<ll> prime;
void sieve(){
	for(ll i = 3;i*i<=mx;i+=2){
		if(!check[i]){
			for(ll j = i*i ; j<mx;j+=2*i){
				check[j]=1;
			}
		}
	}
	prime.push_back(2);
	for(ll i = 3;i<mx;i+=2)if(!check[i])prime.push_back(i);
}
ll bigmod(ll b , ll p){
	if(p==0)return 1%mod;
	if(p&1)return (b%mod*bigmod(b,p-1)%mod)%mod;
	else{
		ll x = bigmod(b,p/2)%mod;
		return (x%mod*x%mod)%mod;
	}
}
ll factorize(ll n,ll m){
	ll sod = 1;
	ll sqr = sqrt(n);
	for(ll i = 0;prime[i]<=sqr;i++){
		if(n%prime[i]==0){
			ll cnt=0;
			while(n%prime[i]==0){
				n/=prime[i];
				cnt++;
			}
			

			sod = ((sod%mod) * ((bigmod(prime[i],cnt*m+1)-1)%mod))%mod*( bigmod(prime[i]-1,mod-2)%mod);
			sod%=mod;
		}
	}
	if(n!=1){

		sod = (sod * (bigmod(n,m+1)-1)) %mod*bigmod(n-1,mod-2);
		sod%=mod;
	}
	return sod;
}
int main(){
	File_IO();
	ll t;
	scanf("%lld",&t);
	sieve();
	///cout<<prime[prime.size()-1]*prime[prime.size()-1]-2e9<<endl;
	for(ll ts = 1;ts<=t;ts++){
		ll n,m;
		scanf("%lld %lld",&n,&m);
		printf("Case %lld: %lld\n",ts,(factorize(n,m)+mod)%mod);
	}
}