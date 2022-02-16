#include "string"
#include <algorithm>
#include <emscripten/emscripten.h>
#include <iostream>
#include <vector>
using namespace std;
struct Node {
  int id;
  float x, y;
  Node() : id(0), x(0), y(0) {}
  Node(int id, float x, float y) : id(id), x(x), y(y) {}
};
Node initPos(Node n) {
  n = Node(2, 1, 3);
  return n;
}

#ifdef __cplusplus
extern "C" {
#endif

char *EMSCRIPTEN_KEEPALIVE test(char *a) {
  cout << a << endl;
  Node n;
  initPos(n);
  vector<int> num(10, 0);
  for (int i = 0; i < num.size(); i++) {
    num[i] = 10 - i;
  }
  sort(num.begin(), num.end());
  string s = string(a) + to_string(num[2]) + to_string(n.id);
  char *o = new char[s.length() + 1];
  memcpy(o, s.c_str());
  return o;
}

#ifdef __cplusplus
}
#endif

int main() {
  char *b = test("aaa");
  cout << b << endl;
  return 0;
}
