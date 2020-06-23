#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 50005
#define mod  1000000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
#define inf 100000000
typedef long long ll;
int arr[mx];
struct data
{
	int sum, pref,sufix,maxi;

}tree[mx*4];
data make_data(int val){
	data temp;
	temp.sum = val;
	temp.pref = temp.sufix=temp.maxi = val;
	return temp;
}
data mini_mumdata(){
	data temp;
	temp.sum = 0;
	temp.pref  = -inf;
	temp.sufix = -inf;
	temp.maxi = -inf;
	return temp;
}
data combine(data l , data r){
	data temp ;
	temp.sum = l.sum+r.sum;
	temp.pref = max(l.pref,l.sum+r.pref);
	temp.sufix = max(r.sufix,r.sum+l.sufix);
	temp.maxi  = max(max(l.maxi,r.maxi),l.sufix+r.pref);
	return temp;
}
void build(int id , int l, int r){
	if(l==r){
		tree[id]=make_data(arr[l]);
		return;
	}
	else{
		int mid = (l+r)>>1;
		int lft = 2*id;
		int rft = lft|1;
		build(lft,l,mid);
		build(rft,mid+1,r);
		tree[id]=combine(tree[lft],tree[rft]);
	}
}
data query(int id ,int l ,int r, int st, int en){
	//dbg(st,en);
	if(st>en)return mini_mumdata();
	if(l == st && en == r){
		return tree[id];
	}
	else {
		int mid = (l+r)>>1;
		int lft = 2*id;
		int rft = lft|1;
		return combine(query(lft,l,mid,st,min(mid,en)),
			query(rft,mid+1,r,max(mid+1,st),en));
	}
}
int main(){
	File_IO();
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	build(1,1,n);
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		data temp = query(1,1,n,a,b);
		printf("%d\n",temp.maxi);
	}
}
