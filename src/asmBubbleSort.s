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

                // clearing registers
    mov x2, #0
    mov x3, #0
                // prepping registers for first loop
    sub x8, x1, x2
    sub x8, x8, #1
    b asm_outerLoop

asm_outerLoop:
                // for (int i =0; i < length; i++)
    cmp x2, x1
    b.eq asm_return
    add x2, x2, #1
    mov x3, #0

    // condition for inner loop
asm_innerLoop:
                    // for (j = 0; j < length - i - 1; j++)
                    // x8 holds length - i - 1

                    // x6 = &array[j]
    add x6, x0, x3, LSL #2
                    // x4 = *array[j]
    ldtrsw x4, [x6]

    add x3, x3, #1
                    // x7 = &array[j+1]
    add x7, x0, x3, LSL #2
                    // x5 = *array[j+1]
    ldtrsw x5, [x7]

    cmp x4, x5
                    // if x4 < x5 don't swap
    b.le asm_noSwap
                    // swapping takes place here
                    // x10 = temp register
    ldtrsw x10, [x6]
                    
    str w5, [x6]
    str w10, [x7]
    b asm_noSwap

asm_noSwap:

    cmp x3, x8
    b.lt asm_innerLoop
                    // if j < length - i - i; keep looping, otherwise decrement counters
    
    sub x8, x1, x2
    sub x8, x8, #1

    b asm_outerLoop

asm_return:
    ret
	.end
