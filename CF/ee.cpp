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
std::map<ll, ll> mp;
int  main(){
	#ifndef ONLINE_JUDGE
	read();
	write();
	double t1 = clock();
	#endif
	optimizar;
	int n,k;
	cin>>n>>k;
	int temp;
	std::vector<int> v;
	for(int i = 0;i<n;i++)cin>>temp,v.push_back(temp);
	sort(v.begin(),v.end());
	int cnt = 0;
	while(k>0 && v.size()){

		int idx ;
		int maxi = 0;
		for(int i = 0;i<v.size();i++){
			int up = upper_bound(v.begin(),v.end(),v[i]+5)-v.begin();
			int now = up - i;
			if(now>maxi ){
				maxi = now;
				idx = i;
			}
		}
		cnt+=maxi;
		//if(v.size())
		v.erase(v.begin()+idx,v.begin()+maxi+idx);
		k--;
		//for(auto x:v)cout<<x<<" ";
		//	cout<<endl;
	}
	cout<<cnt<<endl;
	#ifndef ONLINE_JUDGE
	double t2 = clock();
	printf("%.10lf\n", (t2-t1));
	#endif
	return 0;
}