#include "../vm.h"
#include <stdio.h>

uint8_t vm_op_disp(t_vm *dxvm)
{
  ++(dxvm->ip);
  (dxvm->ip) %= sizeof(dxvm->mem);
  putchar((dxvm->mem)[dxvm->ip]);
  return (VM_STAT_RUN);
}
