#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define dbg1(x) cout<< #x<<" = "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" "<<#z <<" = "<<z<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 200005
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
std::map<ll, ll> mp[63];
ll d , x;
#define inf 100000000

int  main(){
	#ifndef ONLINE_JUDGE
	read();
	write();
	double t1 = clock();
	#endif
	optimizar;
	int ts;
	cin>>ts;
	for(int t = 1;t<=ts;t++){
		cin>>d>>x;
		cout<<"Case "<<t<<": ";
		ll now = 0;
		now += (1LL<<d);
		if(x == 0){
			cout<<"YES 0"<<endl;
			continue;
		}
		if(now == x){
			cout<<"YES ";
			cout<<"1"<<endl ;
			continue;;
		}
		//d--;
		d--;
		int cnt = 1;
		bool flag = false;
		while(d>=0){
			cnt++;
			ll temp1 = now + (1LL<<d);
			ll temp2 = now - (1LL<<d);
			//dbg2(temp1,temp2);
			if(abs(temp1 - x) >=abs(temp2-x))now = temp2;
			else now = temp1;
			//dbg1(now);
			if(now == x){
				flag = true;
				//cout<<cnt<<endl;
				break;
			}
			d--;
		}
		if(flag){
			cout<<"YES "<<cnt<<endl;
		}
		else cout<<"NO"<<endl;
	}
	#ifndef ONLINE_JUDGE
	double t2 = clock();
	printf("%.10lf\n", (t2-t1));
	#endif
	return 0;
}