
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
int arr[32];
int main(){
	File_IO();
	int n,q;
	cin>>n>>q;
	for(int i = 0;i<n;i++){
		int temp;
		cin>>temp;
		int d = log2(temp);
		arr[d]++;
	}
	while(q--){
		int val;
		cin>>val;
		int cnt = 0;
		for(int i = 30;i>=0;i--){
			int temp= pow(2,i);
			if(temp<=val&& arr[i]>0){
				int div = val /temp;
				val-=min(div,arr[i])*temp;
				cnt+=min(div,arr[i]);
			}
		}
		if(val==0)cout<<cnt<<endl;
		else cout<<"-1"<<endl;
	}
}