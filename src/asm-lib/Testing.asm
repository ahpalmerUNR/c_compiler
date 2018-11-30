main:
	jal ReadInt
	move $t0, $v0 # TODO: Figure out where we are putting the variable for sure
	jal WriteInt
	# Exit main
	li $v0, 10
	syscall
