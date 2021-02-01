#include<vector>
#include<iostream>


class union_find{
public:
  std::vector<int> parent;
  std::vector<int> depth;
  union_find(int _mAX_V);
  int find(int x);
  void init(int n);
  bool same(int x,int y);
  void unite(int x,int y);
  void print();
  int number_of_group();

private:
  int MAX_VERTEX;
};



union_find::union_find(int _mAX_V){
  MAX_VERTEX=_MAX_V;
  parent.resize(MAX_VERTEX);
  depth.resize(MAX_VERTEX);
  init(MAX_VERTEX);
}

void union_find::print(){
  for(int i=0;i<MAX_VERTEX;i++){
    std::printf("vertex:%d　parent:%d depth:%d\n",i,parent[i],depth[i]);
  }
  printf("number_of_group:%d\n",number_of_group());
}

void union_find::init(int n){
  for(int i=0;i<n;i++){
    parent[i]=i;
    depth[i]=0;
  }
}


int union_find::find(int x){
  if(parent[x]==x)return x;
  else return parent[x]=find(parent[x]);
}


bool union_find::same(int x,int y){
  return find(x)==find(y);
}

void union_find::unite(int x,int y){
  x=find(x);
  y=find(y);

  if(x==y)return;

  if(depth[x]<depth[y]){
    parent[x]=y;
  }else {
    parent[y]=x;
    if(depth[y]==depth[x])depth[x]++;
  }
}

int union_find::number_of_group(){
  int num_of_g=0;
  for(int i=0;i<MAX_VERTEX;i++){
    if(parent[i]==i){
      num_of_g++;
    }
  }
  return num_of_g;
}



int main(){
  union_find Uni(5);
  Uni.print();
  Uni.unite(1,2);
  Uni.print();
  Uni.unite(2,3);
  Uni.print();
 
}
