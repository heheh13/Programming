#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 10005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;

int main(){
	File_IO();
	int n,d,k;
	cin>>n>>d>>k;
	if(n<=d){
		cout<<"NO"<<endl;
		return 0;
	}
	int deg[n+5];
	int dep[n+5];
	memset(deg,0,sizeof(deg));
	memset(dep,0,sizeof(dep));
	std::vector<int> v[n+10];

	int p = d+1;
	queue<int>q;
	for(int i = 1;i<=d+1;i++){
		dep[i]=max(abs(1-i),abs(p-i));
		q.push(i);
		//cout<<dep[i]<<" ";
	}
	for(int i = 1;i<=d;i++)
	{
		v[i].push_back(i+1);
		deg[i]++;
		deg[i+1]++;
	}

	int x = d+2;
	while(!q.empty()){
		if(x>n)break;
		int fnt = q.front();
		if(deg[fnt]>=k || dep[fnt]>=d)q.pop();
		else {
			deg[fnt]++;
			deg[x]++;
			dep[x]=dep[fnt]+1;
			q.push(x);
			v[fnt].push_back(x);
			x++;
			
		}
	}

	if(x<=n){
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i = 0;i<n;i++){
		if(deg[i]>k || dep[i]>d){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<v[i].size();j++)cout<<i<<" "<<v[i][j]<<endl;
	}

}