#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100001000
#define mod  1000
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
typedef long long ll;
using namespace std;


int main(){
	File_IO();
	optimizar;
	int n;
	cin>>n;
	int temp;
	int cnt[1001];
	memset(cnt,0,sizeof(cnt));
	for(int i = 0;i<n*n;i++)cin>>temp, cnt[temp]++;
	
	int idx = 1;
	int arr[n][n];
	int mat[n][n];
	memset(mat,0,sizeof(mat));
	memset(arr,0,sizeof(arr));

	
	for(int i = 0;i<(n+1)/2;i++){
		for(int j = 0;j<n;j++){
			if(arr[i][j])continue;
			if(arr[i][j] || arr[i][n-j-1] || arr[n-i-1][j] || arr[n-i-1][n-j-1])continue;
			arr[i][j]=arr[i][n-j-1]=arr[n-i-1][j]=arr[n-i-1][n-j-1]=idx++;
		}
	}
	std::vector<pair<int,int> > v[idx];
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			v[arr[i][j]].push_back({i,j});
			//cout<<arr[i][j]<<" ";
		}
		//cout<<endl;
	}

	for(int i = 0;i<idx;i++)unique(v[i].begin(),v[i].end());
		//for(int i = 1;i<=8;i++)cout<<cnt[i]<<" ";

	priority_queue<pair<int,int> > pq;
	for(int i = 0;i<idx;i++)pq.push({v[i].size(),i});
	for(int i = 1;i<idx;i++){
		int need = pq.top().first;
		int now  = pq.top().second;
		pq.pop();
		for(int j = 0;j<=1000;j++){
			if(cnt[j]>=need){
				
				cnt[j]-=need;
				for(auto x:v[now]){
					mat[x.first][x.second]=j;
				}
				break;	
			}
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){

			if(!mat[i][j]){cout<<"NO"<<endl;return 0;}
		}
	}
	cout<<"YES"<<endl;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}