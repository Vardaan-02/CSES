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

int binarySearch(vector<vector<int>>& v,int target,int n){
    int s = 0;
    int e = n;
    int mid = s+(e-s)/2;
    int ans = -1;
    while(s<=e){
        mid = s+(e-s)/2;
        if(v[mid][0]<target){
            ans = mid;
            s = mid+1;
        }
        else e = mid-1;
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(3,0));
    for(int i=0 ; i<n ; i++) cin >> v[i][1] >> v[i][0] >> v[i][2];
    sort(v.begin(),v.end());
    vector<int> dp(n+1,0);
    for(int i=1 ; i<=n ; i++){
        dp[i] = dp[i-1];
        int index = binarySearch(v,v[i-1][1],i-1);
        if(index!=-1) dp[i] = max(dp[i],v[i-1][2]+dp[index+1]);
        else dp[i] = max(dp[i],v[i-1][2]);
    }
    cout << dp[n];
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