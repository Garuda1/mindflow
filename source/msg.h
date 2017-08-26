//
// Created by Garuda1 on 26/08/2017.
//

#ifndef MINDFLOW_MSG_H
#define MINDFLOW_MSG_H

#define VM_MSG_FATALERROR        "[MindFlow] The virtual machine encountered a fatal error and cannot continue execution."
#define VM_MSG_EXECSTARTED       "[MindFlow] Virtual Machine beggining program execution..."
#define VM_MSG_EXECHALTED        "[MindFlow] Execution halted (stop instruction executed)"
#define VM_MSG_EXECSTOPPED       "[MindFlow] Execution stopped at cycle %u, dumping memory"
#define VM_MSG_INITIALIZED       "[MindFlow] initialized"
#define VM_MSG_MATRIXALLOCFAILED "[MindFlow] Failed to allocate memory for a new cluster"
#define VM_MSG_NULLVMPTR         "[MindFlow] Provided VM pointer is NULL"
#define VM_MSG_NULLPROGPTR       "[MindFlow] Provided program pointer is NULL, skipping program loading"
#define VM_MSG_VMALLOCFAILED     "[MindFlow] Failed to allocate memory for a new virtual machine"
#define VM_MSG_VMMEMALLOCFAILED  "[MindFlow] Failed to allocate memory for a new virtual machine's memory"
#define VM_MSG_MATRIXINITFAILED  "[MindFlow] Failed to initialize a matrix. Out of memory?"

#endif //MINDFLOW_MSG_H
