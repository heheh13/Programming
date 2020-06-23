#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 200005
#define mod  100000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
std::map<ll, ll> mp;
int cnt[mx];
int need;
int par[mx];
int find_set(int n){
	if(par[n]==n)return n;
	return par[n]=find_set(par[n]);
}
int deg[mx];
int  main(){
	#ifndef ONLINE_JUDGE
	read();
	write();
	double t1 = clock();
	#endif
	optimizar;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		deg[a]++;
		deg[b]++;
	}
	int i
	for(int i = 0;i<n;i++){
		if(deg[i]>=k){
			for(int j = 0;j<v[j].size();j++){
				ans.push_back({i,v[i][j]})
			};
		}
	}
	#ifndef ONLINE_JUDGE
	double t2 = clock();
	printf("%.10lf\n", (t2-t1));
	#endif
	return 0;
}