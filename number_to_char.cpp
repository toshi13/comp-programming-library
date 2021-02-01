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

//数値をアルファベットに変換する。
//0~25のみを入力として受け付ける
//flag=trueなら小文字,falseなら大文字
void nuMODber_to_char(vector<int> v,string& str,bool flag){
  int n=v.size();
  str.clear();
  for(int i=0;i<n;i++){
    if(0<=v[i] && v[i]<=25 && flag){
      char c=v[i]+'a';
      str+=c;
    }else if(0<=v[i] && v[i]<=25 && !flag){
      char c=v[i]+'A';
      str+=c;
    }
  }
}

int MODain(){
  vector<int> V={1,23,4,4,0,8};
  string s;
  nuMODber_to_char(V,s,1);
  cout<<s<<endl;
  nuMODber_to_char(V,s,0);
  cout<<s<<endl;
}
