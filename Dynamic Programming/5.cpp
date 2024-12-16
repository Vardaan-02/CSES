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

void precalc(){
    for(int i=0 ; i<10 ; i++) ans[i] = 1;
    for(int i=10 ; i<1e6+5 ; i++){
        int temp = i;
        while(temp!=0){
            int digit = temp%10;
            temp /= 10;
            ans[i] = min(ans[i],1+ans[i-digit]);
        }
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