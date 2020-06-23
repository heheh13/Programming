#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 30004
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
std::vector<int> tree[4*mx];
int arr[mx];
struct data
{
	int l,r,k;
	
}d;
unordered_map<data,int> mp;
void build(int id,int l, int r){
	if(l==r){
		tree[id] = std::vector<int> (1,arr[l]);
		return;
	}
	else{
		int mid = (l+r)>>1;
		int lft = 2*id;
		int rft = lft|1;
		build(lft,l,mid);
		build(rft,mid+1,r);
		merge(tree[lft].begin(),tree[lft].end(),tree[rft].begin(),tree[rft].end(),back_inserter(tree[id]));

	}
}
int query(int id ,int l, int r, int st ,int en , int k){
	if(st>en)return 0;
	//data d;
	d.l = l ;
	d.r = r;
	d.k = k;
	//if(mp.count(d))return mp[d]; 
	if(l == st && en == r){
		int low = upper_bound(tree[id].begin(),tree[id].end(),k)-tree[id].begin();
		mp[d] = tree[id].size()-low;
		return tree[id].size()-low;
	}
	else{
		int mid  = (l+r)>>1;
		int lft = 2*id;
		int rft = lft|1;
		return query(lft,l,mid,st,min(mid,en),k)+ query(rft,mid+1,r,max(mid+1,st),en,k); 
	}
}
int main(){
	File_IO();
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)scanf("%d",&arr[i]);
	build(1,1,n);
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b,k;
		scanf("%d %d %d",&a,&b,&k);
		printf("%d\n",query(1,1,n,a,b,k));
	}
}