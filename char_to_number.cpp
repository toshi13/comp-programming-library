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

//アルファベットを0~25に変換してvに格納する。
//小文字も大文字も対応
void char_to_nuMODber(string s,vector<int>& v){
  int n=s.length();
  v.clear();
  for(int i=0;i<n;i++){
      //小文字のとき
      if(0x61<s[i] && s[i]< 0x7a){
        int c=s[i]-'a';
        v.push_back(c);
      }//大文字のとき
      else if(0x41<s[i] && s[i] <0x5a){
        int c=s[i]-'A';
        v.push_back(c);
      }
  }
}

int MODain(){
  string s="abcdeABCDE";
  vector<int> vec;
  char_to_nuMODber(s,vec);
  REP(i,vec.size())cout <<vec[i]<<endl;
}
