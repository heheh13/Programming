#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 7000005
#define mod  998244353
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
	bool mark[mx];
typedef long long int ll;
int main(){
	File_IO();
	int n;
	cin>>n;
	int arr[n];
	memset(mark,0,sizeof(mark));
	arr[0]=3;
	mark[3]=1;
	int x = 3;
	
	for(int i = 1;i<=n;i++){
		while(mark[x]){
			x+=2;
		}
		arr[i]=x;
		int sum = 0;
		for(int j = i;j>=0;j--){
			sum+=arr[j];
			mark[sum]=true;
		}
		//cout<<sum<<endl;
	}
	for(int i = 0;i<n;i++)cout<<arr[i]<<" ";
}