#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1e18
#define mod   1000000009
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define N 4
struct  matrix
{
	ll row , col;
	ll mat[N][N];
	//memset(mat,0,sizeof(mat));
	matrix(ll r=0 , ll c=0){
		row=r;
		col = c;
		memset(mat,0,sizeof(mat));
	}
};
int cnt = 0;
matrix multiply(struct matrix &a,struct matrix &b){
	cnt++;
	matrix m(a.row,b.col);
	for(ll i = 0;i<a.row;i++){
		for(ll j = 0;j<b.col;j++){
			ull sum = 0;
			for(ll k = 0;k<b.row;k++){
				sum+=(a.mat[i][k]* b.mat[k][j]);
				sum%=mod;
			}
			m.mat[i][j]=sum;
		}
	}
	return m;
}

std::vector<matrix> v;
void display_matrix(struct matrix m){
	for(ll i = 0;i<m.row;i++){
		for(ll j = 0;j<m.col;j++){
			cout<<m.mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	File_IO();
	struct matrix m(3,3),n(3,1),prod(3,1);

	m.mat[0][0]=1;
	m.mat[0][1]=1;
	m.mat[0][2]=1;
	m.mat[1][0]=1;
	m.mat[2][1]=1;

	n.mat[0][0]=2;
	n.mat[1][0]=1;
	n.mat[2][0]=0;
	//display_matrix(n);
	v.push_back(m);

	for(ll  i = 1;i<60;i++){
		v.push_back(multiply(v[i-1],v[i-1]));
		//display_matrix(v[i]);
		//display_matrix(multiply(v[i],n));
	}
	// for(auto x:v){
	// 	display_matrix(x);
	// }
	ll num;
	while(cin>>num){
		if(num == 0)return 0;
		if(num == 1)cout<<"0"<<endl;
		else if(num == 2)cout<<"1"<<endl;
		else if(num == 3)cout<<"2"<<endl;
		else{

			num-=3;
			struct matrix ans(3,3);

			ll lg = log2(num);
			ans = v[lg];
			num-=(1LL<<lg);

			for(ll k = lg-1;k>=0;k--){
				if((1LL<<k) <= num){
					ans=multiply(v[k],ans);
					num-=1LL<<k;
				}
			}
			prod = multiply(ans,n);
			cout<<prod.mat[0][0]%mod<<endl;
		}
	}
}