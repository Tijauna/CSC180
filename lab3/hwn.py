while True:
	try:
		n = int(raw_input())
		break
	except:
		print 'error: not a number'
msg = raw_input()
for i in range(0, n-1):
	print msg



