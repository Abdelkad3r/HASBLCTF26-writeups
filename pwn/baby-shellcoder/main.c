#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#define MEMORY_SIZE 64

int main(){
  void* ptr = mmap(NULL,MEMORY_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if(ptr == MAP_FAILED) {
    perror("mmap failed: ");
    return -1;
  }
  puts("Kept you waiting huh?");
  read(0,ptr,MEMORY_SIZE);
  ((void(*)())ptr)();
  munmap(ptr,MEMORY_SIZE);
  return 0;
}
