#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
using ll = long long;
using VL=vector<ll>;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
const long long INF =  999999999;



class Backet{
  int n,sqrtN,B;
  vector<int> val,backet;
public:
  //val(a) はvalをaで初期化したという意味
  Backet(vector<int> a):val(a){
    n=a.size();sqrtN=ceil(sqrt(n));
    B=(n+sqrtN-1)/sqrtN;

    backet.resize(B,INF);
    REP(i,B){
      FOR(j,sqrtN*i,sqrtN*(i+1)){
        if(j>=n)break;
        backet[i]=min(backet[i],val[j]);
      }
    }
  }
};

int RMQ(int l,int r){
  int L=(l+sqrtN)
}
