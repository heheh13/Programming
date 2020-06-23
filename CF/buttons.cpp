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
long long arr[20010];
int  main(){
	File_IO();
	ll n;
	cin>>n;
	ll sum  = 0;
	ll i = 1;
	ll save=((n-1) *(n))/2;
	while(n){
		sum+=n*i;
		n--,i++;
	}
	//debug(save);
	cout<<sum-save<<endl;
}