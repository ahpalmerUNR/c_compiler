writeFloat:
	addi	$sp,	$sp,	-4
	sw	$ra,	0($sp)
	l.d	$f12,	4($sp)
	li	$v0,	3
	syscall
	lw	$ra,	0($sp)
	addi	$sp,	$sp,	12
	jr $ra