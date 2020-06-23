#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 50005
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
int arr[mx];
std::vector<int> tree[4*mx];
void build(int id , int l, int r){
	if(l==r){
		tree[id].push_back(arr[l]);
	}
	else{
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft|1;
		build(lft,l,mid);
		build(rft,mid+1,r);
		merge(tree[lft].begin(),tree[lft].end(),tree[rft].begin(),
			tree[rft].end(),back_inserter(tree[id]));
	}
}
int query(int id , int l , int r , int st , int en,int val){
	if(st>en)return 0;
	if(l== st && en == r){
		int low = lower_bound(tree[id].begin(),tree[id].end(),val)-tree[id].begin();
		return low;
	}
	else{
		int mid = (l+r)>>1;
		int lft = 2*id;
		int rft = lft|1;
		int x = query(lft, l , mid,st , min(mid, en),val);
		int y = query(rft, mid+1,r, max(st,mid+1),en,val);
		return x+y;
	}
}
int main(){
	File_IO();
	int n;
	cin>>n;
	for(int i  = 1;i<=n;i++)cin>>arr[i];
	build(1,1,n);
	int x,a,b;
	cin>>a>>b>>x;
	cout<<query(1,1,n,a,b,x)<<endl;
}