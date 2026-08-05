#include <bits/stdc++.h>
using namespace std;

void buffIO(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
void file(string x){if(x=="")return;freopen((x+".INP").c_str(),"r",stdin);freopen((x+".OUT").c_str(),"w",stdout);}

template<typename... T>void see(T&... x){((cin>>x),...);}
template<typename... T>void put(T... x){((cout<<x<<" "),...);}
template<typename... T>void putl(T... x){((cout<<x<<" "),...);cout<<'\n';}

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<ll,ll>
#define vl vector<ll>
#define vii vector<pii>
#define vc vector<char>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mkp make_pair
#define umap unordered_map
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz size()
#define SL stoll
#define TS to_string
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define bk back
#define fr front

#define rep(i,n,m) for(ll i=m;i<n;i++)
#define rex(i,n,m) for(ll i=m;i<=n;i++)
#define rev(i,n,m) for(ll i=n;i>=m;i--)

#define bit(x,i) (((x)>>(i))&1)
#define on(x,i) ((x)|(1LL<<(i)))
#define off(x,i) ((x)&~(1LL<<(i)))
#define flip(x,i) ((x)^(1LL<<(i)))

#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define uni(x) x.erase(unique(all(x)),x.end())
#define SUM(x) accumulate(all(x),0LL)
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))

#define BIT(x) __builtin_popcountll(x)
#define PAR(x) __builtin_parityll(x)
#define ZR(x) __builtin_ctzll(x)
#define LZ(x) __builtin_clzll(x)
#define MSB(x) (63-__builtin_clzll(x))

#define PI acos(-1.0)

const ll md=1e9+7;
//const ll md=998244353;
const ll N=1000005;
const ll INF=4e18;
const ll NEG=-INF;


//Buff
string Tich(string a,string b){ll n=a.sz,m=b.sz;string kq="";bool z=1;vl v(n+m);rev(i,n-1,0)rev(j,m-1,0){ll s=(a[i]-48)*(b[j]-48)+v[i+j+1];v[i+j+1]=s%10;v[i+j]+=s/10;}for(ll x:v){if(x==0&&z)continue;z=0;kq+=char(x+48);}return kq==""?"0":kq;}
string Tong(string a,string b){string d="";ll x=0;while(a.sz<b.sz)a='0'+a;while(a.sz>b.sz)b='0'+b;rev(i,a.sz-1,0){ll s=a[i]+b[i]+x-96;d=char(s%10+48)+d;x=s/10;}if(x)d='1'+d;return d;}
string Thuong(string a,ll b){string d="";ll x=0;rep(i,a.sz,0){x=x*10+a[i]-48;d+=char(x/b+48);x%=b;}while(d.sz>1&&d[0]=='0')d.erase(0,1);return d;}
ll Modulo(string s,ll m){ll r=0;for(char c:s)r=(r*10+c-48)%m;return r;}


//template
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll poww(ll a,ll b){ll r=1;while(b){if(b&1)r*=a;a*=a;b>>=1;}return r;}
ll mp(ll a,ll b,ll m=md){ll r=1;a%=m;while(b){if(b&1)r=r*a%m;a=a*a%m;b>>=1;}return r;}
ll iv(ll a,ll m=md){return mp(a,m-2,m);}
ll Ceil(ll a,ll b){return (a+b-1)/b;}
bool snt(ll n){if(n<2)return 0;if(n%2==0)return n==2;for(ll i=3;i*i<=n;i+=2)if(n%i==0)return 0;return 1;}
bool _P[N];ll _F[N];ll fac[N],inv[N];vl pri;
void sang(ll n=N-1){fill(_P,_P+n+1,1);_P[0]=_P[1]=0;for(ll i=2;i*i<=n;i++)if(_P[i])for(ll j=i*i;j<=n;j+=i)_P[j]=0;rep(i,n+1,2)if(_P[i])pri.pb(i);}
void sf(ll n=N-1){rep(i,n+1,0)_F[i]=i;for(ll i=2;i*i<=n;i++)if(_F[i]==i)for(ll j=i*i;j<=n;j+=i)if(_F[j]==j)_F[j]=i;}
vl F(ll x){vl v;while(x>1)v.pb(_F[x]),x/=_F[x];return v;}
void cb(ll n=N-1){fac[0]=1;rep(i,n+1,1)fac[i]=fac[i-1]*i%md;inv[n]=iv(fac[n]);rev(i,n,1)inv[i-1]=inv[i]*i%md;}
ll C(ll n,ll k){return k<0||k>n?0:fac[n]*inv[k]%md*inv[n-k]%md;}
ll bitc(ll x){return __builtin_popcountll(x);}
ll lg(ll x){return x?63-__builtin_clzll(x):-1;}
template<class T>bool mn(T&a,T b){return b<a?(a=b,1):0;}
template<class T>bool mx(T&a,T b){return b>a?(a=b,1):0;}
ll dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
ll dx8[8]={-1,-1,-1,0,0,1,1,1},dy8[8]={-1,0,1,-1,1,-1,0,1};
//

//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//ll Rand(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}





signed main(){
    buffIO();
    file("");

    //code here
    
    
    
    
    //end code
    #ifdef LOCAL
    clock_t tStart=clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<'\n';
    #endif

    //set up by Youtuber_TWK
}
