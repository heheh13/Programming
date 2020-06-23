#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 300005
#define mod  1000000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
std::vector<int> blocks[550];
int sqr ;
int arr[mx],n,m,u;
void update(int l , int r, int  v , int p){
	int fst = ceil(l/(double)sqr);
	int lst = ceil(r/(double)sqr);
	int cnt = 0;
	for(int i = l;i<=fst* sqr ;i++){
		//cout<<arr[i]<<" ";
		if(arr[i]<v)cnt++;
	}
	cout<<cnt<<endl;
	
	for(int i = r;i> (lst-1) * sqr;i--){
		//cout<<arr[i]<<" ";
		if(arr[i]<v)cnt++;
	}
	cout<<cnt<<endl;

	for(int i = fst+1; i<lst;i++){
		cnt+=upper_bound(blocks[i].begin(),blocks[i].end(),v-1)-blocks[i].begin();
	}
	
	ll new_val = ((ll)u *(ll) cnt )/(ll)(r-l+1);

	
	arr[p]=new_val;
	int block_of_p = ceil(p/(double)sqr);
	
	blocks[block_of_p].clear();
	for(int i = ((block_of_p-1)*sqr)+1;i<=(block_of_p*sqr) && i<=n;i++){
		blocks[block_of_p].push_back(arr[i]);
	}
	sort(blocks[block_of_p].begin(),blocks[block_of_p].end());

}
int main(){
	File_IO();
	
	scanf("%d %d %d",&n,&m,&u);
	int id = 1;
	sqr = sqrt(n);
	for(int i = 1;i<=n;i++){
		scanf("%d",&arr[i]);
		
		blocks[id].push_back(arr[i]);
		if(i%sqr==0){
			sort(blocks[id].begin(),blocks[id].end());
			id++;
		}
	}
	sort(blocks[id].begin(),blocks[id].end());

	while(m--){
		int l,r,u,p;
		scanf("%d %d %d %d",&l,&r,&u,&p);
		update(l,r,u,p);
	}
	for(int i = 1;i<=n;i++){
		printf("%d\n",arr[i]);
	}
}