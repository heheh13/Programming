#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 5005
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
int par[mx];
int find_set(int n){
	if(par[n]==n)return n;
	return par[n]=find_set(par[n]);
}
std::vector<pair<int,int> > close, nw;
int main(){
	File_IO();
	int n;
	cin>>n;
	int a, b;
	for(int i = 0;i<=n;i++)par[i]=i;
	for(int i = 1;i<n;i++){
		cin>>a>>b;
		if(find_set(a)!=find_set(b))par[a]=b;
		else close.push_back({a,b});
	}
	for(int i = 2;i<=n;i++){
		cout<<find_set(i)<<endl;
	}
}