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
#define F first
#define S second
#define ll long long
#define ull unsigned ll
#define ld long double
#define pii pair<ll,ll>
#define map map<ll,ll>
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

//Buff
string Tich(ll a,ll b){string d="";ll x=0;while(a!=0){ll k=(a%10)*b+x;a/=10,x=k/10;d=char(k%10+48)+d;}if(x>0)d=to_string(x)+d;return d;}
string TICHv2(string a,string b){ll n=a.length(),m=b.length(),d=0;string s(n+m,'0');rev(i,n-1,0)rev(j,m-1,0){s[i+j+1]=(((a[i]-'0')*(b[j]-'0'))+(s[i+j+1]-'0')%10)+'0';s[i+j]+=((a[i]-'0')*(b[j]-'0'))+(s[i+j+1]-'0')/10;}while(d<s.length()&&s[d]=='0')++d;return d==s.length()?"0":s.substr(d);}
string TICHv3(string a,string b){ll n=a.sz,m=b.sz;string kq="";bool xoa0=true;vl v(n+m,0);rev(i,n-1,0)rev(j,m-1,0){ll sum=(a[i]-'0')*(b[j]-'0')+v[i+j+1];v[i+j+1]=sum%10;v[i+j]+=sum/10;}for(ll x:v){if(x==0&&xoa0)continue;xoa0=false;kq+=char(x+'0');}return kq.empty()?"0":kq;}
string Tong(string a,string b){string d="";ll x=0;while(a.sz<b.sz)a='0'+a;while(a.sz>b.sz)b='0'+b;for(ll i=a.sz-1;i>=0;--i){ll tong=a[i]+b[i]+x-96;d=char(tong%10+48)+d;x=tong/10;}if(x==1)d='1'+d;return d;}
string Thuong(string a,int b) {string d;ll x=0;rep(i,a.sz,0){x=x*10+int(a[i]-48);d=d+char(x/b+48);x%=b;}while(d.sz>1&&d[0]=='0')d.erase(0,1);return d;}
ll Modulo(string s,ll i) {ll r=0;for(char c:s)r=(r*10+(c-'0'))%i;return r;}
//






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
