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
    int n;
    cin >> n;
    vector<string> v(n);
    vin(v);
    vector<vector<int>> ans(n,vector<int> (n,0));
    
    if(v[0][0]=='.') ans[0][0] = 1;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(v[i][j]=='*') continue;
            if(i>0) ans[i][j] += ans[i-1][j];
            ans[i][j] %= M;
            if(j>0) ans[i][j] += ans[i][j-1];
            ans[i][j] %= M;
        }
    }

    cout << ans[n-1][n-1];
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