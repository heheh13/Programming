#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 46341
#define mod  1000003
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
ll mod_inverse(ll base, ll power){
	if(power==0)return 1%mod;
	if(power%2==0){
		long long  x = mod_inverse(base,power/2)%mod;
		return (x%mod*x%mod)%mod;
	}
	return (base %mod * mod_inverse(base,power-1)%mod)%mod;
}
ll bigmod(ll b , ll p){
	if(p==0)return 1%mod;
	if(p&1)return (b%mod*bigmod(b,p-1)%mod)%mod;
	else{
		ll x = bigmod(b,p/2)%mod;
		return (x%mod*x%mod)%mod;
	}
}

int fact[1000006];
int main(){
	File_IO();
	ll temp;
	fact[0]=1;
	for(int i = 1;i<1000006;i++)temp=((ll)fact[i-1]*i)%mod , fact[i]=temp;
	int t;
	sc1(t);
	for(int ts = 1;ts<=t;ts++){
		int n, r;
		sc2(n,r);
		ll up = fact[n];

		ll dw  = ((ll)fact[r]*(ll)fact[n-r]);
		ll ans = (fact[n] * mod_inverse(dw,mod-2) )%mod;
		printf("Case %d: %lld\n",ts,ans );

	}

}