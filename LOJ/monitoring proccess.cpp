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
int main(){
	File_IO();
	optimizar;
	int t;
	cin>>t;
	for(int ts = 1;ts<=t;ts++){

		int n;
		cin>>n;
		int x[n],y[n];
		for(int i = 0;i<n;i++)cin>>x[i]>>y[i];
		sort(x,x+n);
	    sort(y,y+n);
	    int ans = 0;
	    int cnt =0;
	    for(int i = 0;i<n;i++){

	    	int low = upper_bound(x,x+n,y[i])-x;
	    	ans = max(ans,low-cnt);
	    	cnt++;
	    }
	cout<<"Case "<<ts<<": "<<ans<<endl;
	}
}