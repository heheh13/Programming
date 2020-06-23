#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100000
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int main(){
	File_IO();
	int t;
	cin>>t;
	for(int ts = 1;ts<=t;ts++){
		ll e,p,k,r;
		cin>>e>>p>>k>>r;
		ll ans = 0;
		if(e<=p*k){
			ans = (e+p-1)/p;
		}
		else{
			ll x = p*k;
			ll dif = x-r;
			if(dif<=0 ||r>x)
				ans=-1;
			else{
				ll need = (e-x+dif-1)/dif;
				ans += need*k+(e-dif*need+p-1)/p;
			}
		}
		printf("Case %d: %lld\n",ts,ans );
	}

}