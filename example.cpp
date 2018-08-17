#include <iostream>
#include <random>
#include <chrono>
#include <iacaMarks.h>

#include "uuid_v4.h"

#define IT 1000000000

void debugUUID(const UUID::UUID &uuid) {
  std::string bytes = uuid.bytes();
  for (int i=0; i<16; i++) {
    printf("%02hhx", bytes[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[]) {
  UUID::UUIDGenerator<std::mt19937_64> uuidGenerator;
  char txt[37];
  auto t1 = std::chrono::high_resolution_clock::now();
  for (int i=0; i<IT; i++) {
    UUID::UUID test = uuidGenerator.getUUID();
    test.str(txt);
  }
  auto t2 = std::chrono::high_resolution_clock::now();
  auto diff = t2-t1;
  std::cout << "ops/sec: " << IT / (std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count() / 1e9) << std::endl;


  return 0;
}
