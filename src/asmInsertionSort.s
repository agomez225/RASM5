    .global asmInsertionSort



asmInsertionSort:
                // i = 1
    mov x2, #1 
        

iloop:              // i - n         

    cmp x2, x1      // i >= n => loopend
    b.ge iloopend 

                    // temp = &array[4*i]    
    add x10, x0, x2, LSL #2

                    // temp = array[4*i]
    ldr w10, [x10]

                    // j = i - 1
    sub x3, x2, #1

jloop:              // while j >=0
    cmp x3, #0 
    b.lt jloopend

                    // x9 <- &array[4*j]
    add x9, x0, x3, LSL #2 

                    // x9 <- array[4*j]
    ldtrsw x9, [x9] 

                    // temp < array[4*j] ?
    cmp x10, x9 
    b.ge jloopend

    add x8, x0, x3, LSL #2

                    // x8 <- &array[4*(j+1)]    
    add x8, x8, #4

                    // a[j+1] <- a[j]
    str w9, [x8] 
                    // j <- j - 1
    sub x3, x3, #1 
    b jloop

jloopend:           // j <- j+1
    add x3, x3, #1 
                    // x8 <- &array[4*(j+1)]
    add x8, x0, x3, LSL #2 
                    // a[j+1] <- temp
    str w10, [x8] 
                     // i++
    add x2, x2, #1
    b iloop

iloopend:
    ret
    .end
