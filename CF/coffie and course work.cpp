#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 200005
#define mod  1000
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
typedef long long ll;
using namespace std;
int arr[mx];
ll n,m;

int f(int mid){
	ll s[mid+1];
	memset(s,0,sizeof(s));
	int t = 0;
	for(int i =1;i<=n;i++){
		s[1+(i-1)%mid]+=max(0,arr[i]-t);
		if(i%mid==0)t++;
		///cout<<t<<" "<<arr[i]<<endl;
	}
	//cout<<endl;
	ll sum = 0;
	for(int i = 1;i<=mid;i++)sum+=s[i];
	return (sum>=m);
}
int main(){
	File_IO();
	cin>>n>>m;
	ll sum = 0;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	sort(arr+1, arr+n+1,greater<int>());
	int low  = 1 , high = n;
	int mid ;
	ll ans =0;
	while(low<=high){
		int mid = (high+low)/2;
		if(f(mid)){
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}
	if(ans == 0)cout<<"-1"<<endl;
	else 
	cout<<ans<<endl;

}