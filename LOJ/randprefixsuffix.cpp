#include<bits/stdc++.h>
#define read() freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout)
#define debug(x) cout<< #x<<" = "<<x<<endl;
#define dbg(x,y) cout<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define mx 1000006
#define mod  1000000007
void File_IO () {
  #ifndef ONLINE_JUDGE 
  read();write();
  #endif
}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
map<int,int> mp;
int main(){
 
    File_IO();
    srand(time(0));
    string line ;
    for(int i = 0;i<20;i++) {
        line+= (char)(rand()%1 + 97);
    }
    cout<<line.size()<<endl;
    string temp;
    for(int i = 0;i<line.size()-1;i++){
        temp += line[i];
        cout<<temp<<endl;
    }
    
    while(line.size()!=0){
        line.erase(line.begin()+0);
        cout<<line<<endl;
    }
 
}