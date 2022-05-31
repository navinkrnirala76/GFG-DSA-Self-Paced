def ToggleBits(n):
    a = bin(n)[2:]
    x = list(a)
    if len(a)%2 == 0:
        u = len(a)
        if x[(u//2)-1] == '1':
            x[(u//2)-1] = '0'
        elif x[(u//2)-1] == '0':
            x[(u//2)-1] = '1'
        if x[(u//2) + 1 - 1] == '1':
            x[(u//2) + 1 - 1] = '0'
        elif x[(u//2) + 1 - 1] == '0':
            x[(u//2) + 1 - 1] = '1'
    else:
        u = len(a)
        if x[((u+1)//2)-1] == '1':
            x[((u+1)//2)-1] = '0'
        elif x[((u+1)//2)-1] == '0':
            x[((u+1)//2)-1] = '1'
    y = "".join(x)
    return int(y,2)

if __name__ == '__main__':
    t = int(input())
    for c in range(t):
        n = int(input())
        print (ToggleBits(n))