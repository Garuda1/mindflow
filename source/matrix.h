//
// Created by Garuda1 on 26/08/2017.
//

#ifndef MINDFLOW_MATRIX_H
#define MINDFLOW_MATRIX_H

#include "vm.h"
#include <sys/types.h>

typedef struct s_vm_matrix t_vm_matrix;
struct s_vm_matrix
{
  size_t size_x;
  size_t size_y;

  t_vm   ***vm; /* TRIPLE POINTER Y'ALL */
};

t_vm_matrix *vm_matrix_new(const size_t size_x, const size_t size_y, const size_t mem_size);
void vm_matrix_free(t_vm_matrix *matrix);

#endif //MINDFLOW_MATRIX_H
