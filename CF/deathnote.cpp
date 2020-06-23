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
int arr[mx];
int main(){
	File_IO();
	int n,m,q;
	cin>>n>>m>>q;
	string line,hell;
	cin>>line>>hell;
	for(int i = 0;i<=n-m;i++){
		bool flag = 1;
		int x = 0;
		for(int j = i;j<min(i+m,n);j++,x++){
			if(line[j]!=hell[x]){
				flag = false;
				break;
			}
		}
		if(flag)arr[i+1]=1;
	}
	for(int i = 1;i<=n;i++){
		arr[i]+=arr[i-1];
		//cout<<arr[i]<<" " ;
	}

	while(q--){
		int a,b;
		cin>>a>>b;
		int high = arr[b+1-m];
		int low = arr[a-1];
		if(b-a+1<m) printf("0\n");
		else if(high-low>=0)cout<<high-low<<endl;
		//else cout<<"0"<<endl;
	}
}