#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 2005
#define mod  998244353
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;

std::map<ll, bool> mp;
ll fun(ll n, ll num){
	std::vector<ll> line;
	while(num){
		line.push_back(num%10);
		num/=10;
	}
	ll help = 0;
	ll len = line.size();

	for(ll i = len-1 ; i>=max(0LL,len-n);i--){
		help = help *10 + line[i];
	}
	
	return help;
}
int  main(){
	File_IO();
	ll t;
	cin>>t;
	while(t--){
		mp.clear();
		ll n , num;
		cin>>n>>num;
		ll maxi = fun(n,num);
		mp[maxi]=true;
		for(ll i = 0;;i++){
			ll help = fun(n,num*num);
			if(mp[help])break;
			mp[help]=true;
			num = help;
			maxi = max(maxi,help);
		}
		cout<<maxi<<endl;
	}
}