#include "../vm.h"

uint8_t vm_op_jmp(t_vm *dxvm)
{
  dxvm->ip = dxvm->mem[((dxvm->ip)+1) % sizeof(dxvm->mem)] % sizeof(dxvm->mem);
  return (VM_STAT_RUN);
}
