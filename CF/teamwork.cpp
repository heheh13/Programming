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
ll ncr(ll n,ll r){
	ll x=max(n-r,r);
	ll y = min(r,n-r);
	ll p=1;
	ll sum = 1;
	for(ll i = x+1;i<=n;i++){
		sum*=i;
		if(p<=y){
			sum/=p;
			p++;
		}
	}
	return sum;
}
int main(){
	File_IO();
	ll n;
	cin>>n;
	ll sum =0;
	for(ll i =2;i<=n;i++){
		sum+=ncr(n,i);
	}
	cout<<sum<<endl;
}
