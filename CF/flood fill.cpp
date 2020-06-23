#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 5005
#define mod  100000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
//string arr;
int arr[mx];
int n;
int dp[mx][mx];
int bt( int left , int right,int  clr){
	//dbg3(left,right,clr);
	//dbg2(arr[left],arr[right]);
	if(left == 0 && right == n-1){
		return 0;
	}
	if(left-1 >=0 &&arr[left-1]==clr)return bt(left-1,right,clr);
	 if(right+1<n && arr[right+1]==clr) return bt(left,right+1,clr);
	if(~dp[left][right])return dp[left][right];
	int &ans = dp[left][right]=mod;
	if(left-1>=0) ans =min(ans,1+bt(left-1, right,arr[left-1]));
	if(right+1<n)ans = min(ans,1+bt(left,right+1,arr[right+1]));
	return ans ;
}
int main(){
	File_IO();
	cin>>n;
	memset(dp,-1,sizeof(dp));
	string help ;
	cin>>help;
	for(int i = 0;i<help.size();i++)arr[i]=help[i]-96;
	//for(int i = 0;i<n;i++)cout<<arr[i];
	//string arr;
	//cin>>arr;

	int ans = mod;
	for(int i = 0;i<n;i++){
		//memset(dp,-1,sizeof(dp));
	ans = min(ans,bt(i,i,arr[i]));
	}
	cout<<ans<<endl;
}