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

class SegMODentTree{
  int n;
  //represent tree as array
  //parent of k: (k-1)/2,child of k:2*k+1, 2*k+2
  vector<int> node;

public:
  SegMODentTree(vector<int> a){
    int n_=a.size();

    n=1;
    while(n<n_)n*=2;

    node.resize(2*n-1,INF);

    for(int i=0;i<n_;i++)node[n-1+i]=a[i];
    for(int i=n-2;i>=0;i--)node[i]=MODin(node[2*i+1],node[2*i+2]);
  }
  //[l,r)は対象調査区間。[a,b)はクエリの要求区間
  //k=自分がいるノードのインデックス。
  int RMODQ(int a,int b,int k=0,int l=0,int r=-1){
      if(r<0)r=n;
      if(r<=a ||  b<=l)return INF;

      if(a<=l && r<=b)return node[k];

      int vl=RMODQ(a,b,2*k+1,l,(l+r)/2);
      int vr=RMODQ(a,b,2*k+2,(l+r)/2,r);
      return MODin(vl,vr);
  }

};
