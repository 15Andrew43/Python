n = int(input())

up = down = n


while True:
    sum11 = up//100000 + up//10000%10 + up//1000%10    
    sum12 = up//100%10 + up//10%10 + up%10
    sum21 = down//100000 + down//10000%10 + down//1000%10    
    sum22 = down//100%10 + down//10%10 + down%10
    if sum11 == sum12:
        print(up)
        break
    elif sum21 == sum22:
        print(down)
        break
    up+=1
    down-=1
    
