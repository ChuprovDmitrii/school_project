#include <stdio.h>
#include <iostream>
class vector {
  int x;
  int y;
 public:
  vector() {
    x = 0;
    y = 0;
  }
  vector(int a, int b) {
    x = a;
    y = b;
  }
  vector(const vector& a) {
    x = a.x;
    y = a.y;
  }
  friend vector operator+(const vector& a,const vector& b) {
    vector s;
    s.x = a.x + b.x;
    s.y = a.y + b.y;
    
    return s;
  }
  friend vector operator-(const vector& a, const vector& b) {
    vector s;
    s.x = a.x - b.x;
    s.y = a.y - b.y;
    return s;
  }
  friend int operator*(const vector& a,const vector& b) {
    int s;
    s = a.x * b.x + a.y * b.y;
    return s;
  }
  friend vector operator*( const int& a,const vector& b) {
    vector s;
    s.x = a * b.x;
    s.y = a * b.y;
    return s;
  }
  friend vector operator*( const vector& a, const int& b) {
    vector s;
    s.x = a.x * b;
    s.y = a.y * b;
    return s;
  }
  friend vector operator/(const vector& a, const int& b) {
    vector s;
    s.x = a.x / b;
    s.y = a.y / b;
    return s;
  }
  friend int operator==(const vector& a, const vector& b) {
    return ((a.x-b.x)==0&&(a.y-b.y)==0);
  }
  friend int operator!=(const vector& a, const vector& b) {
    return ((a.x-b.x)!=0&&(a.y-b.y)!=0);
  }
  friend int operator>(const vector& a, const vector& b) {
    return (a.x*a.x-b.y*b.y-b.x*b.x+a.y*a.y)>0;
  }
  friend int operator<(const vector& a, const vector& b) {
    return (a.x*a.x-b.y*b.y-b.x*b.x+a.y*a.y)<0;
  }
  friend int operator<=(const vector& a, const vector& b) {
    return (a.x*a.x-b.y*b.y-b.x*b.x+a.y*a.y)<=0;
  }
  friend int operator>=(const vector& a, const vector& b) {
    return (a.x*a.x-b.y*b.y-b.x*b.x+a.y*a.y)>=0;
  }
  vector & operator=(vector& in){
    x=in.x;
    y=in.y;
    return *this;
  }
  friend std::ostream& operator<<(std::ostream& buf, const vector &out) {
    buf <<"x="<< out.x <<"y="<< out.y;
    return buf;
  }
  friend std::istream& operator>>(std::istream& buf, vector& in) {
    buf >> in.x;;
    buf >> in.y;
    return buf;
  }
};
int main(){
  vector a, b,t;
  std::cin >> a;
  std::cin >> b;
  std::cout << a+b <<std::endl;
  std::cout << a-b <<std::endl;
  std::cout << a*b <<std::endl;
return 0;
}
