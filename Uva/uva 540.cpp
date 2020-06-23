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
int main(){
	File_IO();
	optimizar;
	int ts = 1;
	int n;
	while(cin>>n){
		if(n== 0 )return 0;
		cout<<"Scenario #"<<ts++<<endl;
		std::map<int ,int> mp;
		for(int i = 1;i<=n;i++){
			int k ;
			cin>>k;
			while(k--){
				int temp;
				cin>>temp;
				mp[temp]=i;
			}
		}
		queue <int> q[n+1];
		queue<int> team;
		//for(int i = 1;i<=n;i++)team.push(i);
		string line;
		map<int,bool>name;
		while(cin>>line)
		{
			int val;
			if(line=="STOP")break;
			if(line=="ENQUEUE"){
				//int val ;
				cin>>val;
				q[mp[val]].push(val);
				if(name[mp[val]])continue;
				else team.push(mp[val]);
			}
			if(line=="DEQUEUE"){
				while(q[team.front()].empty()){
					//debug(team.front());

					int a = team.front();
					team.pop();
					team.push(a);
				}
				//cout<<endl;
				int ans = q[team.front()].front();
				cout<<ans<<endl;
				//debug(val);
				q[team.front()].pop();
			}
		}
		cout<<endl;
	}
	

}
