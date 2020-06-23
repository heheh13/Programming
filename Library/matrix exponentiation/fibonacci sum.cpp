#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1e18
#define SZ 4
#define sc(a) scanf("%d",&a)
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int mod = 1000000007;
struct  matrix
{
	int  row , col;
	int mat[SZ][SZ];
	matrix(int r=0 , int c=0){
		row=r;
		col = c;
		memset(mat,0,sizeof(mat));
	}
};
std::vector<matrix> v;
void display_matrix(struct matrix m){
	for(int i = 0;i<m.row;i++){
		for(int j = 0;j<m.col;j++){
			cout<<m.mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
matrix multiply(struct matrix &a,struct matrix &b){
	matrix m(a.row,b.col);
	for(int  i = 0;i<a.row;i++){
		for(int j = 0;j<b.col;j++){
			ll sum = 0;
			for(int k = 0;k<b.row;k++){
				sum+=((ll)a.mat[i][k]* (ll)b.mat[k][j]);
				sum%=mod;
			}
			m.mat[i][j]=sum;
		}
	}
	return m;
}


void precalulate(struct matrix &m){
	//powers of two
	v.push_back(m);
	for(int i = 1;i<35;i++){
		v.push_back(multiply(v[i-1],v[i-1]));
	}
	//for(auto x:v)display_matrix(x);
}
int procedure(long long  num,struct matrix &n){
	if(num<0)return 0;
	if(num == 0)return 1;
	struct matrix ans(4,4);
	int lg = log2(num);
	ans = v[lg];
	num-=(1LL<<lg);

	for(int k = lg-1;k>=0;k--){
		if((1LL<<k) <= num){
			ans=multiply(v[k],ans);
			num-=1LL<<k;
		}
	}
	struct matrix prod (4,1);
	prod = multiply(ans,n);
	//display_matrix(prod);
	return prod.mat[2][0];
}
int main(){
	File_IO();
	matrix m(4,4), n(4,1);
	m.mat[0][0] = m.mat[0][1] = m.mat[1][0]=1;
	m.mat[2][0] = m.mat[2][1] = m.mat[2][2]=1;
	m.mat[3][2]=1;
	n.mat[0][0]=1;
	n.mat[2][0]=1;
	// display_matrix(n);
	// display_matrix(m);
	precalulate(m);
	int t ;
	sc(t);
	int a, b;
	for(int ts = 1; ts<= t; ts++){
		sc(a);
		sc(b);
		//dbg(procedure(a-2,n), procedure(b-1,n));
		int res = procedure(b-1,n) - procedure(a-2,n);
		if(res<0)res+=mod;
		printf("%d\n",res);
	}
	return 0;
}