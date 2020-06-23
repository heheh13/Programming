#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100005
#define mod  1000000007
#define sci(a) scanf("%d",&a)
#define scii(a,b) scanf("%d %d",&a,&b)
#define scl(a) scanf("%lld",&a)
#define scll(a,b) scanf("%lld %lld",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int arr[mx], tree[mx*4];
int gcd(int a, int b){
	return __gcd(a,b);
}
void build (int id , int L , int R){
	if(L == R) {
		tree[id]=1;
		return ;
	}
	int mid = (L+R)>>1;
	int lft = id*2;
	int rft = id*2 + 1;
	build (lft,L,mid);
	build(rft,mid+1, R);
	tree[id]=max(tree[lft],tree[rft]);
}
int query(int id, int L , int R , int st , int en){
	if(en<L || R<st)return 0;
	if(st <= L && en >= R){
		return tree[id];
	}
	int mid = (L+R)>>1;
	int lft = id*2;
	int rft = lft+1;
	return gcd(query(lft,L,mid,st,en),query(rft,mid+1,R,st,en));
}
void update(int id , int L , int R , int idx, int val){
	if(L==R){
		tree[id] = val;
		return ;
	}
	int mid = (L+R)>>1;
	int lft = id*2;
	int rft = lft+1;
	if(idx>mid){
		update(rft,mid+1,R,idx,val);
	}
	else update(lft,L,mid,idx,val);
	tree[id]=gcd(tree[lft],tree[rft]);
}
stack<int> stk[mx];
map<int,int>mp;
int main(){
	File_IO();
	int n;
	scanf("%d ",&n);
	char ch ;
	int val;
	int idx = 0;
	int pos = 0;
	for(int i = 1 ;i<=n;i++){
		scanf("%c %d ",&ch,&val);
		if(ch =='+'){
			if(!mp[val])mp[val]=++pos;
			stk[mp[val]].push(++idx);
			update(1,1,n,idx,val);
			printf("%d\n",max(1,query(1,1,n,1,n)));
		}
		else{
			//find_idx
			int nidx = stk[mp[val]].top();
			stk[mp[val]].pop();
			update(1,1,n,nidx,0);
			printf("%d\n",max(1,query(1,1,n,1,n)));
		}
	}
	
}