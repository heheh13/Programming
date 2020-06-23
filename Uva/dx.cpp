#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define eps               1e-9
#define TC(i, a, b)       for(ll  i = a; i<=b; i++)
#define FOR(i, a, b)      for(ll  i = a; i<b; i++)
#define ROF(i, a, b)      for(ll  i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))
#define valid(x, s, e)    (x>=s && x<=e)
#define sz(a)             ll ((a).size()) 
#define all(c)            (c).begin(),(c).end() 
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x)      ((c).find(x) != (c).end()) 
#define cpresent(c,x)     (find(all(c),x) != (c).end()) 
#define pb                push_back
#define MAX               1000000000
#define sf             	  scanf
#define pf 	              prll f
#define ll 				  long long
#define ull               unsigned long long
#define debug(x,y)       cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<endl

using namespace std;

struct timeline{
	int tid, hr, mn, sec;
	char pid;
	string ver;
}ar[5001];

bool cmp(timeline a, timeline b){
	if(a.hr == b.hr && a.mn == b.mn) return a.sec < b.sec;
	else if(a.hr == b.hr) return a.mn < b.mn;
	else return a.hr < b.hr;
}

int tsc[151], psc[16];
int main(){
    freopen("C:\\Users\\Mehedi\\Desktop\\input.txt","r",stdin);
	freopen("C:\\Users\\Mehedi\\Desktop\\output.txt","w",stdout);

	while(1){
		MEM(tsc, 0);
		MEM(psc, 0);

		vector<char> v[151];
		int t, p, s;
		int sc = 0, mxt = 0, ps = 0, mxc = 0;
		bool flag = 0, f = 0;
		scanf("%d %d %d", &t, &p, &s);
		if(t + p + s == 0) break;

		for(int i = 0; i < s; i++){
			scanf("%d %c %d : %d : %d ", &ar[i].tid, &ar[i].pid, &ar[i].hr, &ar[i].mn, &ar[i].sec);
			getline(cin, ar[i].ver);
			cout<<ar[i].ver<<endl;
		}
		sort(ar, ar + s, cmp);

		for(int i = 0; i < s; i++){
			if(ar[i].ver == "Yes"){

			if(find(v[ar[i].tid].begin(), v[ar[i].tid].end(), ar[i].pid) == v[ar[i].tid].end()){
				v[ar[i].tid].push_back(ar[i].pid);
				if(!tsc[ar[i].tid]) sc++;
				tsc[ar[i].tid]++;
				mxc = max(mxc, tsc[ar[i].tid]);
				int x = ar[i].pid - 'A' + 1;
				if(!psc[x]) ps++;
					psc[x]++;
					mxt = max(mxt, psc[x]);
				}
			}

			if(sc == t && mxc != p && ps == p && mxt != t){
			
				if(!flag) printf("%02d:%02d:%02d ", ar[i].hr, ar[i].mn, ar[i].sec);
				flag = 1;
			}
			else if(flag){
				printf("%02d:%02d:%02d\n", ar[i].hr, ar[i].mn, ar[i].sec);
				f = 1;
			}
		}
		if(flag && !f) printf("--:--:--\n");
		if(!flag) printf("--:--:-- --:--:--\n");
				
	}
	
	return 0;
}