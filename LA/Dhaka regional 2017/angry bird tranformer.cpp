#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10000
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
	int n;
	int ts = 1;
	while(scanf("%d",&n)&&n){
		///printf("Case %d: ",ts++);
		int x[n],y[n];
		int res[mx+1];
		memset(res,0,sizeof(res));
		for(int i = 0;i<n;i++){
			scanf("%d%d",&x[i],&y[i]);
			for(int j = max((x[i]-y[i]),1); j<=min(x[i]+y[i],10000); j++)res[j]++;
		}
		int track =0;
		int maxi =0;
		for(int i =1;i<=mx;i++)
			if(maxi<res[i]) maxi = res[i],track=i;
		printf("%d\n",maxi);
		//cout<<res[track]<<endl;
	}
}