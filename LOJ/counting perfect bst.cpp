#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 5000
#define mod  100000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll cat[mx];
ll catalan(ll n){
	
	if(n<=1)return cat[n]=1;

	ll res = 0;
	//debug(n);
	if(cat[n]!=-1)return cat[n];
	for(ll i = 0;i<n;i++)
		res += ((catalan(i)%mod)*(catalan(n-i-1)%mod))%mod;
	//cout<<res<<endl;
	return cat[n]=res%mod;
}
ll power(ll base,ll p){
	ll sum = 1;
	for(ll i = 0;i<p;i++)sum*=base;
	return sum;
}
std::vector<ll> v;
int  main(){
	optimizar;
	File_IO();
	memset(cat,-1,sizeof(cat));
	for(ll i = 2;i<=sqrt(1e10+10);i++){

		for(ll j = 2;;j++){
			ll temp = power(i,j);
			if(temp>1e10)break;
			v.push_back(temp);
		}
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	catalan(1500);
	cat[0]=0;
	ll t;
	cin>>t;
	for(ll ts = 1;ts<=t;ts++){
		ll a,b;
		cin>>a>>b;
		ll temp = upper_bound(v.begin(),v.end(),b)-upper_bound(v.begin(),v.end(),a-1);
		cout<<"Case "<<ts<<": "<<cat[temp]<<endl;
	}
}