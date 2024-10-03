.text
.globl __start
__start:
    la $a0, prm1         # Imprime "Original: "
    li $v0,4
    syscall
    
    la $a0, orig         # Imprime la cadena original
    li $v0,4
    syscall
    
    la $s0, orig         # Cargar dirección de la cadena en $s0
    li $t0,0             # contador
    li $t2,1             # indicador de que se leyó un espacio
    li $t3,0             # indicador de rango minúsculas
    li $t4,0
    li $t6, 0x20         # ASCII space
    li $t7, 0x61         # ASCII 'a'
    li $t8, 0x7a         # ASCII 'z'
    
loop:                     # bucle para recorrer la cadena y convertir
    lb $t1, 0($t0)        # cargar el siguiente byte (carácter)
    beq $t1, $zero, endLoop  # fin si es null
    slt $t3, $t1, $t7     # t3 = 1 si t1 < 'a'
    slt $t4, $t8, $t1     # t4 = 1 si t1 > 'z'
    or $t3, $t3, $t4      # si está fuera del rango minúsculas
    
    beq $t2, $zero, nospace  # si no se leyó un espacio antes
    bne $t3, $zero, nospace  # si no está en rango minúsculas
    addi $t1, $t1, -32    # convertir a mayúscula
    sb $t1, 0($t0)        # almacenar el carácter convertido
    
nospace:
    bne $t1, $t6, nospacenow  # si el carácter actual no es un espacio
    li $t2, 1              # se leyó un espacio
    j endspace
    
nospacenow:
    li $t2, 0              # no se leyó un espacio
    
endspace:
    addi $t0, $t0, 1       # siguiente carácter
    j loop
    
endLoop:
    la $a0, prm2           # Imprime "Upcased: "
    li $v0,4
    syscall
    
    la $a0, orig           # Imprime la cadena convertida
    li $v0,4
    syscall
    
    li $v0, 10             # Salir del programa
    syscall

.data
orig: .asciiz "la cadena original con letras todas minusculas"
prm1: .asciiz "Original: "
prm2: .asciiz "\nUpcased: "
