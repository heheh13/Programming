#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 2005
#define mod  998244353
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct edges
{
	int u,v;
	double cost;
	
}e;
double dist( double x1, double y1, double x2, double y2){
	return sqrt(((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2)));
}
bool cmp (struct edges a, struct edges b){
	return a.cost<b.cost;
}
int par[505];
int find_set(int n){
	if(par[n]==n)return n;
	return par[n]=find_set(par[n]);
}
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		par[b]=a;
	}
}
void make_set(int n){
	par[n]=n;
}
int main(){
	File_IO();
	int t;
	cin>>t;
	while(t--){
		int s,n;
		cin>>s>>n;
		int x[n] , y[n];
		
		
		for(int i = 0;i<n;i++){
			cin>>x[i]>>y[i];
		}
		struct edges e;
		std::vector<edges> v;
		bool mark[n][n];
		memset(mark,0,sizeof(mark));
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(i==j)continue;
				if(mark[i][j]|| mark[j][i])continue;
				mark[i][j]=true;
				mark[j][i]=true;
				e.u = i;
				e.v = j;
				e.cost = dist(x[i],y[i],x[j],y[j]);
				v.push_back(e);
			}
		}
		for(int i = 0;i<=n;i++)make_set(i);
		sort(v.begin(),v.end(),cmp);
		std::vector<double > ans;
		for(auto x:v){
			//cout<<x.u<<" "<<x.v<<" "<<x.cost<<endl;
			if(find_set(x.u)!=find_set(x.v)){
				union_set(x.u,x.v);
				ans.push_back(x.cost);
			}
		}
		double help = 0;
		for(int i = 0;i<ans.size()-s+1;i++)help = max(help,ans[i]);
		printf("%.2lf\n",help);
	}
}