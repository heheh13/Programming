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
bitset<mx>check;
std::vector<ll> prime,divisors;
std::vector<pair<ll,ll> > factor;
void seive(){
	ll sqr =sqrt(mx);
	for(ll i = 4;i<mx;i+=2)check[i]=1;
	for(ll i = 3;i<=sqr;i+=2){
		if(!check[i]){
			for(ll j = i*i;j<=mx;j+=2*i)check[j]=1;
		}
	}
	prime.push_back(2);
	for(ll i = 3;i<mx;i+=2)if(!check[i])prime.push_back(i);
}
void factorize(ll n){
	ll sqr = sqrt(n);
	for(ll i = 0;prime[i]<=sqr;i++){
		if(n%prime[i]==0){
			ll cnt =0;
			while(n%prime[i]==0){
				n/=prime[i];
				cnt++;
			}
			factor.push_back({prime[i],cnt});
			//sqr=sqrt(n);
		}
	}
	if(n!=1){
		factor.push_back({n,1});
	}
}
void gen(ll pos,ll n){
	if(pos==factor.size()){
		divisors.push_back(n);
		return;
	}
	ll temp = 1;
	for(ll i = 0;i<=factor[pos].second;i++){
		gen(pos+1,n*temp);
		temp*=factor[pos].first;
	}
}
map<ll,ll>mp;
int main(){
	File_IO();
	seive();
	ll n;
	cin>>n;
	factorize(n);
	gen(0,1);
	ll arr[n];
	for(ll i = 0;i<n;i++){
		cin>>arr[i];
	}
	sort(divisors.begin(),divisors.end());
	
	for(auto x:divisors){
		if(x==1) continue;
		for(ll i = 0;i<n;i++){
			mp[arr[i]%x]++;
		}
		bool flag = true;
		int cnt =0;
		for(auto p:mp){
			if(p.second > n/x)flag = false;
			if(p.first<x)cnt++;
		}
		if(flag && cnt==x){
			cout<<x<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}