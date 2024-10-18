#include<bits/stdc++.h>
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
#define r(x) {cout<<x<<endl;return;}

const int M = 1e9+7;
const int N = 1e5+10;

void precalc(){}

void solve(){
	string s;
    cin >> s;
    int prev = -1;
    int count = 0;
    int ans = 0;
    for(int i=0 ; i<s.length() ; i++){
        if(s[i]==prev) count++;
        else{
            ans = max(ans,count);
            count = 1;
            prev = s[i];
        }
    }
    r(max(ans,count));
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	precalc();
	// int t;
	// cin >> t;
	// while(t--){
		solve();
	// }
	return 0;
}