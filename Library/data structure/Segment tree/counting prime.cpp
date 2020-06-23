#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10004
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
#define maxn 1000000
int arr[mx],tree[4*mx],lazy[4*mx];
bitset<maxn> check;
void seive(){
	check[1]=1;
	int sqr = sqrt(maxn);
	for(int  i = 4;i<maxn;i+=2)check[i]=1;
	for(int i = 3;i<=sqr;i+=2){
		if(!check[i]){
			for(int j = i*i ;j<maxn;j+=2*i){
				check[j]=1;
			}
		}
	}
}
int sum(int a, int b){
	return a+b;
}
void push(int id , int l , int r){
	if(lazy[id]!=-1){
		int mid = (l+r)>>1;
		int left = (mid-l+1);
		int right = (r-mid);
		int lft  = id*2;
		int rft = lft|1;
		tree[lft] = left* lazy[id];
		tree[rft] = right* lazy[id];
		lazy[lft]=lazy[id];
		lazy[rft]=lazy[id];
		lazy[id]=-1;
	}
}
void build(int id, int l , int r){
	if(l==r){
		tree[id]=arr[l];
		return ;
	}
	else{
		int mid = (l+r)>>1;
		int lft = id * 2;
		int rft = lft|1;
		build(lft,l,mid);
		build(rft,mid+1,r);
		tree[id]=sum(tree[lft],tree[rft]);
	}
}
void update(int id , int l , int r , int st , int en , int val){
	if(st>en)return ;
	if(st == l && en == r){
		tree[id]= (r-l + 1)*val;
		lazy[id]=val;
		return ;
	}
	else{
		push(id,l,r);
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft|1;
		update(lft,l,mid,st,min(en,mid),val);
		update(rft,mid+1,r,max(st,mid+1),en,val);
		tree[id]= sum(tree[lft],tree[rft]);
	}
}
int query(int id , int l , int r, int st , int en){
	if(st>en)return 0;
	if(st == l && en == r){
		return tree[id];
	}
	else{
		push(id,l,r);
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft|1;
		return sum(query(lft,l,mid,st,min(mid,en)),query(rft,mid+1,r,max(mid+1,st),en));
	}
}
int main(){
	File_IO();
	seive();
	int t;
	scanf("%d",&t);
	for(int ts = 1;ts<=t;ts++){
		printf("Case %d:\n",ts);
		memset(lazy,-1,sizeof(lazy));
		int n,q;
		scanf("%d %d",&n,&q);
		for(int i = 1;i<=n;i++)scanf("%d",&arr[i]),arr[i]=(check[arr[i]]==0);
		build(1,1,n);
		while(q--){
			int type , a,b,val;
			scanf("%d",&type);
			if(type==1){
				scanf("%d %d",&a,&b);
				printf("%d\n",query(1,1,n,a,b) );
			}
			else{
				scanf("%d %d %d",&a,&b,&val);
				update(1,1,n,a,b,(check[val]==0));
			}
		}
	}
}