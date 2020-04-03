n = int(input())

for i in range(n):
    if (i+1)%15 == 0:
        print("Fizz Buzz", end = "")
    elif (i+1)%3 == 0:
        print("Fizz", end = "")
    elif (i+1)%5 == 0:
        print("Buzz", end = "")
    else:
        print (i+1, end = "")
    if i!= n-1:
    	print(", ", end = "")
