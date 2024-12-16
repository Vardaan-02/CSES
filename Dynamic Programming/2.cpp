#include <bits/stdc++.h>
 
using namespace std;
 
// #define int long long int
// #define double long double
// #define INT_MAX LLONG_MAX
// #define INT_MIN LLONG_MIN
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define vpin(a) for(int i=0;i<(a).size();i++)cin>>a[i].first>>a[i].second;
#define vpout(a) for(int i=0;i<a.size();i++)cout<<a[i].first<<' '<<a[i].second<<endl;cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define r(x) {cout<<x<<'\n';return;}
 
const int M = 1000000007;
const int N = 1e5+10;
 
void precalc(){}
 
void solve(){
    int n , k;
    cin >> n >> k;
    vector<int> coins(n);
    vin(coins);
    vector<int> ans(1e6+5,1e9);
    for(int i=0 ; i<n ; i++) ans[coins[i]] = 1;
    for(int i=0 ; i<=k+5 ; i++) for(int j=0 ; j<n ; j++) if(i-coins[j]>=0) ans[i] = min(ans[i],ans[i-coins[j]]+1);
    if(ans[k]==(int)1e9) cout << -1 ; else cout << ans[k];
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precalc();
    // int t;
    // cin >> t;
    // while(t--){
        solve();
    // }
    return 0;
}