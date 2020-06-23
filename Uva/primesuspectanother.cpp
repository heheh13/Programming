#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1000006
#define mod  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
//typedef long long ll;
typedef unsigned long long ll;
// ll mul_mod(ll a, ll b,ll m){
// 	ll res = 0;
// 	a= a%m;
// 	while(b>0){
// 		if(b&1) res = (res+a)%m;
// 		a = (a*2)%m;
// 		b/=2;
// 	}
// 	return res %m;
// }
ll bigmod(ll b,ll p, ll m){
	if(p ==0)return 1%m;
	if(p%2==0){
		ll x = bigmod(b,p/2,m);
		return (x*x)%m;
	}
	return b*bigmod(b,p-1,m)%m;
}
bool suspects_miller_rabin(ll d,ll n,ll base){
	ll  a =base;
	ll x = bigmod(a,d,n);
	if(x==1 || x==n-1)return true;
	while(d!=n-1){
		x = bigmod(x,2,n)%n;
		d*=2;
		if(x == 1)return false;
		if(x == n-1)return true;
	}
	return false;
}
bool suspects(ll base,ll n){
	//if(base>=n)return true;
	ll d = n-1;
	while(d%2==0){
		d/=2;
	}
	if(suspects_miller_rabin(d,n,base))return true;
	return false;
}
int main(){
	File_IO();
	ll base,low , up;
	bool first = false;
	double t1 = clock();
	while(scanf("%llu %llu %llu",&base,&low,&up) && base+low+up){
		if(first)printf("\n");
		first = true;
		ll temp = low;
		if(low%2==0)temp++;
		int cnt = 0;
		std::vector<ll> spct;
		for(ll i = temp;i<=up;i+=2){
			if(i == 2 || i == 7 || i==61) continue;
			if(suspects(2,i) && suspects(7,i) && suspects(61,i)){
				//prime
				continue;
			}
			else if(suspects(base,i)){
				spct.push_back(i);
				cnt++;
			}
			else cnt++;
		}
		printf("There are %d odd non-prime numbers between %llu and %llu.\n",cnt,low,up);
		if(spct.size()>0){
			printf("%d suspects fail in base %llu:\n",spct.size(),base);
			for(auto x:spct)printf("%llu\n",x);			
		}
		else{
			printf("There are no failures in base %llu.\n",base);
		}
	}
	double t2 = clock();
	// cout<<(t2-t1)/CLOCKS_PER_SEC;
}