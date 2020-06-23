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
int main(){
    File_IO();
    int n;
    cin>>n;
    int left[n],right[n],val[n];
    for(int i = 0;i<n;i++){
        cin>>left[i];
    }
    for(int i = 0;i<n;i++){
        cin>>right[i];
    }
    for(int i = 0;i<n;i++){
        val[i]=n-(left[i]+right[i]);
    }
    bool flag = true;
    for(int i = 0;i<val[i];i++){
        int lft = 0, rft =0;
        for(int j = i-1;j>=0;j--){
            if(val[j]>val[i])
                lft++;
        }
        for(int j = i+1;j<n;j++)
        {
            if(val[j]>val[i])
                rft++;
        }
        if(lft == left[i] && rft == right[i] ){
            continue;
        }
        else {
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
        for(int i = 0;i<n;i++)
            cout<<val[i]<< " ";
    }
    else cout<<"NO"<<endl;
}



