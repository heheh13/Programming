#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1e18
#define SZ 6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int mod =1;
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


void precalulate(struct matrix &m,int lim){
	//powers of two
	v.push_back(m);
	for(int i = 1;i<35;i++){
		v.push_back(multiply(v[i-1],v[i-1]));
	}
	//for(auto x:v)display_matrix(x);
}
void  procedure(long long  num,struct matrix &n){
	struct matrix ans(6,6);
	if(num==0)return ;
	int lg = log2(num);
	ans = v[lg];
	num-=(1LL<<lg);

	for(int k = lg-1;k>=0;k--){
		if((1LL<<k) <= num){
			ans=multiply(v[k],ans);
			num-=1LL<<k;
		}
	}
	struct matrix prod (6,1);
	prod = multiply(ans,n);
	printf("%d %d\n",prod.mat[0][0],prod.mat[3][0]);
	return ;
}

int  main(){
	File_IO();
	matrix m(6,6),n(6,1);
	int f[3],g[3],fc[3],gc[3];
 	int q,num;
 	int t ;
 	scanf("%d",&t);
 	for(int ts = 1;ts<=t ;ts++){
 		v.clear();
 		//a1b1c1
		for(int i = 0;i<3;i++)scanf("%d",&fc[i]);
		for(int i = 0;i<3;i++)scanf("%d",&gc[i]);
		for(int i = 0;i<3;i++)scanf("%d",&f[i]);
		for(int i = 0;i<3;i++)scanf("%d",&g[i]);

		///build matrix;
		for(int i =0,x=2;i<3;i++,x--)n.mat[i][0]=f[x];
		for(int i = 3,x=2;i<6;i++,x--)n.mat[i][0]=g[x];
		//display_matrix(n);
		m.mat[0][0] = fc[0] ; m.mat[0][1]=fc[1] ;m.mat[0][5]=fc[2];
		m.mat[1][0] = 1;
		m.mat[2][1] = 1;

		m.mat[3][2] = gc[2] ; m.mat[3][3]=gc[0],m.mat[3][4]=gc[1];
		m.mat[4][3] =1;
		m.mat[5][4]= 1;
		//display_matrix(m);
		//end of preprocess;
		scanf("%d",&mod);
	 	scanf("%d",&q);
	 	for(int i = 0;i<m.row;i++){
	 		for(int j = 0;j<m.col;j++)m.mat[i][j]%=mod;
	 	}
		for(int i = 0;i<n.row;i++){
	 		for(int j = 0;j<n.col;j++)n.mat[i][j]%=mod;
	 	}
		precalulate(m,log2(1e9));
		printf("Case %d:\n",ts );
	 	for(int i = 0;i<q;i++){
	 		
	 		scanf("%d",&num);
	 		if(num<3)printf("%d %d\n",f[num]%mod,g[num]%mod);
	 		else procedure(num-2,n);
	 	}
 	}
}