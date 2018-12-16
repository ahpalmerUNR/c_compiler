###############################################################################
# @file ReadInt.asm
# @brief Read an int from user input.
###############################################################################

ReadInt:
    li      $v0,     5
    syscall             # Read integer from console
    # $v0 is the value read
    jr $ra
