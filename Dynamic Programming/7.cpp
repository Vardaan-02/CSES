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

vector<int> ans(1e6+10,1e9);

void precalc(){}

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> price(n);
    vector<int> pages(n);
    vin(price);
    vin(pages);
    
    vector<vector<int>> dp(n+5,vector<int>(k+10,0));

    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<=k ; j++){
            dp[i][j] = dp[i-1][j];
            if(j>=price[i-1]) dp[i][j] = max(dp[i][j],pages[i-1]+dp[i-1][j-price[i-1]]);
        }
    }

    cout << *max_element(dp[n].begin(),dp[n].end());
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