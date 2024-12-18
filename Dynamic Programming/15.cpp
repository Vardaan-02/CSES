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
    vector<int> ans;
    ans.push_back(v[0]);
    for(int i=1 ; i<n ; i++){
        if(v[i]>ans[ans.size()-1]) ans.push_back(v[i]);
        else{
            int index = lower_bound(ans.begin(),ans.end(),v[i]) - ans.begin();
            ans[index] = v[i];
        }
    }

    cout << ans.size();
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