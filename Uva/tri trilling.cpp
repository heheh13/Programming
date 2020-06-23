#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10105
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
int mat[3][mx];
int n;
bool complete(){
	for(int i = 1;i<=3;i++){
		for(int j = 1;j<=n;j++){
			if(mat[i][j]==0)return false;
		}
	}
	return true;
}
void display(){
	for(int i = 1;i<=3;i++){
		for(int j = 1;j<=n;j++){
			cout<<mat[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
int ways(int x , int y){
	//dbg(x,y);
	display();
	///if(y>n)x++;
	//if(x>3)y++;
	if(x>=3){
		if(complete())return 1;
		return 0;
	}
	int ans = 0;
	for(int j = 1;j<=3;j++){

		for(int i = y;i<=n;i+=2){
			mat[j][i]=1;
			mat[j][i+1]=1;
			ways(j,i+2);
			//mat[x][i]=0;
			//mat[x][i+1]=0;
		}
		mat[j][y]=1;
		mat[j+1][y]=1;
		ways(j+1,y);
		//mat[x][y]=1;
		//mat[x+1][y]=1;
	}
	return ans ;
}
int main(){
	File_IO();
	cin>>n;
	cout<<ways(1,1)<<endl;
}
