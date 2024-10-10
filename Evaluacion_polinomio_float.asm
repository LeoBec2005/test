.data
prompt_degree:  .asciiz "Ingrese el grado del polinomio: "
prompt_coeff:   .asciiz "Ingrese el coeficiente a%d (punto flotante): "
prompt_x:       .asciiz "Ingrese el valor de x (punto flotante): "
result_msg:     .asciiz "El resultado del polinomio es: "

.text
.globl main

main:
    la   $a0, prompt_degree
    li   $v0, 4
    syscall

    li   $v0, 5
    syscall
    move $t0, $v0

    addi $t0, $t0, 1
    li   $a0, 8
    mul  $a0, $a0, $t0

    li   $v0, 9
    syscall
    move $s0, $v0

    li   $t1, 0
leer_coef:
    la   $a0, prompt_coeff
    li   $v0, 4
    syscall

    li   $v0, 6
    syscall
    sll  $t2, $t1, 3
    sdc1 $f0, 0($s0)

    addi $t1, $t1, 1
    add  $s0, $s0, 8
    blt  $t1, $t0, leer_coef

    sub  $s0, $s0, $t2

    la   $a0, prompt_x
    li   $v0, 4
    syscall

    li   $v0, 6
    syscall
    mov.s $f0, $f0

    li    $t1, 0
    li.s  $f2, 0.0
    li.s  $f4, 1.0

evaluar:
    ldc1  $f6, 0($s0)
    mul.s $f8, $f4, $f6
    add.s $f2, $f2, $f8

    mul.s $f4, $f4, $f0
    addi  $t1, $t1, 1
    addi  $s0, $s0, 8

    blt   $t1, $t0, evaluar

    la   $a0, result_msg
    li   $v0, 4
    syscall

    mov.s $f12, $f2
    li   $v0, 2
    syscall

    li   $v0, 10
    syscall
