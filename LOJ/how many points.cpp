#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 46341
#define mod  1000000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
#define MAXN 100005
typedef long long ll;
int main(){
	File_IO();
	int t;
	sc1(t);
	for(int ts = 1;ts<=t ;ts++){
		long long  x1, x2,y1,y2;
		sc2(x1,y1);
		sc2(x2,y2);
		long long  ans  = __gcd(abs(x1-x2),abs(y1-y2))+1;
		printf("Case %d: %lld\n",ts,ans );
	}
}