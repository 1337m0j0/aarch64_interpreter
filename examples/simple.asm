.text 			    // code section

.globl _start
_start:
	mov x1, 8
	mov x2, 24
  add x0, x1, x2
	mov x8, 93 	    // system call code for sys_exit
	svc #0 		    // call kernel
