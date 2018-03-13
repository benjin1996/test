#include <iostream>
#include <fstream>

using namespace std;

struct vec { 
 int x,y;
 vec() {}
 vec(int x, int y): x{x}, y{y} {}
 vec& operator= (const vec& v) {
  x = v.x;
  y = v.y;}};

vec operator+ (const vec& u, const vec& v) {
 return {u.x+v.x, u.y+v.y};}

ostream& operator<<(ostream& out, const vec& v) {
 out << v.x << " " << v.y;
 return cout;}

int main() {
 vec q;
 cout << q.x << " " << q.y << endl;
 ofstream file("lop.txt");
 vec u{1,2};
 cout << 5 << 6;
 file << u;
 vec v{3,4};
 vec w{v};
 vec x = u + v + w;}
