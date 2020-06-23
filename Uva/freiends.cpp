#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 50005
#define mod  1000000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
#define MAXN 100005
typedef long long ll;
int par[mx];

int find_set(int n){
	if(par[n]==n)return n;
	return par[n] = find_set(par[n]);
}
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(rand()%2)swap(a,b);
		par[b]=a;
	}
}
int main(){
	File_IO();
	int t;
	scanf("%d",&t);
	for(int ts = 1;ts<=t;ts++){
		int n,m;
		int a,b;
		scanf("%d%d",&n,&m);
		for(int i = 0;i<=n;i++)par[i]=i;
		for(int i = 0;i<m;i++){
			scanf("%d %d",&a,&b);
			union_set(a,b);
		}
		int arr[mx];
		for(int i = 1;i<=n;i++)arr[i]=find_set(i);
		for(int i = 1;i<=n;i++)arr[i]=find_set(i);
		sort(arr+1,arr+n+1);
		//for(int i = 1;i<=n;i++)printf("%d ",arr[i] );
		int maxi = 1,cnt = 1;
		for(int i = 2;i<=n;i++){
			if(arr[i]==arr[i-1])cnt++;
			else cnt = 1;
			maxi = max(maxi,cnt);
		}
		printf("%d\n", maxi);
	}
}