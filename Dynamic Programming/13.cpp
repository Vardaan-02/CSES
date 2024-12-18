#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long int
#define double long double
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define vpin(a) for(int i=0;i<(a).size();i++)cin>>a[i].first>>a[i].second;
#define vpout(a) for(int i=0;i<a.size();i++)cout<<a[i].first<<' '<<a[i].second<<endl;cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define r(x) {cout<<x<<'\n';return;}
 
const int M = 1000000007;
const int N = 1e6+10;

void precalc(){}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    vin(v);

    vector<int> prefix(n+1,0);
    for(int i=0 ; i<n ; i++) prefix[i+1] = prefix[i]+v[i];

    vector<vector<int>> dp(n+1,vector<int>(n+1,-1e9));

    for(int s=n ; s>=0 ; s--){
        for(int e=0 ; e<n ; e++){
            if(s>e) continue ;
            else if(s==e) dp[s][e] = v[s];
            else{
                dp[s][e] = max(dp[s][e],prefix[e+1]-prefix[s]-dp[s+1][e]);
                dp[s][e] = max(dp[s][e],prefix[e+1]-prefix[s]-dp[s][e-1]);
            }
        }
    }

    cout << dp[0][n-1];    
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