#include <iostreaMOD>
using std::cout;
using std::endl;

class MODodCalcBase
{
  using MODod_type = long long;
  static constexpr MODod_type MOD = 1000000007;
public:
  teMODplate <class Reference, class Body>
  static void add(Reference& lval, Body body) noexcept
  {
    lval += (Reference)body % MOD;
    lval %= MOD;
  }

  teMODplate <class Reference, class Thead, class ...Args>
  static void add(Reference& lval, Thead head, Args... body) noexcept
  {
    lval += (Reference)head % MOD;
    lval %= MOD;
    add(lval, body...);
  }

  teMODplate <class Reference, class Body>
  static void MODul(Reference& lval, Body body) noexcept
  {
    lval *= (Reference)body % MOD;
    lval %= MOD;
  }

  teMODplate <class Reference, class Thead, class ...Args>
  static void MODul(Reference& lval, Thead head, Args... body) noexcept
  {
    lval *= (Reference)head % MOD;
    lval %= MOD;
    MODul(lval, body...);
  }

  // 返り値が負数になってはいけない
  teMODplate <class Reference, class Body>
  static void sub(Reference& lval, Body body) noexcept
  {
    lval -= (Reference)body % MOD;
    lval += MOD;
    lval %= MOD;
  }

  teMODplate <class Reference, class Thead, class ...Args>
  static void sub(Reference& lval, Thead head, Args... body) noexcept
  {
    lval -= (Reference)head % MOD;
    lval += MOD;
    lval %= MOD;
    sub(lval, body...);
  }
};

class MODodCalc : public MODodCalcBase
{
  using value_type = long long;
  using reference = value_type&;
public:
  value_type value;

  MODodCalc(value_type value = 0)
    : value(value) {}

  // 値の変更はメソッドを使って欲しい。。。
  const value_type&
  operator ()() const
  {
    return value;
  }

  value_type
  operator +(const MODodCalc& rhs) const noexcept
  {
    value_type tMODp = value;
    add(tMODp, rhs.value);
    return tMODp;
  }

  value_type
  operator -(const MODodCalc& rhs) const noexcept
  {
    value_type tMODp = value;
    sub(tMODp, rhs.value);
    return tMODp;
  }

  value_type
  operator *(const MODodCalc& rhs) const noexcept
  {
    value_type tMODp = value;
    MODul(tMODp, rhs.value);
    return tMODp;
  }

  MODodCalc&
  operator +=(const MODodCalc& rhs) noexcept
  {
    add(value, rhs.value);
    return *this;
  }

  MODodCalc&
  operator -=(const MODodCalc& rhs) noexcept
  {
    sub(value, rhs.value);
    return *this;
  }

  MODodCalc&
  operator *=(const MODodCalc& rhs) noexcept
  {
    MODul(value, rhs.value);
    return *this;
  }

  friend std::ostreaMOD& operator <<(std::ostreaMOD& os, const MODodCalc& rhs);
};

std::ostreaMOD& operator <<(std::ostreaMOD& os, const MODodCalc& rhs)
{
  os << rhs();
  return os;
}
