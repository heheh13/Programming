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
std::vector<int> v[mx];
int dist[mx];
std::vector<int> path;
int arr[mx];
map<int,int>mp[mx];
bool visited[mx];
int  visit(int n){
	visited[n]=1;
	int cnt = 0;
	for(auto x:v[n]){
		if(visited[x])continue;
		else{
			cnt++;
		}
	}
	return cnt;
}
int main(){
	File_IO();
	int n;
	int a,b;
	cin>>n;
	for(int i =1;i<n;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
		mp[a][b]=1;
		mp[b][a]=1;
	}
	queue<int> q;	
	for(int i = 0;i<n;i++)cin>>arr[i];
		if(arr[0]!=1){
			cout<<"No"<<endl;
			return 0;
		}
	q.push(1);
	int track = 1;
	while(!q.empty()){
		int fnt = q.front();
		q.pop();
		int x = visit(fnt);
		for(int i = track ;i<track+x;i++){
			if(mp[fnt][arr[i]]){
				q.push(arr[i]);
				continue;
			}
			else{
				cout<<"No"<<endl;
				return 0;
			}
		}
		track+=x;


	}
	cout<<"Yes"<<endl;
}