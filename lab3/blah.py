def fibonacci(b):
	if b <= 1:
		return 1
	else:
		return (fibonacci(b-1) + fibonacci(b-2))

for i in range(0,10):
	print fibonacci(i)
