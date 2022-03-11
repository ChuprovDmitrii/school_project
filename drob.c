#include <stdio.h>
#include <iostream>
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
class drob {
  int ch;
  int zn;

 public:
  void socr() {
    int buf = gcd(ch, zn);
    ch /= buf;
    zn /= buf;
  }
  drob() {
    ch = 0;
    zn = 1;
  }
  drob(int a) {
    ch = a;
    zn = 1;
  }
  drob(int a, int b) {
    ch = a;
    zn = b;
  }
  drob(const drob& a) {
    ch = a.ch;
    zn = a.zn;
  }
  friend drob operator+(const drob& a,const drob& b) {
    drob s;
    s.ch = a.zn * b.ch + a.ch * b.zn;
    s.zn = a.zn * b.zn;
    s.socr();
    return s;
  }
  friend drob operator+(const drob& a,const int& b) {
    drob s;
    s.ch = a.zn * b + a.ch;
    s.zn = a.zn;
    s.socr();
    return s;
  }
  friend drob operator+(const int &a,const drob &b) {
    drob s;
    s.ch = b.ch + a * b.zn;
    s.zn = b.zn;
    s.socr();
    return s;
  }
  friend drob operator-(const drob& a, const drob& b) {
    drob s;
    s.ch = a.ch * b.zn - a.zn * b.ch;
    s.zn = a.zn * b.zn;
    s.socr();
    return s;
  }
  friend drob operator-(const drob& a,const int& b) {
    drob s;
    s.ch = a.ch - a.zn * b;
    s.zn = a.zn;
    s.socr();
    return s;
  }
  friend drob operator-(const int& a, const drob& b) {
    drob s;
    s.ch = a * b.zn - b.ch;
    s.zn = b.zn;
    s.socr();
    return s;
  }
  friend drob operator*(const drob& a,const drob& b) {
    drob s;
    s.ch = a.ch * b.ch;
    s.zn = a.zn * b.zn;
    s.socr();
    return s;
  }
  friend drob operator*( const int& a,const drob& b) {
    drob s;
    s.ch = a * b.ch;
    s.zn = b.zn;
    s.socr();
    return s;
  }
  friend drob operator*( const drob& a, const int& b) {
    drob s;
    s.ch = a.ch * b;
    s.zn = a.zn;
    s.socr();
    return s;
  }
  friend drob operator/( const drob& a, const drob& b) {
    drob s;
    s.ch = a.ch * b.zn;
    s.zn = a.zn * b.ch;
    s.socr();
    return s;
  }
  friend drob operator/( const int& a,const drob& b) {
    drob s;
    s.ch = a * b.zn;
    s.zn = b.ch;
    s.socr();
    return s;
  }
  friend drob operator/(const drob& a, const int& b) {
    drob s;
    s.ch = a.ch;
    s.zn = b * a.zn;
    s.socr();
    return s;
  }
  
  friend int operator==(const drob& a, const drob& b) {
    return (a.ch*b.zn-b.ch*a.zn)==0;
  }
  friend int operator!=(const drob& a, const drob& b) {
    return (a.ch*b.zn-b.ch*a.zn)!=0;
  }
  friend int operator>(const drob& a, const drob& b) {
    return (a.ch*b.zn-b.ch*a.zn)>0;
  }
  friend int operator<(const drob& a, const drob& b) {
    return (a.ch*b.zn-b.ch*a.zn)<0;
  }
  friend int operator<=(const drob& a, const drob& b) {
    return (a.ch*b.zn-b.ch*a.zn)<=0;
  }
  friend int operator>=(const drob& a, const drob& b) {
    return (a.ch*b.zn-b.ch*a.zn)>=0;
  }
  friend int operator==(const int& a, const drob& b) {
    return (a*b.zn-b.ch)==0;
  }
  friend int operator!=(const int& a, const drob& b) {
    return (a*b.zn-b.ch)!=0;
  }
  friend int operator>(const int& a, const drob& b) {
    return (a*b.zn-b.ch)>0;
  }
  friend int operator<(const int& a, const drob& b) {
    return (a*b.zn-b.ch)<0;
  }
  friend int operator<=(const int& a, const drob& b) {
    return (a*b.zn-b.ch)<=0;
  }
  friend int operator>=(const int& a, const drob& b) {
    return (a*b.zn-b.ch)>=0;
  }
  friend int operator==(const drob& a, const int& b) {
    return (a.ch-b*a.zn)==0;
  }
  friend int operator!=(const drob& a, const int& b) {
    return (a.ch-b*a.zn)!=0;
  }
  friend int operator>(const drob& a, const int& b) {
    return (a.ch-b*a.zn)>0;
  }
  friend int operator<(const drob& a, const int& b) {
    return (a.ch-b*a.zn)<0;
  }
  friend int operator<=(const drob& a, const int& b) {
    return (a.ch-b*a.zn)<=0;
  }
  friend int operator>=(const drob& a, const int& b) {
    return (a.ch-b*a.zn)>=0;
  }
  drob & operator=(drob& in){
    ch=in.ch;
    zn=in.zn;
    return *this;
  }
  friend std::ostream& operator<<(std::ostream& buf, const drob &out) {
    buf << out.ch << "/" << out.zn;
    return buf;
  }
  friend std::istream& operator>>(std::istream& buf, drob& in) {
    buf >> in.ch;
    char b;
    buf>>b;
    buf >> in.zn;
    return buf;
  }
};
int main() {
  drob a, b,t;
  char c;
  std::cin >> a;
  std::cin >> b;
  std::cout << a+b <<std::endl;
  std::cout << a-b <<std::endl;
  std::cout << a+b <<std::endl;
  std::cout << a*b <<std::endl;
  return 0;
}
