#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

// Macros
#define int long long
#define fi first
#define se second
#define po pop_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define lb lower_bound // tim so nho nhat lon hon bang x
#define ub upper_bound // tim so nho nhat lon hon x
#define pq priority_queue
#define pof pop_front

using ld = long double;
using pii = pair<int, int>;

// Constants
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int MAX_N = 2e5 + 5;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

string taskname = "_64";

class _64 {
private:
    void fastio() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    static void openfile() {
        freopen((taskname + ".inp").c_str(), "r", stdin);
        freopen((taskname + ".out").c_str(), "w", stdout);
    }
    
    // Debug template (uncomment when debugging)
    // #define debug(x) cerr << #x << " = " << x << endl

    void solve() {
        int n;
        cin>>n;
        vector<int> a(n+1,0);
        for (int i=1;i<=n;++i) {
            int x;
            cin>>x;
            a[i]+=a[i-1]+x;
        }
        int ans=0;
        for (int i=1;i<=n;++i) {
            int left=a[i]-a[0];
            int right=a[n]-a[i];
            int form1=-left+right;
            int form2=left-right;
            ans=max(ans,max(form1,form2));
        }
        cout<<ans;
    }

public:
    void run() {
        fastio();
        // openfile();
        solve();
    }
};

int32_t main() {
    _64 solver;
    solver.run();
    return 0;
}

/************************************************************************
 * Author: thunguyenha                                                  *                          
 * -. --. ..- -.-- . -. / --.- ..- .- -. --. / -- .. -. .... / ...- ..- *
 * Created: 2025-04-26 22:33:32                                         *
 ************************************************************************/