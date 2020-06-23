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
typedef long long ll;
typedef unsigned long long ull;
int main(){
	File_IO();
	ll n;
	ll fib[41];
	fib[1]=1;
	fib[2]=1;
	for(int i = 3;i<40;i++){
		fib[i]=fib[i-1] + fib[i-2];
	}
	ll a,b;
	ll median[41];
	a = 0,b = 0;
	cin>>n;
	a = 2, b = 3;
	median[0]=3
	for(int i = 4;i<=n;i++){
		a =b+1;
		b = a+fib[i]-1;
		median[i]=(a+b)/2;
		debug(median[i]);

	}
}