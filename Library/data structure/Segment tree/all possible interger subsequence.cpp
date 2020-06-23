#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100005
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
int arr[mx];
//std::vector<pair<int,int> > v;
struct data{
	int val , idx;
}v[mx];
int tree[4*mx];
void update(int id , int l , int r , int pos , int val){
	//dbg3(id,l,r);
	if(l==r){
		//dbg1(l);
		tree[id]=val;
	}
	else{
		int mid = (l+r)>>1;
		int lft = 2*id;
		int rft = lft|1;
		if(pos<=mid) update(lft,l,mid,pos,val);
		else update(rft,mid+1,r,pos,val);
		tree[id] = ((ll)tree[lft]+(ll)tree[rft])%mod;
	}
	//dbg1(tree[1]);
}
int query(int id , int l , int r, int st , int en){
	if(st>en)return 0;
	if(l == st && en == r)return tree[id];
	else{
		int mid = (l+r)>>1;
		int lft = 2*id;
		int rft = lft|1;
		int  x = query(lft , l,mid, st, min(mid,en));
		int y = query(rft, mid+1, r , max(st,mid+1),en);
		return (x+y)%mod;
	}
}
bool cmp(data &a, data &b){
	if(a.val == b.val )return a.idx>b.idx;
	return a.val<b.val;
}
int main(){
	File_IO();

	int t;
	scanf("%d",&t);
	for(int ts = 1;ts<=t;ts++){
		int n;
		scanf("%d",&n);
		for(int i = 1;i<=n;i++)scanf("%d",&arr[i]),v[i].val = arr[i],v[i].idx=i;
		sort(v+1,v+n+1,cmp);
		update(1,1,n,v[1].idx,1);
		int sum = 1;
		ll idx = v[1].idx;
		int now = 1;
		for(int i = 2;i<=n;i++){
			idx = v[i].idx;
			now = 1+query(1,1,n,1,idx-1);
			update(1,1,n,v[i].idx,now);
			sum+=now;
			sum%=mod;
		}
		printf("Case %d: %d\n",ts,sum);
		for(int i = 0;i<4*n;i++)tree[i]=0;
	}

}
