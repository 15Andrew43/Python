n = int(input())

answer = [n*[0]]*n

answer[0][0] = 1
turn = 0
T = 0
go = n-1
k = 1

number = 1
# x++ wright  2
# y++ down   2
# x-- left   2
# y-- up     1

x=y=0
number = 1

for i in range(n):
	answer[x][y] = number
	x+=1
	number += 1
k = 1
gox = -1
goy = 1
p = 0
x = n
y = 0
while(p < n*n - n - 2):
	answer[x][y] = number
	for i in range(go):
		y+=goy
		answer[x][y] = number
		number += 1
		p+=1
	goy*=(-1)
	for i in range(go):
		x+=gox
		answer[x][y] = number
		number += 1
		p+=1
	gox*=(-1)
	go-=1

for i in range(n):
	for j in range(n):
		print(answer[i][j])
	print()

print(answer)

