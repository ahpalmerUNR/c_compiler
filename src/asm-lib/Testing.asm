main:
	jal readChar
	move $a0, $v0 # TODO: Figure out where we are putting the variable for sure
	jal writeChar
	# Exit main
	li $v0, 10
	syscall
