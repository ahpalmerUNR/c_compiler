writeInt:
	addi	$sp,	$sp,	-4
	sw	$ra,	0($sp)
	lw	$a0,	4($sp)
	li	$v0,	1
	syscall
	lw	$ra,	0($sp)
	addi	$sp,	$sp,	8
	jr $ra
