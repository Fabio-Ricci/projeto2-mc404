.global set_motor_speed
.global read_sonar
.global set_time
.global get_time
.align 4

set_motor_speed:
	push {lr}
	mov r7, #20
	svc 0x0
	pop {lr}
	mov pc, lr

read_sonar:
	push {lr}
	mov r7, #21
	svc 0x0
	pop {lr}
	mov pc, lr

get_time:
	push {lr}
	mov r7, #17
	svc 0x0
	pop {lr}
	mov pc, lr

set_time:
	push {lr}
	mov r7, #18
	svc 0x0
	pop {lr}
	mov pc, lr