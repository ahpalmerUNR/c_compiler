readInt:
	addi	$sp,	$sp,	-4
	sw	$ra,	0($sp)
	li	$v0,	5
	syscall
	lw	$ra,	0($sp)
	addi	$sp,	$sp,	4
	jr $ra