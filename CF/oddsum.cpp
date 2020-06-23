#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int   main(){
	File_IO();
	ll n;
	cin>>n;
	ll even_sum=0,odd_sum=0;
	std::vector<ll> odd,negodd;
	ll temp;
	for(ll i = 0;i<n;i++){
		cin>>temp;
		if(temp%2==0 && temp>0)even_sum+=temp;
		if(temp&1 && temp>0){
			odd_sum+=temp;
			odd.push_back(temp);
		}
		if(temp&1 && temp<0)negodd.push_back(temp);
	}
	sort(odd.begin(),odd.end());
	sort(negodd.rbegin(),negodd.rend());
	ll sum = even_sum+odd_sum;
	if(sum&1){
		cout<<sum<<endl;
		return 0;
	}
	else {
		///sum = even 
		ll a = 0,b=0;
		if(negodd.size()){
			a=negodd[0];
		}
		if(odd.size())b=odd[0];
		ll s1 = sum+a;
		ll s2 = sum-b;
		if(s1&1 && s2&1){
			cout<<max(s1,s2)<<endl;
		}
		else if(s1&1)cout<<s1<<endl;
		else cout<<s2<<endl;
	}
}