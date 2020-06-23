#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int NA = -1111;
ll sq(ll v){
	return v*v;
}
int arr[mx];
int sum[4*mx],lazy1[4*mx],lazy2[4*mx];
ll square[4*mx];
void push1(int id , int l , int r){
	if(lazy1[id]!=NA){
		//dbg(lazy1[id],id);
		int mid = (l+r)>>1;
		int left = (mid-l+1);
		int right = (r-mid);
		int lft = id*2;
		int rft = lft|1;

		sum[lft]=lazy1[id]*(left);
		sum[rft]=lazy1[id]*(right);
		square[lft]=sq(lazy1[id])*(ll)left;
		square[rft]= sq(lazy1[id])*(ll)right;
		lazy1[lft]=lazy1[id];
		lazy1[rft]=lazy1[id];
		lazy1[id]=NA;

	}
}
void push2(int id , int l , int r){
	if(lazy2[id]){
		int mid = (l+r)>>1;
		int left = (mid-l+1);
		int right = (r-mid);
		int lft = id*2;
		int rft = lft|1;

		square[lft]+=sq(lazy2[id])*(ll)left+2ll*(ll)lazy2[id]*(ll)sum[id];
		square[rft]+=sq(lazy2[id])*(ll)right+2ll*(ll)lazy2[id]*(ll)sum[id];

		sum[lft]+=lazy2[id]*(left);
		sum[rft]+=lazy2[id]*(right);

		lazy2[lft]+=lazy2[id];
		lazy2[rft]+=lazy2[id];
		lazy2[id]=0;

	}
}
void build(int id , int l , int r){
	if(l == r){
		sum[id]=arr[l];
		square[id]=sq(arr[l]);
		/*lazy2[id]=0;
		lazy1[id]=NA;*/
		return ;
	}
	else {
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft|1;
		build(lft,l,mid);
		build(rft,mid+1,r);
		sum[id]=sum[lft]+sum[rft];
		square[id]=square[lft]+square[rft];
	}

}
void update1(int id , int l , int r , int st , int en , int rep){
	if(st>en)return ;
	if(l == st && r == en){
		push2(id,l,r);
		push1(id,l,r);
		sum[id]=rep*(r-l+1);
		square[id]= sq(rep)*(ll)(r-l+1);
		lazy1[id]=rep;
		return ;
	}
	else {
		push2(id,l,r);
		push1(id,l,r);
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft|1;
		update1(lft,l,mid,st,min(en,mid),rep);
		update1(rft,mid+1,r,max(mid+1,st),en,rep);
		sum[id]=sum[lft]+sum[rft];
		square[id]=square[lft]+square[rft];

	}
}
void update2(int id , int l , int r , int st , int en , int add){
	if(st>en)return ;
	if(l == st && r == en){

		push1(id,l,r);
		push2(id,l,r);
		square[id] +=(ll)(r-l+1)*sq(add)+2ll*(ll)add*(ll)sum[id];
		sum[id]+=add;
		lazy2[id]+=add;
		return ;
	}
	else {
		push1(id,l,r);
		push2(id,l,r);
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft+1;
		update2(lft,l,mid,st,min(en,mid),add);
		update2(rft,mid+1,r,max(mid+1,st),en,add);
		sum[id]=sum[lft]+sum[rft];
		square[id]=square[lft]+square[rft];

	}
}
ll query(int id , int l , int r , int st , int en){
	if(st>en)return 0;
	if(l==st && r == en){
		push1(id,l,r);
		push2(id,l,r);
		return square[id];
	}
	else {
		push1(id,l,r);
		push2(id,l,r);
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft|1;
		return query(lft,l,mid,st,min(en,mid)) + query(rft,mid+1,r,max(mid+1,st),en);
	}
}
int main(){
	File_IO();
	int t;
	scanf("%d",&t);
	for(int ts = 1;ts<=t;ts++){
		printf("Case %d:\n",ts );
		int n,q;
		scanf("%d %d",&n,&q);
		for(int i = 1;i<=n;i++)scanf("%d",&arr[i]);
		build(1,1,n);
		for(int i =0;i<4*n;i++)lazy2[i] = 0, lazy1[i]=NA;
		while(q--){
			int type,st,en,x;
			scanf("%d",&type);
			if(type==1){
				
				scanf("%d %d %d",&st,&en,&x);
				update2(1,1,n,st,en,x);
			}
			else if(type==0){
				scanf("%d %d %d",&st,&en,&x);
				update1(1,1,n,st,en,x);
			}
			else if(type==2) {
				scanf("%d %d",&st,&en);
				printf("%lld\n",query(1,1,n,st,en));
			}

		}
	}

}