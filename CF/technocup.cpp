#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 50005
#define mod  100000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
void File_IO () {
  #ifndef ONLINE_JUDGE
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int main(){
	#ifndef ONLINE_JUDGE
	read();
	write();
	double t1 = clock();
	#endif
	int a,b;
	char ch;
	cin>>a>>ch>>b;
	int temp1 = a*60 + b;
	int c,d;
	cin>>c>>ch>>d;
	int temp2 = c*60 + d;
	int now = (temp2+temp1)/2;
	int h = now/60;
	int m = now%60;
	if(h<10)cout<<"0";
	cout<<h<<":";
	if(m<10)
		cout<<"0";
	cout<<m<<endl;


	#ifndef ONLINE_JUDGE
	double t2 = clock();
	printf("%.10lf\n", (t2-t1));
	#endif
	return 0;
}