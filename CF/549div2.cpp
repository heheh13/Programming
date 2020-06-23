#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100005

#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
set<pair<int,int> >child[mx];
int par[mx];
int respect[mx];
int main(){
	File_IO();
	int n;
	scanf("%d",&n);
	int p,c;
	int root;
	for(int i = 1;i<=n;i++){
		scanf("%d %d",&p,&c);
		respect[i]=c;
		par[i]=p;
		if(p==-1){
			root = i;
			continue;
		}
		child[p].insert({i,c});
	}
	bool flag = true;
	for(int i = 1;i<=n;i++){
		if(respect[i]==1){
			int cnt = 0;
			for(auto it = child[i].begin();it!=child[i].end();it++){
				if(it->second==1){
					cnt++;
					par[it->first]=par[i];
				}
			}
			if(child[i].size()==cnt)printf("%d ",i),flag =false;
		}
	}
	if(flag){
		cout<<"-1"<<endl;
	}
}