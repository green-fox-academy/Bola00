#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
  float cpu_speed_GHz;
  int ram_size_GB;
  int bits;
};

typedef struct {
  float cpu_speed_GHz;
  int ram_size_GB;
  int bits;
} Notebook;

int main()
{
struct Computer comp;
comp.bits = 100;
comp.cpu_speed_GHz = 2.4;
comp.ram_size_GB = 8;

Notebook note;
note.ram_size_GB = 6;
note.bits = 60;
note.cpu_speed_GHz = 1.8;

printf("speed is %.1f GHz, ram is %i GB and bits are %i \n", comp.cpu_speed_GHz, comp.ram_size_GB, comp.bits);
    printf("speed is %.1f GHz, ram is %i GB and bits are %i \n", note.cpu_speed_GHz, note.ram_size_GB, note.bits);
    return 0;
}