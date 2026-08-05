//#pragma GCC optimize ("Ofast","O3","Ofast","unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//#pragma comment(linker, "/STACK:200000000")
//#pragma GCC optimize("inline,fast-math,unroll-loops,tree-vectorize,jump-threading")
//#pragma GCC optimize("no-stack-protector,no-math-errno,strict-overflow")

#include <bits/stdc++.h>
using namespace std;


#if defined(__GNUC__) && (defined(__AVX2__) || defined(__SSE2__))
    #pragma GCC optimize("Ofast")
#endif
#if defined(__GNUC__) && (defined(__AVX2__) || defined(__SSE2__))
    #pragma GCC optimize("O3")
#endif
#if defined(__GNUC__) && (defined(__AVX2__) || defined(__SSE2__))
    #pragma GCC optimize("unroll-loops")
#endif
#if defined(__GNUC__) && (defined(__POPCNT__))
    #pragma GCC optimize("popcnt")
#endif
#if defined(__GNUC__) && (defined(__AVX2__) || defined(__SSE2__))
    #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif
#if defined(__GNUC__) && (defined(__BMI__) || defined(__BMI2__))
    #pragma GCC target("bmi,bmi2")
#endif
#if defined(__GNUC__) && defined(__AVX2__)
    #pragma GCC target("avx2")
#endif
#if defined(__GNUC__) && defined(__POPCNT__)
    #pragma GCC target("popcnt")
#endif
#if defined(__GNUC__) && defined(__LZCNT__)
    #pragma GCC target("lzcnt")
#endif
#if defined(__GNUC__) && (defined(__AVX2__) || defined(__SSE2__))
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("O3")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC optimize("popcnt")
    #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif
#if defined(__GNUC__)
    #pragma GCC optimize("inline")
#endif
#if defined(__GNUC__) && (defined(__AVX2__) || defined(__SSE2__))
    #pragma GCC optimize("fast-math")
#endif
#if defined(__GNUC__) && (defined(__AVX2__) || defined(__SSE2__))
    #pragma GCC optimize("tree-vectorize")
#endif
#if defined(__GNUC__)
    #pragma GCC optimize("jump-threading")
#endif
#if defined(__GNUC__)
    #pragma GCC optimize("no-stack-protector")
#endif
#if defined(__GNUC__)
    #pragma GCC optimize("no-math-errno")
#endif
#if defined(__GNUC__)
    #pragma GCC optimize("strict-overflow")
#endif
#if defined(__GNUC__) && (defined(__AVX2__) || defined(__SSE2__))
    #pragma GCC optimize("fast-math")
    #pragma GCC optimize("tree-vectorize")
#endif
#if defined(__GNUC__) && defined(__SSE2__)
    #pragma GCC target("sse2,popcnt")
#endif
#if defined(_MSC_VER)
    #pragma comment(linker, "/STACK:200000000")
#endif


template<typename... T>
void see(T&... args) {((cin>>args),...);}
template<typename... T>
void gsee(T&... args) {((getline(cin,args)),...);}
template<typename... T>
void put(T&&... args) {((cout<<args<<" "),...);}
template<typename... T>
void putl(T&&... args) {((cout<<args<<" "),...);cout<<'\n';}
void file(string x){if(x.empty())return;freopen((x+".INP").c_str(),"r",stdin);freopen((x+".OUT").c_str(),"w",stdout);}
void buffIO(bool tieCin=true,bool tieCout=true) {ios_base::sync_with_stdio(false);if(tieCin)cin.tie(0);if(tieCout)cout.tie(0);}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

#define pb push_back
#define mkp make_pair
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define rsz resize
#define ins insert
#define bk back
#define fr front
#define fi first
#define se second

#define ll long long
#define ull unsigned ll
#define ld long double
#define pii pair<ll,ll>
#define mpll map<ll,ll>
#define umap unordered_map
#define vl vector<ll>
#define vii vector<pii>
#define vc vector<char>

#define ERROR cerr<<'\n';
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define putsp(x) cout<<setprecision(x)<<fixed

#define sz size()
#define SL stoll
#define TS to_string

#define seev(v,n) for(ll i=0;i<n;++i){ll x; cin>>x; v.push_back(x);}
#define sees(s,n) for(ll i=0;i<n;++i){ll x; cin>>x; s.insert(x);}
#define seea(n,arr) for(ll i=0;i<n;++i){cin>>arr[i];}
#define rep(i,n,m) for(ll i=m;i<n;++i)
#define rex(i,n,m) for(ll i=m;i<=n;++i)
#define rev(i,n,m) for(ll i=n;i>=m;--i)
#define trav(x,v) for(auto x:v)
#define each(x,v) for(auto &x:v)

#define bit(x,i) (((x)>>(i))&1)
#define on(x,i) ((x)|(1LL<<(i)))
#define off(x,i) ((x)&~(1LL<<(i)))
#define flip(x,i) ((x)^(1LL<<(i)))

#define cnt(x,v) count(all(v),x)
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define uni(x) x.erase(unique(all(x)),x.end())

#define SUM(v) accumulate(all(v),0LL)
#define MAX(v) *max_element(all(v))
#define MIN(v) *min_element(all(v))

#define BIT(x) __builtin_popcountll(x)
#define PAR(x) __builtin_parityll(x)
#define ZR(x) __builtin_ctzll(x)
#define LZ(x) __builtin_clzll(x)
#define MSB(x) (63-__builtin_clzll(x))

#define PI acos(-1.0)
#define gcd __gcd


//Buff
string Tich(string a,string b){ll n=a.sz,m=b.sz;string kq="";bool xoa0=true;vl v(n+m,0);rev(i,n-1,0)rev(j,m-1,0){ll sum=(a[i]-'0')*(b[j]-'0')+v[i+j+1];v[i+j+1]=sum%10;v[i+j]+=sum/10;}for(ll x:v){if(x==0&&xoa0)continue;xoa0=false;kq+=char(x+'0');}return kq.empty()?"0":kq;}
string Tong(string a,string b){string d="";ll x=0;while(a.sz<b.sz)a='0'+a;while(a.sz>b.sz)b='0'+b;for(ll i=a.sz-1;i>=0;--i){ll tong=a[i]+b[i]+x-96;d=char(tong%10+48)+d;x=tong/10;}if(x==1)d='1'+d;return d;}
string Thuong(string a,int b) {string d;ll x=0;rep(i,a.sz,0){x=x*10+int(a[i]-48);d=d+char(x/b+48);x%=b;}while(d.sz>1&&d[0]=='0')d.erase(0,1);return d;}
ll Modulo(string s,ll i) {ll r=0;for(char c:s)r=(r*10+(c-'0'))%i;return r;}
//

const ll md=1e9+7;
//const ll md=998244353;
const ll N=1000005;
const ll INF=4e18;
const ll NEG=-INF;

//template
bool _P[N];ll _F[N];ll _f[N],_i[N];vl _p;
ll g(ll a,ll b){return b?g(b,a%b):a;}
ll l(ll a,ll b){return a/g(a,b)*b;}
ll p(ll a,ll b){ll r=1;while(b){if(b&1)r*=a;a*=a;b>>=1;}return r;}
ll mp(ll a,ll b,ll m=md){ll r=1;a%=m;while(b){if(b&1)r=r*a%m;a=a*a%m;b>>=1;}return r;}
ll iv(ll a,ll m=md){return mp(a,m-2,m);}
bool snt(ll n){if(n<2)return 0;if(!(n&1))return n==2;for(ll i=3;i*i<=n;i+=2)if(n%i==0)return 0;return 1;}
void sang(ll n=N-1){fill(_P,_P+n+1,1);_P[0]=_P[1]=0;for(ll i=2;i*i<=n;i++)if(_P[i])for(ll j=i*i;j<=n;j+=i)_P[j]=0;rep(i,n+1,2)if(_P[i])_p.pb(i);}
void sf(ll n=N-1){rep(i,n+1,0)_F[i]=i;for(ll i=2;i*i<=n;i++)if(_F[i]==i)for(ll j=i*i;j<=n;j+=i)if(_F[j]==j)_F[j]=i;}
vl F(ll x){vl v;while(x>1)v.pb(_F[x]),x/=_F[x];return v;}
void cb(ll n=N-1){_f[0]=1;rep(i,n+1,1)_f[i]=_f[i-1]*i%md;_i[n]=iv(_f[n]);rev(i,n,1)_i[i-1]=_i[i]*i%md;}
ll C(ll n,ll k){return k<0||k>n?0:_f[n]*_i[k]%md*_i[n-k]%md;}
ll bc(ll x){return __builtin_popcountll(x);}
ll lg(ll x){return x?63-__builtin_clzll(x):-1;}
ll Ceil(ll a,ll b){return (a+b-1)/b;}
template<class T>bool mn(T&a,T b){return b<a?(a=b,1):0;}
template<class T>bool mx(T&a,T b){return b>a?(a=b,1):0;}
ll dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
ll dX[8]={-1,-1,-1,0,0,1,1,1},dY[8]={-1,0,1,-1,1,-1,0,1};
//

//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); ll Rand(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}





signed main() {
    buffIO();
    file("");
    //code here
    
    
    
    //end code
    #ifdef LOCAL
    clock_t tStart = clock();
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
    #endif

    //set up by Youtuber_TWK
}
