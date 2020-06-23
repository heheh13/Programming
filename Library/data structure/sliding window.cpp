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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(){
	File_IO();
	int n,h,b,e;
	while(scanf("%d%d%d%d",&n,&h,&b,&e)!=EOF){

		int cost[n+h+10];
		for(int i = 0;i<h;i++)cost[i]=INT_MAX;
		for(int i = h;i<n+h;i++)scanf("%d",&cost[i]);
		deque<pair<int,int> > deq;
		deq.push_back({cost[0],h-1});
		int index[n+h+10];
		memset(index,0,sizeof(index));
		for(int i = h;i<n+h;i++){
			if(!deq.empty() && abs(deq.front().second - i) >=h)deq.pop_front();
			while( !deq.empty() && deq.front().first>=cost[i])deq.pop_front();
			deq.push_back({cost[i],i});
			//cout<<deq.front().first<<" ";
			index[deq.front().second]++;
		}
		printf("%d",index[b+h-1]);
		for(int i = b+h ; i<e+h;i++){
			printf(" %d",index[i]);
		}
		printf("\n");
	}

}