#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int  main()
{
    ll n,m;
    scanf("%lld %lld",&n,&m);
    ll sum[n+5];
    ll arr[n+1];
    sum[0]=0;
    for(ll i = 1; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
        sum[i]=sum[i-1]+arr[i];
    }
    if(n==1)
    {
        printf("%lld\n",m);
        return 0;
    }
    for(ll i = 1; i<=n; i++)
    {
        ll a = sum[n]-arr[i]+m;
        ll b = sum[n]-sum[i];
        ll c = sum[i-1];
        printf("%lld ",max(a,max(b,c)));
    }

}
