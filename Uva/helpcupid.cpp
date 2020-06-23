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
typedef unsigned long long ull;
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
int main(){
	optimizar;
	File_IO();
	int n;
	while(cin>>n){
		int arr[n];
		for(int i = 0;i<n;i++)cin>>arr[i];
		sort(arr,arr+n);
		int t1=0 , t2=0 ;
		for(int i = 0;i<n;i+=2){
			int a = abs(arr[i]-arr[i+1]);
			int b = 24-a;
			t1+=min(a,b);
		}
		for(int i = 1;i<=n;i+=2){
			int a = abs(arr[i]-arr[(i+1)%n]);
			int b = 24-a;
			t2+=min(a,b);
		}
		cout<<min(t1,t2)<<endl;
	}
}