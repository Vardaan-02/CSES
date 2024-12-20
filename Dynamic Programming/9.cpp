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

vector<int> danda(N,0);
vector<int> nodanda(N,0);

void precalc(){
    danda[1] = 1;
    nodanda[1] = 1;
    for(int i=2 ; i<N-5 ; i++){
        danda[i] = (danda[i-1]*4) + nodanda[i-1];
        danda[i] %= M;
        nodanda[i] = danda[i-1] + nodanda[i-1]*2;
        nodanda[i] %= M;
    }
}

void solve(){
    int n;
    cin >> n;
    cout << (danda[n]+nodanda[n])%M << endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precalc();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}