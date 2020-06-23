#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10001
#define mod  1000000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
map<string,int>mp;
int par[mx][2];
int findset(int n){
	if(par[n][0]==n)return n;
	return par[n][0]=findset(par[n][0]);
}
union_set(int a, int b){
	a = findset(a);
	b = findset(b);

	if(a!=b){
		if(rand()%2)swap(a,b);
		//cout<<par[a][0]<<" "<<b<<endl;
		par[a][1]=par[a][1]+par[b][1];
		par[b][0]=a;
		//cout<<par[a][0]<<" "<<par[a][1]<<endl;
	}

}
int main(){
	File_IO();
	int t;
	scanf("%d",&t);
	char a[100],b[100];
	while(t--){
		int n;
		int idx = 0;
		scanf("%d",&n);
		for(int i = 0;i<=mx;i++)par[i][0]=i,par[i][1]=1;
		for(int i = 0;i<n;i++){
			scanf("%s %s",a,b);
			if(!mp.count(a))
				mp[a]=++idx;
			if(!mp.count(b))
				mp[b]=++idx;
			//cout<<mp[a]<<" "<<mp[b]<<endl;
			union_set(mp[a],mp[b]);
			
			cout<<par[findset(mp[a])][1]<<endl;
			// int key = findset(mp[a]),cnt = 0;
			// for(int i = 1;i<=idx;i++){
			// 	if(key==findset(par[i][0]))cnt++;

			// }
			// printf("%d\n",cnt);
			
		}
		//for(int i = 0;i<=idx;i++)cout<<findset(par[i])<< " ";
	}
}