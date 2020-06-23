#include<bits/stdc++.h>
using namespace std;
int n,m;
int coin[1000];
int make[1000];
int coinchange(int value,int index){
	if(value==0)return 1;
	if(index>=m)return 0;
	cout<<value<<" "<<index<<endl;
	int ways =0;
	for(int i = 0;i<m;i++){
		if(value-coin[i]>=0)
		ways+=coinchange(value-coin[i],i+1);
	}
	return ways;
}
int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>m;
	for(int  i =0;i<m;i++)
		cin>>coin[i];
	cout<<coinchange(n,0);
}
