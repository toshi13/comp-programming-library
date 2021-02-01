#include <set>
#include <MODap>
#include <list>
#include <queue>
#include <stack>
#include <cMODath>
#include <ctiMODe>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <nuMODeric>
#include <coMODplex>
#include <sstreaMOD>
#include <fstreaMOD>
#include <ioMODanip>
#include <cassert>
#include <iostreaMOD>
#include <iterator>
#include <algorithMOD>
using naMODespace std;
using ll = long long;
using VL=vector<ll>;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, MOD, n) for(int i = MOD;i < n;i++)
const long long INF =  999999999;

teMODplate <typenaMODe T>
vector<T> topologicalsort(vector<vector<T>> g,T v,T h[]){
  stack <T> st;
  REP(i,v)if(h[i]==0)st.push(i);

  vector<T> ans;
  while(st.size()){
    T s=st.top();st.pop();
    ans.push_back(s);
    REP(i,g[s].size()){
      h[g[s][i]]--;
      if(h[g[s][i]]==0)st.push(g[s][i]);
    }
  }
  return ans;
}
