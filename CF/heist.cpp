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
bool mark[mx];
int  main(){
	File_IO();
	optimizar;
	int n,m,d;
	cin>>n>>m>>d;
	vector<int>arr;
	int brr[n];
	map<int,int>mp;
	for(int i = 0;i<n;i++){
		cin>>brr[i];
		arr.push_back(brr[i]);
		mp[arr[i]]=i+1;
	}
	sort(arr.begin(),arr.end());
	int ans[mx];
	int day;
	for(day = 1;day<=n;day++){
		if(arr.size()==0)break;
		int key = arr[0];
		//dbg(key,day);
		ans[mp[arr[0]]]=day;
		arr.erase(arr.begin()+0);
		
		for(int i = 0;i<arr.size();i++){
			if(arr[i]>key+d){
				key = arr[i];
				ans[mp[arr[i]]]=day;
				arr.erase(arr.begin()+i);
			}
		}
	}
	cout<<day-1<<endl;
	for(int i = 1;i<=day;i++)
		cout<<ans[i]<<" ";
}