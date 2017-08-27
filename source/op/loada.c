#include "../vm.h"

uint8_t vm_op_loada(t_vm *dxvm)
{
  (dxvm->reg)[0] = (dxvm->mem)[++(dxvm->ip) % sizeof(dxvm->mem)];
  return (VM_STAT_RUN);
}
