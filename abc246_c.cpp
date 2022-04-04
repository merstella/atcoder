#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
template<class T> using MaxHeap = priority_queue<T, vector<T>,    less<T>>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
const int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1}; // for adjacent traversal use the first 4 elements
const int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

// Debugging:
void __print(int x) { std::cerr << x; }
void __print(ll x) { std::cerr << x; }
void __print(float x) { std::cerr << x; }
void __print(double x) { std::cerr << x; }
void __print(ld x) { std::cerr << x; }
void __print(char x) { std::cerr << '\'' << x << '\''; }
void __print(const char *x) { std::cerr << '\"' << x << '\"'; }
void __print(const std::string &x) { std::cerr << '\"' << x << '\"'; }
void __print(bool x) { std::cerr << (x ? "true" : "false"); }
template<typename T, typename V>
void __print(const std::pair<T, V> &x) { std::cerr << '{'; __print(x.first); std::cerr << ','; __print(x.second); std::cerr << '}'; }
template<typename T>
void __print(const T &x) { int f = 0; std::cerr << '{'; for (auto &i : x) std::cerr << (f++ ? "," : ""), __print(i); std::cerr << "}"; }
void _print() { std::cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) std::cerr << ", "; _print(v...); }
#define debug(x...) std::cerr << "[" << #x << "] = [", _print(x)

#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const int maxN = 1e5 + 2;
const int MOD[2] = {1000000007, 998244353};
const int INF = 0x3f3f3f3f;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    MaxHeap<int> h;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        h.push(a);
    }
    ll ans = 0;
    while (k > 0) {
        if (h.size() == 0) break;
        int t = h.top(); h.pop();
        int need = t / x;
        if (need == 0) {
            k--;
            continue;
        }
        if (k >= need) {
            k -= need;
            h.push(t - need * x);
        }
        else {
            h.push(t - k * x);
            break;
        }
    }
    while (h.size()) {
        ans += h.top(); h.pop();
    }
    cout << ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    // freopen("main.inp", "r", stdin);
    // freopen("main.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
// -~.-~-.-~-| Eustia Tia Astraea |-~.-~-.-~-
