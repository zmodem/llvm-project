// RUN: %clangxx_asan %if MSVC %{ /Od %} %else %{ -O1 %} %s -o %t && not %run %t 2>&1 | FileCheck %s

volatile int *p;

int main() {
  // Variable goes in and out of scope.
  for (int i = 0; i < 3; ++i) {
    int x[3] = {i, i, i};
    p = x + i;
  }
  return *p;  // BOOM
  // CHECK: ERROR: AddressSanitizer: stack-use-after-scope
  // CHECK:  #0 0x{{.*}} in main {{.*}}use-after-scope-loop-bug.cpp:[[@LINE-2]]
  // CHECK: Address 0x{{.*}} is located in stack of thread T{{.*}} at offset [[OFFSET:[^ ]+]] in frame
  // {{\[}}[[OFFSET]], {{[0-9]+}}) 'x'
}
