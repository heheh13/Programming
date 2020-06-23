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
int main(){
	File_IO();
	ll n,t;
	cin>>n>>t;
	ll arr[n],brr[n],x[n];
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		brr[i]=arr[i]+t;
	}
	for(int i =1;i<=n;i++)cin>>x[i];
	ll ans [n];
    ans[1]=brr[x[1]];
	for(int i = 2;i<=n;i++){
		if(brr[x[i]]<=ans[i-1]){
			cout<<"No"<<endl;
			return 0;
		}
		else {
			ans[i]=max(brr[x[i]],ans[i-1]+1);
		}
	}
	cout<<"Yes"<<endl;
	for(int i = 1;i<=n;i++)
		cout<<ans[i]<<" ";
}