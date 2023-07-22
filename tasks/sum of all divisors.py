#(включая 1 и само число)
i = 36;
j = 2;
sum = 1;
n = 0;
a = i;
while(j*j <= a):
    if(a % j == 0):
        n = 0;
        while(a % j == 0):
            a = a // j;
            n+=1;
        sum = sum * ((j**(n+1)-1)//(j-1));
    j+=1;
if(a > 1):
    sum = sum * ((a**(1+1)-1)//(a-1));
print(sum);
