#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100000
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
map<char,int>mp;
int main(){
	File_IO();
	int n;
	string a,b;
	cin>>n;
	cin>>a>>b;
	
	int ans = 0;
	for(int i = 0;i<n-i-1;i++){
		mp.clear();
		mp[a[i]]++;mp[a[n-i-1]]++;
		mp[b[i]]++;mp[b[n-i-1]]++;
		if(mp.size()==4){
			ans+=2;
			continue;
		}

		if(mp.size()==3){
			if(a[i]==a[n-i-1])ans+=2;
			else
			ans++;
			continue;
		}
		if(mp.size()==2){
			if(mp[a[i]]==2)continue;
			ans++; 
			continue;
		}
	}
	if(n&1 && a[n/2]!=b[n/2])ans++;
	cout<<ans<<endl;
}