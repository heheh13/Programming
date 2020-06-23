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
struct Lazy
{
	int vl,vr;
	int val;
	int status=0;
}lazy[4*mx];
int tree[4*mx];

int sum(int a, int b){
	return a+b;
}
int range_sum(int a, int b){
	//dbg2(a,b);
	if(a>b)swap(a,b);
	 b = (b*(b+1))/2;
	a = (a*(a-1))/2;
	return b-a;
}
int high,low;
void push(int id, int l , int r){
	if(lazy[id].status==1){
		int mid = (l+r)>>1;
		int left = mid-l+1;
		int right = r-mid;
		int lmid = (lazy[id].vl+lazy[id].vr)>>1;
		tree[2*id] +=range_sum(lazy[id].vl,lmid); 
		tree[2*id+1] +=range_sum(lmid+1,lazy[id].vr);
		lazy[id*2] .vl = lazy[id].vl;
		lazy[id*2] .vr = lmid;
		lazy[id*2] .status=1;
		lazy[id*2 + 1] . vl = lmid+1;
		lazy[id*2 +1 ] .vr = lazy[id].vr; 
		lazy[id*2 +1].status = 1;
	}
	else if(lazy[id].status==2){
		int lmid = (lazy[id].vl +lazy[id].vr)>>1;
		int vx = lazy[id].vl-lmid+1;
		tree[2*id] +=range_sum(lazy[id].vl,vx);
		tree[2*id+1] +=range_sum(vx-1,lazy[id].vr);
		lazy[id*2] .vl = lazy[id].vl;
		lazy[id*2] .vr = vx;
		lazy[id*2].status = 2;
		lazy[id*2 + 1].vl = vx-1;
		lazy[id*2 + 1] .vr = lazy[id].vr;
		lazy[id*2+1].status=2;
	}
	else if(lazy[id].status==3){
		int mid = (l+r)>>1;
		int left =  mid-l+1;
		int right = r-mid;
		tree[2*id ]= left * lazy[id].val;
		tree[2*id +1]= right * lazy[id].val;
		lazy[id*2].val = lazy[id].val;
		lazy[id*2].status = 3;
		lazy[id*2+1].val = lazy[id].val;
		lazy[id*2+1].status = 3;
	}
	lazy[id].status=0;
}

void updateA(int id,int l,int r,int st,int en){
	if(st>en)return ;
	if(st== l && en == r){
		 dbg2(l,r);
		// dbg2(low,high);
		tree[id] +=range_sum(low,low+min(r-l,high));
		lazy[id].vl = low;
		low +=min(r-l+1,high);
		lazy[id].vr = low-1;
	//	dbg2(lazy[id].vl,lazy[id].vr);
		lazy[id].status=1;
	}
	else{
		push(id,l,r);
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft|1;
		int m = (low+high)>>1;
		updateA(lft,l,mid,st,min(mid,en));
		updateA(rft,mid+1,r,max(st,mid+1),en);
		tree[id]=sum(tree[lft],tree[rft]);
	}
}
void updateB(int id,int l,int r,int st,int en){
	
	if(st>en)return ;
	if(st== l && en == r){
		dbg2(l,r);
		dbg2(high,low);
		tree[id] +=range_sum(high,high-(r-l));
		dbg2(tree[id],id);
		lazy[id].vl = high;
		high -= (r-l+1);
		lazy[id].vr = high+1;
		dbg2(high+1,low);
		dbg2(lazy[id].vl, lazy[id].vr);
		lazy[id].status=2;
	}
	else{
		push(id,l,r);
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft|1;
		//int m = (low+high)>>1;
		updateB(lft,l,mid,st,min(mid,en));
		updateB(rft,mid+1,r,max(st,mid+1),en);
		tree[id]=sum(tree[lft],tree[rft]);
	}
}
void updateC(int id,int l,int r,int st,int en,int val){

	if(st>en)return ;
	if(st== l && en == r){
		tree[id] =(r-l+1)*val;
		lazy[id].val=val;
		lazy[id].status=3;
	}
	else{
		push(id,l,r);
		int mid = (l+r)>>1;
		int lft = id*2;
		int rft = lft|1;
		updateC(lft,l,mid,st,min(mid,en),val);
		updateC(rft,mid+1,r,max(st,mid+1),en,val);
		tree[id]=sum(tree[lft],tree[rft]);
	}
}
int query(int id , int  l , int r ,int st ,int en){
	if(st>en)return 0;
	if(st == l && en == r){
		return tree[id];
	}
	else{
		push(id,l,r);
		int mid =(l+r)>>1;
		int lft = 2*id;
		int rft = lft|1;
		int x = query(lft,l,mid,st,min(en,mid));
		int y = query(rft,mid+1,r,max(mid+1,st),en);
		return sum(x,y);
	}

}
int main(){
	File_IO();
	int t;
	scanf("%d",&t);
	int n =4;
	while(t--){
		char ch;
		int a, b, val;
		scanf(" %c",&ch);
		if(ch=='A'){
			scanf("%d %d",&a,&b);
			low = 1,high = (b-a+1);
			updateA(1,1,n,a,b);
		}
		if(ch=='B'){
			scanf("%d %d",&a,&b);
			low = 1, high = (b-a+1);
			//updateB(1,1,n,a,b);
		}
		if(ch=='C'){
			scanf("%d %d %d",&a,&b,&val);
			low = 0, high =0;
			//updateC(1,1,n,a,b,val);
		}
		if(ch=='S'){
			scanf("%d %d",&a,&b);
			cout<<query(1,1,n,a,b)<<endl;
		}
		//dbg3(lazy[4].status,lazy[4].vl,lazy[4].vr);

	}
	//for(int i = 0;i<=8;i++)cout<<tree[i]<<endl;
}