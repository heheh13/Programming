#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100001000
#define mod  1000
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll bigmod(ll base, ll power){
	if(power==1)return base%mod;
	if(power&1)return base * bigmod(base,power-1)%mod;
	else {
		ll x = bigmod(base,power/2);
		return ((x %mod)*( x %mod))%mod;
	}
}
int main(){
	optimizar;
	File_IO();
	int t;
	cin>>t;
	for(int ts = 1;ts<=t;ts++){

		ll n,k;
		cin>>n>>k;
		double num = k* log10(n);
		ll nx = num;
		num-=nx;
		ll ans = pow(10,num)*100;
		ll hell = bigmod(n,k);
		string line;
		if(hell<100)line+="0";
		if (hell<10) line+="0";
		cout<<"Case "<<ts<<": "<<ans<<" "<<line<<hell<<endl;

	}
	


}