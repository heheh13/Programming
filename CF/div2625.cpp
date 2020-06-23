#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 44721
#define mod  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int main(){
	File_IO();
	int t;
	cin>>t;
	while(t--){
		std::vector<int> v[5005];
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0;i<n;i++)cin>>arr[i],v[arr[i]].push_back(i);
		
		bool found = false;
		for(int i = 0;i<5005;i++){
			if(v[i].size()>=3){
				found = true;
				cout<<"YES"<<endl;
				break;
			}
			else if(v[i].size()>=2){
				for(int j = 1;j<v[i].size();j++){
					if(v[i][j] > v[i][j-1]+1){
						cout<<"YES"<<endl;
						found = true;
						break;
					}
				}
			}
		}
		if(!found)cout<<"NO"<<endl;
		//for(int i = 0;i<5000;i++)v[i].clear();
	}
}