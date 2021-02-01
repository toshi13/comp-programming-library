#include <iostream>
#include <mutex>
const long long MAX=510000;

class mint {
    long long x;
    static const long long mod = 1000000007;
    static long long fac[MAX],finv[MAX],inv[MAX];
public:
    mint(long long x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { 
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv_func() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv_func();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }

    static void COM_init(){
      fac[0] = fac[1] = 1;
      finv[0] = finv[1] = 1;
      inv[1] = 1;
      for (int i = 2; i < MAX; i++){
          fac[i] = fac[i - 1] * i % mod;
          inv[i] = mod - inv[mod%i] * (mod / i) % mod;
          finv[i] = finv[i - 1] * inv[i] % mod;
      }
    }

    static void print(mint n){
      std::cout <<n.x<<std::endl;
    } 


    mint COM(mint n, mint k){
      if(n.x < k.x)return mint(0);
      long long s=fac[n.x]*(finv[k.x]*finv[n.x-k.x]%mod)%mod;
      return mint(s);
    }
  

    
};




int main(){
  mint::COM_init();
  mint a(1100000),b(2222222222);
  mint::print(a);
  mint::print(b);

}