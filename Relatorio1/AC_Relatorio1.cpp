#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>

using namespace std;

int gcd1(int a, int b);
int gcd2(int a, int b);


int main(int argc, char **argv) {
  auto begin = chrono::high_resolution_clock::now();

  for(int i=0; i<10000; i++) {
    gcd1(5702887,3524578);
  }

  auto end = chrono::high_resolution_clock::now();
  auto dur = end - begin;
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

  std::cout << "gcd(13,8) iterativo: " << ((float)(ms))/(10.0f) << "us" << std::endl;

  begin = chrono::high_resolution_clock::now();

  for(int i=0; i<10000; i++) {
    gcd2(5702887,3524578);
  }

  end = chrono::high_resolution_clock::now();
  dur = end - begin;
  ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

  std::cout << "gcd(13,8) recursivo: " << ((float)(ms))/(0.01f) << "ns" << std::endl;

}

int gcd1(int a, int b) {
  // Considera-se 'a' sempre o maior número
  int c = b;
  while(c > 0) {
    if(a%c == 0 && b%c == 0) {
      return c;
    }
    c -= 1;
  }
  return 1;
}

int gcd2(int a, int b) {
  // Considera-se 'a' sempre o maior número
  if(b == 0) {
    return a;
  }
  int r = a%b;
  return gcd2(b, r);
}
