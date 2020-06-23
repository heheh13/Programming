#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 44721
#define mod  998244353
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int main(){
	File_IO();
	int n;
	cin>>n;
	int arr[n],brr[n],crr[n],drr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++)cin>>brr[i],crr[i]=drr[i]=arr[i]-brr[i];
	sort(crr,crr+n);
	if(n==1000 && arr[0]==1000000000)
		for(int i = 0;i<100;i++)cout<<crr[i]<<" ";
	int cnt = 0;
	for(int i = 0;i<n;i++){
		int val = abs(crr[i])+1;
		int low = lower_bound(crr,crr+n,val)-crr;
		cout<<low<<endl;
		cnt+=max(0,n-low);
	}
	cout<<cnt<<endl;


}