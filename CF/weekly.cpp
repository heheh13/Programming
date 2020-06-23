#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100005
#define mod  998244353
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int arr[mx];
int  main(){
	File_IO();
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	int i = 0,j = n-1;
	int maxi =0;
	bool flag = true;
	while(i<j){
		//cout<<arr[i]<<" "<<arr[j]<<endl;
		if(arr[i]!=arr[j])flag = false;
		if(arr[i]==arr[j])maxi = max(0,maxi);
		else maxi = __gcd(maxi,abs(arr[i]-arr[j]));
		
		i++,j--;
	}
	if(flag)cout<<"-1"<<endl;
	else
	cout<<maxi<<endl;
}