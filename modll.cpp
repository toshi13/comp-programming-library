const long long MOD=1000000007;

class Modll{
  long long value;
public:
  Modll(long long value=0):value((value%MOD)%MOD){}
  long long operator +(const Modll& obj) const{
    return ((value%MOD) + (obj.value%MOD))%MOD;
  }
  Modll operator -(const Modll& obj)const{
    if(value-obj.value>=0){return (value-obj.value)%MOD;}
    else{return (value-obj.value)%MOD+MOD;}
  }
  Modll operator *(const Modll& obj)const{
    return((value%MOD)*(obj.value%MOD))%MOD;
  }


  Modll& operator+=(const Modll& obj){
    if((value+=obj.value)>=MOD)value-=MOD;
    return *this;
  }
  Modll& operator-=(const Modll& obj){
    if((value-=obj.value)<0)value+=MOD;
    return *this;
  }
  
  Modll pow(long long t);

};


Modll Modll::pow(long long t) const{
    if(!t) return 1;
    Modll a = pow(t>>1);
    a *= a;
    if(t&1) a *= *this;
    return a;
}

