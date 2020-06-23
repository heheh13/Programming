#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1005
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
	int n,h,a,b,q;
	cin>>n>>h>>a>>b>>q;
	while(q--){
		int t1, f1, t2, f2;
		cin>>t1>>f1>>t2>>f2;
		int ans = abs(t2-t1);
		///there are passage in  f1 or  f2
		if(ans == 0){
			cout<<abs(f1-f2)<<endl;
			continue;
		}
		int cost = 0;
		if((f1>=a&&f1<=b)||(f2>=a&&f2<=b)){
			cost = abs(f1-f2);

			ans+=cost;
		}
		else{
			int temp1 = abs(f1-a)+abs(f2-a);
			//if i go wiht b
			int temp2 = abs(f1-b)+abs(f2-b);
			ans+=min(temp1,temp2);
		}
		cout<<ans<<endl;
	}
}