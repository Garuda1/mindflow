#include "../vm.h"

uint8_t vm_op_loadc(t_vm *dxvm)
{
  (dxvm->reg)[2] = (dxvm->mem)[++(dxvm->ip) % sizeof(dxvm->mem)];
  return (VM_STAT_RUN);
}
