#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10001
#define mod  1000000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
#define inf 100
typedef long long ll;
int arr[mx];
struct data
{
	int sum, pref,sufix,maxi;
}tree[mx*4];
data combine(data l , data r){
	data res ;
	res.sum = l.sum+ r.sum;
	res.pref = max(l.pref,l.sum+r.pref);
	res.sufix = max(r.sufix,r.sum+l.sufix);
	res.maxi = max(max(l.maxi,r.maxi),l.sufix+r.pref);
	return res;

}
data make_data(int val){
	data res;
	res.sum = val;
	res.pref=res.sufix=res.maxi= val;
	return res;
}
void build(int id , int L , int R ){
	if(L==R){
		tree[id]=make_data(arr[L]);
		
		return ;
	}
	int mid = (L+R)>>1;
	int lft = id*2;
	int rft = lft+1;
	build(lft,L, mid);
	build(rft,mid+1,R);
	tree[id]=combine(tree[lft],tree[rft]);
}
data query(int id , int L , int R , int st, int en){
	if(st> R || en<L)return make_data(-inf);
	if(L == R){
		return tree[id];
	}
	int mid = (L+R)>>1;
	int lft = id*2;
	int rft = lft+1;
	return combine(query(lft,L,mid,st,en),query(rft,mid+1,R,st,en));
}
int main(){
	File_IO();
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	build(1,1,n);
	int a = 2, b = 3;
	data now = query(1,1,n,a,b);
	//cout<<now.maxi<<endl;
	for(int i = 1;i<=7;i++){
		cout<<tree[i].sum<<endl;
		cout<<tree[i].pref<<endl;
		cout<<tree[i].sufix<<endl;
		cout<<tree[i].maxi<<endl;
		cout<<endl;
	}
}