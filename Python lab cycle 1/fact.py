a=int(input("Enter the number : "))
fact=1
if a < 0:
   print("Sorry, factorial does not exist for negative numbers")
elif a == 0:
   print("The factorial of 0 is 1")
else:
   for i in range(1,a + 1):
       fact = fact*i
   print("The factorial is",fact)

