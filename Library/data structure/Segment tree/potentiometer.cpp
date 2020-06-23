#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 200005
#define mod  1000000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int arr[mx], tree[mx*4];
int sum (int a, int b){
	return a+b;
}
void build (int id , int L , int R){
	if(L == R) {
		tree[id]=arr[L];
		return ;
	}
	int mid = (L+R)>>1;
	int lft = id*2;
	int rft = id*2 + 1;
	build (lft,L,mid);
	build(rft,mid+1, R);
	tree[id]=sum(tree[lft],tree[rft]);
}
int query(int id, int L , int R , int st , int en){
	if(en<L || R<st)return 0;
	if(st <= L && en >= R){
		return tree[id];
	}
	int mid = (L+R)>>1;
	int lft = id*2;
	int rft = lft+1;
	return sum(query(lft,L,mid,st,en),query(rft,mid+1,R,st,en));
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
	tree[id]=sum(tree[lft],tree[rft]);
}
int main(){
	File_IO();
	optimizar;
	int n;
	int ts = 1;
	bool newline = false;
	while(cin>>n && n){
		for(int i = 1;i<=n;i++)cin>>arr[i];
		build(1,1,n);
		string str;
		if(newline)cout<<endl;
		newline = true;
		cout<<"Case "<<ts++<<":"<<endl;
		while(cin>>str){
			if(str=="END"){
				break;
			}
			if(str=="S"){
				int idx,val;
				cin>>idx>>val;
				update(1,1,n,idx,val);
			}
			if(str=="M"){
				int a,b ;
				cin>>a>>b;
				cout<<query(1,1,n,a,b)<<endl;
			}
		}
	}

}