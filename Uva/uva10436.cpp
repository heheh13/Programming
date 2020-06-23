#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10000005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int x[11],y[11];
bool taken[11];
int beep,stx,sty,n,m;
int ans ;
void bt(int pos,int cx,int cy,int dist){
	if(pos>=beep){

		int base = abs(stx-cx)+abs(sty-cy);
		ans = min(ans,min(2*dist, dist+base));
		return ;
	}
	for(int i = 0;i<beep;i++){
		if(!taken[i]){
			taken[i]=1;
			int temp = abs(cx-x[i])+abs(cy-y[i]);
			bt(pos+1,x[i],y[i],dist+temp);
			taken[i]=0;
		}
	}
	return ;
}
int main(){
	File_IO();
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		cin>>stx>>sty;
		cin>>beep;
		for(int i = 0;i<beep;i++)
			cin>>x[i]>>y[i];
		ans=1e9;
		bt(0,stx,sty,0);
		cout<<"The shortest path has length "<<ans<<endl;
	}
}