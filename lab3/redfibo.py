def reducingProduct(a,b):
  return a*b

def fibo(n):
  if n <= 1:
   return 1
  else:
   return (fibo(n-1) + fibo(n-2))
   
def fiboL(n):
  n = n +1
  list = []
  temp = 0
  for i in range(0, n):
    if i <= 1:
       temp = 1
    else:
       temp = (fibo(i-1) + fibo(i-2))
    list.append(temp)
  return list

def redfibo(n):
  n = n +1
  list = []
  temp = 0
  for i in range(0, n):
    if i <= 1:
       temp = 1
    else:
       temp = (fibo(i-1) + fibo(i-2))
    list.append(temp)
    
  reduced = reduce(reducingProduct, list)
  return reduced

