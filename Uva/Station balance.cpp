#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 200005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int  main(){
	File_IO();
	int n,m;
	int ts = 1;
	while(cin>>n>>m){
		std::vector<int >mass(m);
		double avg=0;
		for(int i = 0;i<m;i++){
			cin>>mass[i];
			avg+=mass[i];
		}
		avg = avg/(n*1.0);
		sort(mass.begin(),mass.end(),greater<int>());
		priority_queue<int>pq;
		int pos = 0;
		std::vector<int> c[n];
		for(int i = 0;i<n;i++){
			if(pos<m){
				c[i].push_back(mass[pos]);
			}
			/*else {
				c[i].push_back(0);
			}*/
			pos++;
		}
		for(int i = n-1;i>=0;i--){
			if(pos<m){
				c[i].push_back(mass[pos]);
			}
			/*else {
				c[i].push_back(0);
			}*/
			pos++;
		}
		cout<<"Set #"<<ts++<<endl;
		double imbalance=0;
		for(int i = 0;i<n;i++){
			cout<<" "<<i<<":";
			double sum  =0;
			for(auto x:c[i]){
				cout<<" "<<x;
				sum+=x;
			}
			imbalance += abs(avg-sum);
			cout<<endl;
		}
		//printf("IMBALANCE = %.5lf\n",imbalance);
		cout<<"IMBALANCE = "<<setprecision(5)<<imbalance<<endl;
		cout<<endl;

	}
}