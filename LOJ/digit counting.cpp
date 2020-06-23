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
int arr[11];
int mask[11];
int n,m;
int bt(int n,int prev){
	if(n==0)return 1;
	int sum = 0;
	for(int i = 0;i<m;i++){
		if(abs(arr[i]-prev)<=2){
			sum+=bt(n-1,arr[i]);
		}
	}
	return sum;
}
int  main(){
	File_IO();
	cin>>m>>n;
	for(int i=0;i<m;i++)cin>>arr[i];
	int sum = 0;
	for(int i = 0;i<m;i++){
		sum+=bt(n-1,arr[i]);
	}
}