	.global asmBubbleSort
	// x0 = array ptr
	// x1 = array size
	
asmBubbleSort:
		
    // x2 = i
    // x3 = j
    // x4 = *array[j]
    // x5 = *array[j+1]
    // x6 = &array[j]
    // x7 = &array[j+1]

    mov x2, #0
    mov x3, #0

asm_outerLoop:
    
    add x2, x2, #1
    cmp x2, x1
    b.eq asm_return
    mov x3, #0

asm_innerLoop:
                    // for (j = 0; j < length - i - 1; j++)
    sub x8, x1, x2
    sub x8, x8, #1
    cmp x3, x8
    b.eq asm_outerLoop

                    // x6 = &array[j]
    add x6, x0, x3, LSL #2
                    // x4 = *array[j]
    ldr x4, [x6]

    add x3, x3, #1
                    // x7 = &array[j+1]
    add x7, x0, x3, LSL #2
                    // x5 = *array[j+1]
    ldr x5, [x7]

    cmp x5, x4
    b.gt swap
    b asm_innerLoop


    
swap:
    // x10 = temp 
    ldr x10, [x6]

    str w5, [x6]
    str w10, [x7]

    b asm_innerLoop

asm_return:
    ret
	.end
