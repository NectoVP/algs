a, b = map(int, input().split());
x, y = (a, b) if a > b else (b, a);
while(x % y != 0):
    x, y = y, x % y;
print(y);
