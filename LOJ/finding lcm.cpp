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
typedef unsigned long long ull;
ll lcm(ll a, ll b){
	return (a*b)/ __gcd(a,b);
}
int main(){
	File_IO();
	int t;
	cin>>t;
	for(int ts = 1; ts<= t;ts++){
		ll a, b, l;
		cin>>a>>b>>l;
		ll ret = (a*b) / __gcd(a,b);
		
		cout<<"Case "<<ts<<": ";
		if(l%ret==0){
			ll seed = l/ret;
			ll now = seed;
			ll L = lcm(ret,now);
			int x = 1;
			while(1){
				//cout<<now<<endl;
				if(L == l){
					cout<<now<<endl;
					break;
				}
				now  =seed *x++;
				L = lcm(ret,now);
			}
		}
		else cout<<"impossible"<<endl;
		
	}
}