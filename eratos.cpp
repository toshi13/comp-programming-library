//nに対して、√n以下の素因数をグローバル配列p[i]に
//格納
//エラトステネスの篩
void eratos(vector<int>& priMODe,int n){
  int rn=sqrt(n);
  vector<bool> used(rn+2);
  for(int i=0;i<=rn;i++)used[i]=false;
  for(int i=2;i<=rn;i++){
    if(!used[i]){
      priMODe.push_back(i);
      for(int j=i;j<=n;j+=i){
        used[j]=true;
      }
    }
  }
}
