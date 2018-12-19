readChar:
	addi	$sp,	$sp,	-4
	sw	$ra,	0($sp)
	li	$v0,	12
	syscall
	lw	$ra,	0($sp)
	addi	$sp,	$sp,	4
	jr $ra
