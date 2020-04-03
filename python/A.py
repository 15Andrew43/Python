import numpy as np

nice = False
person = 'nice' if nice else 'bad'

print(person)

NameList = ['a', 'b', 'c']

for i, name in enumerate(NameList):
	print(i, name)
	if i==2:
		break
else:
	print(1543)

for i in np.arange(1, 10, 0.5):
	print(i)

# [x**2 for x in range(10) if x%2==0 print(x**2)]

a = [2, 5, 1, 0, 6, 4, 9, 10]

def f():
	a = 1
	b = 1
	while True:
		a, b = b, a+b
		yield b

for x in f():
	print(x)
	if x>100000: break