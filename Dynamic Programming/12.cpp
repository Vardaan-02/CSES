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

    int sum = accumulate(v.begin(),v.end(),0);

    vector<vector<int>> dp(110,vector<int>(sum+1,0));

    dp[0][0] = 1;

    for(int i=0 ; i<110 ; i++) dp[i][0] = 1;

    for(int i=1 ; i<=v.size() ; i++){
        for(int j=sum ; j>=0 ; j--){
            if(dp[i-1][j]) dp[i][j] = 1;
            if(j-v[i-1]>=0 && dp[i-1][j-v[i-1]]) dp[i][j] = 1;
        }
    }

    vector<int> ans;
    for(int i=1 ; i<=sum ; i++) if(dp[n][i]) ans.push_back(i);

    cout << ans.size() << endl;
    vout(ans);
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