.data
array:    .word 5, 2, 9, 3, 7
size:     .word 5

.text
.globl main

main:
    la   $t0, array
    lw   $t1, size
    subi $t1, $t1, 1

outer_loop:
    move $t2, $t0
    add  $t3, $t0, $t1

    move $a0, $t2
    move $a1, $t3
    jal  min
    move $t4, $v0

    lw   $t5, 0($t4)
    lw   $t6, 0($t2)
    sw   $t5, 0($t2)
    sw   $t6, 0($t4)

    subi $t1, $t1, 1
    bgez $t1, outer_loop

    li   $v0, 10
    syscall

min:
    move $t7, $a0
    lw   $t8, 0($t7)
    move $v0, $a0

inner_loop:
    addi $t7, $t7, 4
    bgt  $t7, $a1, end_min
    lw   $t9, 0($t7)
    bge  $t8, $t9, update_min

    j    inner_loop

update_min:
    move $t8, $t9
    move $v0, $t7

    j    inner_loop

end_min:
    jr   $ra
