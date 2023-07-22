i = 80;
n = 0;
j = 2;
sum = 1;
a = i;
while(j * j <= i):
  if (a % j == 0):
    while (a % j == 0):
      a = a / j;
      n+=1;
    sum = sum * (n+1);
    n = 0;
  j+=1;
if (a > 1):
  sum = sum * 2;

print(sum)
