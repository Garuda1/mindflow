//
// Created by Garuda1 on 26/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "vm.h"
#include "msg.h"
#include "matrix.h"

t_vm_matrix *vm_matrix_new(const size_t size_x, const size_t size_y, const size_t mem_size)
{
  t_vm_matrix *matrix;
  t_vm *temp_vm;
  size_t ix;
  size_t iy;

  if ((matrix = (t_vm_matrix*)malloc(sizeof(t_vm_matrix))) == NULL)
  {
    fprintf(stderr, VM_MSG_MATRIXALLOCFAILED "(%s:%d)\n", __FILE__, __LINE__);
    return (NULL);
  }

  matrix->size_x = size_x;
  matrix->size_y = size_y;

  if ((matrix->vm = (t_vm***)malloc(size_x*sizeof(t_vm*))) == NULL)
  {
    fprintf(stderr, VM_MSG_MATRIXALLOCFAILED "(%s:%d)\n", __FILE__, __LINE__);
    return (NULL);
  }

  for (ix=0; ix < size_x; ++ix)
    if ((matrix->vm[ix] = (t_vm**)malloc(size_y*sizeof(t_vm))) == NULL)
    {
      fprintf(stderr, VM_MSG_MATRIXALLOCFAILED "(%s:%d)\n", __FILE__, __LINE__);
      return (NULL);
    }

  for(ix=0; ix<size_x; ++ix)
    for(iy=0; iy<size_y; ++iy)
    {
      if ((temp_vm = vm_new(mem_size)) == NULL)
      {
        fprintf(stderr, VM_MSG_MATRIXINITFAILED "(%s:%d)\n", __FILE__, __LINE__);
        return (NULL);
      }

      matrix->vm[ix][iy] = vm_init(temp_vm, NULL);
    }

  return (matrix);
}