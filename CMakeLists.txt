cmake_minimum_required(VERSION 3.8)
project(MindFlow)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        LICENSE
        README.md
        source/main.c
        source/vm.c
        source/dumpmem.c
        source/optab.c
        source/op/add.c
        source/op/and.c
        source/op/cjmp.c
        source/op/dec.c
        source/op/disp.c
        source/op/eq.c
        source/op/great.c
        source/op/inc.c
        source/op/jmp.c
        source/op/less.c
        source/op/loada.c
        source/op/loadb.c
        source/op/loadc.c
        source/op/loadd.c
        source/op/lshift.c
        source/op/neq.c
        source/op/nop.c
        source/op/not.c
        source/op/or.c
        source/op/popa.c
        source/op/popb.c
        source/op/popc.c
        source/op/popd.c
        source/op/push.c
        source/op/pusha.c
        source/op/pushb.c
        source/op/pushc.c
        source/op/pushd.c
        source/op/rshift.c
        source/op/stop.c
        source/op/sub.c
        source/op/xor.c
        source/matrix.h source/matrix.c source/msg.h)

add_executable(MindFlow ${SOURCE_FILES})

target_compile_options(MindFlow PRIVATE -Wall -Wextra -Werror -O2)