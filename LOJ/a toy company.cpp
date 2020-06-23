#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1000006
#define inf  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
map<string,bool> mp;
int mod(int a){
	if(a<0)a+=26;
	else a%=26;
	return a;
}
string f , s;
bool forbiden[30][30][30],visited[30][30][30];
struct node
{
	int a,b,c,step;
	
}N,F;
int bfs(node N){

	if(forbiden[F.a][F.b][F.c])return -1;
	queue<node> q;
	q.push(N);
	visited[N.a][N.b][N.c] = true;
	N.step =0;
	int val;
	while(!q.empty()){
		node temp = q.front();
		// string str;
		// str+=temp.a+97;
		// str+=temp.b+97;
		// str+=temp.c+97;
		// cout<<str<<endl;
		q.pop();
		if(forbiden[temp.a][temp.b][temp.c])continue;
		if(temp.a == F.a && temp.b == F.b && temp.c == F.c){
			//cout<<temp.a<<temp.b<<temp.c<<endl;
			//cout<<F.a<<F.b<<F.c<<endl;
			return temp.step;
		}
		val = mod(temp.a + 1);
		if(!visited[val][temp.b][temp.c]){
			node temp1 ;
			temp1.a = val;
			temp1.b = temp.b;
			temp1.c = temp.c;
			temp1.step = temp.step+1;
			visited[val][temp.b][temp.c] = true;
			q.push(temp1);
		}

		val = mod(temp.a - 1);
		if(!visited[val][temp.b][temp.c]){
			node temp1 ;
			temp1.a = val;
			temp1.b = temp.b;
			temp1.c = temp.c;
			temp1.step = temp.step+1;
			visited[val][temp.b][temp.c] = true;
			q.push(temp1);
		}

		val =mod(temp.b + 1);
		if(!visited[temp.a][val][temp.c]){
			node temp1 ;
			temp1.a = temp.a;
			temp1.b = val;
			temp1.c = temp.c;
			temp1.step = temp.step+1;
			visited[temp.a][val][temp.c] = true;
			q.push(temp1);
		}
		val = mod (temp.b -1);
		if(!visited[temp.a][val][temp.c]){
			node temp1 ;
			temp1.a = temp.a;
			temp1.b = val;
			temp1.c = temp.c;
			temp1.step = temp.step+1;
			visited[temp.a][val][temp.c] = true;
			q.push(temp1);
		}


		val =mod(temp.c + 1);
		if(!visited[temp.a][temp.b][val]){
			node temp1 ;
			temp1.a = temp.a;
			temp1.b = temp.b;
			temp1.c = val;
			temp1.step = temp.step+1;
			visited[temp.a][temp.b][val] = true;
			q.push(temp1);
		}
		val =mod(temp.c - 1);
		if(!visited[temp.a][temp.b][val]){
			node temp1 ;
			temp1.a = temp.a;
			temp1.b = temp.b;
			temp1.c = val;
			temp1.step = temp.step+1;
			visited[temp.a][temp.b][val] = true;
			q.push(temp1);
		}

	}
	return -1;

}
int main(){
	File_IO();
	int t;
	cin>>t;
	for(int ts = 1;ts<=t;ts++){
		memset(forbiden,0,sizeof(forbiden));
		memset(visited,0,sizeof(visited));
		cin>>f>>s;
		int m;
		cin>>m;
		string a ,b ,c ;
		for(int i = 0;i<m; i++){
			cin>>a >> b>> c;
			for(int j = 0; j < a.size(); j++){
				for(int k = 0; k < b.size(); k++){
					for(int L = 0; L <= c.size(); L++){
						forbiden [a[j]-'a'] [b[k]-'a'] [c[L]-'a'] = true;
					}
				}
			}
		}
		N.a = f[0]-97;	
		N.b = f[1]-97;	
		N.c = f[2]-97;
		N.step = 0;
		F.a = s[0]-97;	
		F.b = s[1]-97;	
		F.c = s[2]-97;
		F.step = 0;
		printf("Case %d: %d\n", ts,bfs(N));
	}
}