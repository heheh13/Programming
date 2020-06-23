#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
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
	int n,d;
	cin>>n>>d;
	int arr[n+2];
	map<int,int>val;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		val[arr[i]]=1;
	}
	map<int,int>mp;
	arr[0]=INT_MIN;
	arr[n+1]=INT_MAX;
	for(int i = 1;i<=n;i++){
		int a= arr[i]+d;
		int b = arr[i]-d;
		if(a+d<=arr[i+1])mp[a]=1;
		if(b-d>=arr[i-1])mp[b]=1;
	}
	int cnt  = 0;
	for(auto x:mp){
		if(val[x.first])cnt++;

	}
	cout<<mp.size()-cnt<<endl;

}
