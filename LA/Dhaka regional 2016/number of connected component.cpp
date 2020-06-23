#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1000106
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int arr[mx],par[mx];
int find(int n){
	return par[n]==n ? n :par[n] = find(par[n]);
}
void unionset(int a,int b){
	int x = find(a);
	int y =find(b);
	if(x==y)return ;
	par[y]=x;
}
int main(){
	File_IO();
	int t;
	scanf("%d",&t);
	for(int ts = 1;ts<=t;ts++){
		printf("Case %d: ",ts);
		//memset(arr,0,sizeof(arr));
		memset(par,0,sizeof(par));
		int n;
		scanf("%d",&n);
		int one = 0;
		for(int i = 0;i<n;i++){
			scanf("%d",&arr[i]);
			par[arr[i]]=arr[i];
			if(arr[i]==1)one++;
		}
		std::vector<int > v;
		sort(arr,arr+n);
		// for(int i = 0;i<n;i++)cout<<arr[i]<<" ";
		// 	cout<<endl;
		int p = 0;
		while(arr[p]<2){
			p++;
		}
		v.push_back(arr[p]);
		for(int i = p+1;i<n;i++){
			//cout<<arr[i]<<" ";
			int x = find(arr[i]);
			bool flag = false;
			for(int j = 0;j<v.size();j++){
				x=find(arr[i]);
				///dbg(x,arr[i]);
				if(x==v[j]){
					flag = true;
					continue;
					
				}
				else if( __gcd(arr[i],v[j]) >=2 && par[x]!=x){
					//v[j]=par[x];
					unionset(par[x],v[j]);
					v[j]=arr[i];
					flag=true;
				}
				else if( __gcd(arr[i],v[j]) >= 2){
					v[j]=arr[i];
					unionset(par[x],v[j]);
					flag=true;

				}
			}
			if(!flag)v.push_back(x);
		}
		int hell=0;
		map<int,int>xp;
		// for(int i = 0;i<n;i++)dbg(arr[i],par[arr[i]]);
		// 	cout<<endl;
		for(int i = 0;i<v.size();i++)v[i]=find(v[i]);
		//for(int i = 0;i<v.size();i++)v[i]=find(v[i]);
		for(int i = 0;i<v.size();i++){
			//dbg(v[i],par[v[i]]);
			xp[par[v[i]]]=1;
		}
		printf("%d\n",xp.size()+one);

	}
	
}