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
int tree[4*mx],arr[mx],lazy[4*mx];
int sum(int a, int b){
	return a+b;
}
void push(int id,int l, int r){
	dbg3(id,l,r);
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
int query(int id, int l , int r  , int st ,int en){
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
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	build(1,1,n);
	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int a,b;
			cin>>a>>b;
			cout<<query(1,1,n,a,b)<<endl;
		}
		else{
			int a,b,val;
			cin>>a>>b>>val;
			update(1,1,n,a,b,val);
		}
	}
}