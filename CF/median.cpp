#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1000005
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
	int n;
	cin>>n;
	bitset<mx>a,b,c;
	cin>>a;
	cin>>b;
	c = a^b;
	int cnt = 0;
	int ans = c.count();
	//cout<<ans<<endl;
	for(int i = 0;i<mx-1;i++){
		if(c[i]==1&& c[i+1]==1){
			if(a[i]!=a[i+1]){
				cnt++;
				c.flip(i);
				c.flip(i+1);	
			}
		}
	}
	ans = min(ans, cnt+(int)c.count());
	cout<<ans<<endl;
}