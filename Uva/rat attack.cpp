#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1025
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int killed[mx+5][mx+5];
int main(){
	File_IO();
	optimizar;
	int t;
	cin>>t;
	while(t--){
		int d,n;
		cin>>d>>n;
		for(int i = 0;i<n;i++){
			int x,y,p;
			cin>>x>>y>>p;
			int minx,miny,maxx,maxy;
			minx=max(0,x-d);
			maxx= min(mx,x+d);
			miny=max(0,y-d);
			maxy= min(mx,y+d);
			for(int  j = minx;j<=maxx;j++){
				for(int k = miny;k<=maxy;k++)killed[j][k]+=p;
			}	
		}
		int ans = 0,x1=0,y1=0;
		for(int i = 0;i<1025;i++){
			for(int j = 0;j<1025;j++){
				int s = killed[i][j];
				if(s>ans){
					ans=s;
					x1=i;
					y1=j;
				}
			}
		}
		cout<<x1<<" "<<y1<<" "<<ans<<endl;
		memset(killed,0,sizeof(killed));
	}
}