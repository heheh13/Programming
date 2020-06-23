#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 3005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int x[mx],y[mx];
std::vector<int> v(40005);

int calc(int x1,int x2, int y1,int y2){
	return ceil(sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2))));
}

int main(){
	File_IO();
	int n,q;
	while(scanf("%d%d",&n,&q)&&n+q){
		for(int i =0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
		for(int i =0;i<n;i++){
			for(int j = 0;j<n;j++){
				int temp = calc(x[i],x[j],y[i],y[j]);
				//debug(temp);
				if(temp<40005)v[temp]++;
			}
		}
		for(int i =1;i<=40004;i++)v[i]+=v[i-1];
		while(q--){
			int r;
			scanf("%d",&r);
			printf("%.2lf\n",(v[r]*1.0)/n*1.0);
		}
		puts("");
		for(int i = 0;i<v.size();i++)v[i]=0;
	}
}