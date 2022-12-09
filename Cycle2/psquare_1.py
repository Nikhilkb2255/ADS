def perfect_Number(n):
   if n < 1:
      return False

   perfect_sum = 0
   for i in range(1,n):
      if n%i==0:
         perfect_sum += i
   return perfect_sum == n

min_value = int(input('Print minimum value: '))
max_value = int(input('Print maximum value: '))

print('Perfect numbers from %d to %d are:' %(min_value, max_value))
for i in range(min_value, max_value+1):
   if perfect_Number(i):
      print(i, end=' ')

