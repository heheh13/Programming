#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100005
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
ll tree[4*mx],arr[mx],lazy[4*mx];
ll sum(ll a, ll b){
	return a+b;
}
void push(int id,int l, int r){
	//dbg3(id,l,r);
	if(lazy[id]){
		int mid = (l+r)>>1;
		int left = (mid-l+1);
		int right = (r-mid);
		tree[2*id]+=lazy[id]*left;
		tree[2*id+1]+=lazy[id]*right;
		lazy[2*id]+=lazy[id];
		lazy[2*id+1]+=lazy[id];
		lazy[id]=0;
	}
}
void build(int id , int l, int r){
	if(l==r){
		tree[id]=arr[l];
		return;
	}
	else{
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft+1;
		build(lft,l,mid);
		build(rft,mid+1,r);
		tree[id]=sum(tree[lft],tree[rft]);
	}
}
void update(int id , int l , int r, int st ,int en, int val){
	if(st>en)return;
	if(st==l && en == r){
		//if(lazy[id])cout<<"hi";
		tree[id]+=val*(r-l+1);
		lazy[id]+=val;
		return;
	}
	else{
		push(id,l,r);
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft+1;
		update(lft,l,mid,st,min(en,mid),val);
		update(rft,mid+1,r,max(mid+1,st),en,val);
		tree[id]=sum(tree[lft],tree[rft]);
	}
}
ll query(int id, int l , int r  , int st ,int en){
	if(st>en)return 0;
	if(st == l && en == r){
		return tree[id];
	}
	else{
		push(id,l,r);
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft+1;
		return sum(query(lft,l,mid,st,min(mid,en)),query(rft,mid+1,r,max(mid+1,st),en));
	}
}
int main(){
	File_IO();
	int t;
	scanf("%d",&t);
	for(int ts = 1;ts<= t;ts++){
		for(int i = 0;i<4*mx;i++){
			tree[i]=lazy[i]=0;
		}
		int n,q;
		scanf("%d %d",&n,&q);
		printf("Case %d:\n",ts);
		int type ;
		while(q--){
			scanf("%d",&type);
			if(type==1){
				int a,b ;
				scanf("%d %d",&a,&b);
				printf("%lld\n",query(1,1,n,a+1,b+1) );
			}
			else{
				int a,b,val;
				scanf("%d %d %d",&a,&b,&val);
				update(1,1,n,a+1,b+1,val);
			}
		}
	}
}