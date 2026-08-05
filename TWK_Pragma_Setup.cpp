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






signed main() {
    //code here
    
    
    
    //end code

    //set up by Youtuber_TWK
}
