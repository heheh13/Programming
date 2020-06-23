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
string now;
int sum(int a, int b){
	return a+b;
}
void push(int id,int l, int r){
	
	if(lazy[id]!=3){
		dbg3(id,l,r);
		dbg2(id,lazy[id]);
		int mid = (l+r)>>1;
		int left = (mid-l+1);
		int right = (r-mid);
		
		if(lazy[id]==-1){
			//dbg3(id,left,right);
			tree[2*id]=left-tree[2*id];
			tree[2*id+1]=right-tree[2*id+1];

		}
		else{
			tree[2*id]=lazy[id]*left;
			tree[2*id+1]=lazy[id]*right;
		}
		lazy[2*id]=lazy[id];
		lazy[2*id+1]=lazy[id];
		lazy[id]=3;
		dbg2(tree[id*2],tree[id*2+1]);
	}
}
void build(int id , int l, int r){
	//cout<<now<<endl;
	if(l==r){
		tree[id]=(now[l]=='1');
		//cout<<now[l]<<endl;
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
		//dbg1(lazy[id]);
		push(id,l,r);
		if(lazy[id]!=3)dbg2(l,r);
		if(val==-1){
			tree[id]=(r-l+1)-tree[id];
			lazy[id]=val;
		}
		else{

			tree[id]=val*(r-l+1);
			lazy[id]=val;
		}
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
		//dbg1(lazy[id]);
		push(id,l,r);
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
	cin>>t;
	for(int ts = 1;ts<=t;ts++){
		for(int i = 0;i<4*mx;i++)tree[i]=0,lazy[i]=3;
		int m;
		cin>>m;
		 now ="a";
		for(int  i = 0;i<m;i++){
			int T;
			string line;
			cin>>T>>line;
			for(int x = 0;x<T;x++)
				now+=line;
		}
		cout<<now<<endl;
		int n = now.size()-1;
		build(1,1,n);
		int q;
		cin>>q;
		while(q--){
			char ch;
			int a,b;
			cin>>ch>>a>>b;
			if(ch=='S'){
				printf("%d\n",query(1,1,n,a+1,b+1));
			}
			if(ch=='F'){
				update(1,1,n,a+1,b+1,1);
			}
			if(ch=='E'){
				update(1,1,n,a+1,b+1,0);
			}
			if(ch=='I')update(1,1,n,a+1,b+1,-1);
		}
	}
}