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
 
vector<int> ans(1e6+10,0);

void precalc(){
    ans[0] = 0; ans[1] = 1; ans[2] = 2; ans[3] = 4; ans[4] = 8; ans[5] = 16; ans[6] = 32;
    for(int i=7 ; i<1e6+5 ; i++){
        ans[i] += ans[i-1];
        ans[i] %= M;
        ans[i] += ans[i-2];
        ans[i] %= M;
        ans[i] += ans[i-3];
        ans[i] %= M;
        ans[i] += ans[i-4];
        ans[i] %= M;
        ans[i] += ans[i-5];
        ans[i] %= M;
        ans[i] += ans[i-6];
        ans[i] %= M;
    }
}

void solve(){
    int n;
    cin >> n;
    cout << ans[n];
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