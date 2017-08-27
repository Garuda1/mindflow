#include "../vm.h"

uint8_t vm_op_popb(t_vm *dxvm)
{
  if (dxvm->sp == sizeof(dxvm->mem))
    return (VM_STAT_FATAL);
  (dxvm->reg)[1] = (dxvm->mem)[(dxvm->sp)];
  ++(dxvm->sp);
  return (VM_STAT_RUN);
}
