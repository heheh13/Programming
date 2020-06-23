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
int tree[4*mx],lazy[4*mx];
int sum(int a, int b){
	return a+b;
}
void push(int id,int l, int r){
	
	if(lazy[id]){
		int mid = (l+r)>>1;
		int left = (mid-l+1);
		int right = (r-mid);
		tree[2*id]=left-tree[2*id];
		tree[2*id+1]=right-tree[2*id+1];
		lazy[2*id]^=1;
		lazy[2*id+1]^=1;
		lazy[id]=0;
	}
}

void update(int id , int l , int r, int st ,int en, int val){
	if(st>en)return;
	if(st==l && en == r){
			tree[id]=(r-l+1)-tree[id];
			lazy[id]^=val;
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
		if(lazy[id])
		push(id,l,r);
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft+1;
		return sum(query(lft,l,mid,st,min(mid,en)),query(rft,mid+1,r,max(mid+1,st),en));
	}
}
int main(){
	File_IO();
	int n,m;
	scanf("%d %d",&n,&m);
	int t,a,b;
	while(m--){
		scanf("%d %d %d",&t,&a,&b);
		//dbg3(t,a,b);
		if(t==0){
			update(1,1,n,a,b,1);
		}
		else{
			printf("%d\n",query(1,1,n,a,b));
		}
	}
}