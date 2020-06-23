#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 100005
#define mod  6
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
int arr[mx];
bool valid(std::vector<char> &v){
	stack<int> s;
	for(int i = 0;i<v.size();i++){
		if(v[i]=='(')s.push(1);
		else{
			if(!s.empty()){
				s.pop();
			}
			else{
				return false;
			}
		}
	}
	if(!s.empty()) return false;
	return true;
}
int main(){
	File_IO();
	int t;
	scanf("%d",&t);
	for(int ts = 1;ts<=t;ts++){
		printf("Case %d: ",ts);
		memset(arr,0,sizeof(arr));		
		int n;
		scanf("%d",&n);
		int maxi = 0;
		int mini = 0;
		for(int i = 0;i<n;i++){
			int temp;
			scanf("%d",&temp);
			maxi = max(temp,maxi);
			mini=min(temp,mini);
			if(temp<=n/2&&temp>=0)
				arr[temp]++;
		}
		if(n&1||maxi>n/2||mini<0){
			printf("invalid\n");
			continue;
		}
		int current=0 ;
		std::vector<char> v;
		if(arr[1]>0){
			current = 1;
			arr[1]--;
			v.push_back('(');
		}
		else{
			printf("invalid\n");
			continue;
		}
		while(1){
			if(arr[current+1]>0&&current+1<=n/2){
				arr[current+1]--;
				current+=1;
				v.push_back('(');
			}
			else if(arr[current-1]>0&&current-1>=0){
				arr[current-1]--;
				current-=1;
				v.push_back(')');
			}
			else break;
		}
		if(valid(v)&&v.size()==n){

			for(int i = 0;i<v.size();i++)printf("%c",v[i]);
				printf("\n");
		}
		else{
			printf("invalid\n");
 
		}
	}
}