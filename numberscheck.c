#include<stdio.h>
#include<math.h>

int countDigits(int n)
{
    int c=0;
    while(n>0)
    {
        c++;
        n/=10;
    }
    return c;
}

int countDigitsrecuursion(int n)
{
    if(n==0)
    return 0;
    return 1+ countDigitsrecuursion(n/10);
}

int sumofDigits(int n)
{
    int sum =0;
    while(n>0)
    {
        sum = sum+(n%10);
        n/=10;
    }
    return sum;
}
int productofDigits(int n)
{
    int prod=1;
    while(n>0)
    {
        prod*=(n%10);
        n/=10;
    }
    return prod;
}
int frequencyOfDigit(int num,int d)
{
    int c=0;
    while(num>0)
    {
        if(num%10==d)
        c++;
        num/=10;
    }
    return c;
}

int factorial(int n)
{
    int fact =1,i;
    for(i=1;i<=n;i++)
    {
        fact*=i;
    }
    return fact;
}

int factorialreccursion(int n)
{
    if(n==0)
    return 1;
    return n* factorialreccursion(n-1);
}


void primefactorization(int n)
{
    int i=2;
    while(n>1)
    {
        if(n%i==0)
        {
            printf("%d ",i);
            n/=i;
        }
        else
        i++;
    }
}

int countFactors(int n)
{
    int i=1,j=n,c=0;
    while(i<j)
    {
        j=n/i;
        if(n%i==0)
        {
            c+=(i==j)?1:2;
        }
        i++;
    }
    return c;
}

int isPrime(int n)
{
    if(n==0 || n==1)
    return 0;
    int i;
    for(i=2;i<=(int)sqrt(n);i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}

int isPerfect(int n)
{
    int s=0,i;
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        s=s+i;
    }
    return s==n?1:0;
}


int isPalindrome(int n)
{
    int rev=0,copy=n,d;
    while(copy>0)
    {
        d=copy%10;
        rev=rev*10+d;
        copy/=10;
    }
    return rev==n?1:0;
}

int isArmstrong(int n)
{
    int count=countDigits(n);
    int sum =0,copy=n,d;
    while(copy>0)
    {
        d=copy%10;
        sum=sum+(int)pow(d,count);
        copy/=10;
    }
    if(sum == n)
    return 1;
    else
    return 0;
}

int isSpecial(int n) //also called krishnamurty number
{
    int sum =0,copy=n,d;
    while(copy>0)
    {
        d=copy%10;
        sum=sum+factorial(d);
        copy/=10;
    }
    if(sum==n)
    return 1;
    else
    return 0;
}

int isDisarium(int n)
{
    int len=countDigits(n);
    int copy=n,d,sum=0;
    while(copy>0)
    {
        d=copy%10;
        sum=sum+(int)pow(d,len);
        len--;
        copy/=10;
    }
    return (sum==n)?1:0;
}

int isBeam(int n)
{
    int copy=n,sum=0,d;
    while(copy>0)
    {
        d=copy%10;
        sum=sum+(d*d);
        copy/=10;
    }
    return (sum>n)?1:0;
}

int isSpy(int n)
{
    int sum=0,prod=1,d;
    while(n>0)
    {
        d=n%10;
        sum=sum+d;
        prod=prod*d;
        n/=10;
    }
    return (sum==prod)?1:0;
}

int isBuzz(int n)
{
    if(n%10==7 || n%7==10)
    return 1;
    else
    return 0;
}

int isAutomorphic(int n)
{
    int len=countDigits(n);
    int sqr = n*n;
    int d=sqr%((int)pow(10,len));
    return d==n?1:0;
}

int isSunny(int n)
{
    double n2=sqrt(n+1);
    if(n2==(double)((int)n2))
    return 1;
    else
    return 0;
}

int isKarpekar(int n)
{
    int sq=n*n,len,a,b;
    len=countDigits(n);
    a=sq%((int)pow(10,len));
    b=sq/((int)pow(10,len));
    if(a+b==n)
    return 1;
    else
    return 0;
}

int isHappy(int n)
{
    int sum,d;
    while(n>9)
    {
        sum=0;
        while(n>0)
        {
            d=n%10;
            sum=sum+(d*d);
            n/=10;
        }
        n=sum;
    }
    if(n==1)
    return 1;
    else
    return 0;
}

int isMagic(int n)
{
    int sum,d;
    while(n>9)
    {
        sum=0;
        while(n>0)
        {
            d=n%10;
            sum=sum+d;
            n/=10;
        }
        n=sum;
    }
    if(n==1)
    return 1;
    else
    return 0;
}

int isTriangular(int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        if((i*(i+1))/2==n)
        return 1;
        else if((i*(i+1))/2>n)
        return 0;
    }
    return 0;
}

int isNeon(int n)
{
    int sq=n*n,s=0;
    while(sq>0)
    {
        s=s+(sq%10);
        sq/=10;
    }
    return s==n?1:0;
}

int isEvil(int n)
{
    if(n<0)
    return 0;
    int count=0,d;
    while(n>0)
    {
        d=n%2;
        if(d==1)
        count++;
        n/=2;
    }
    return (count%2==0)?1:0;
}


int isSmith(int n)
{
    int i=2,s1=sumofDigits(n),s2=0;
    while(n>1)
    {
        if(n%i==0)
        {
            s2=s2+sumofDigits(i);
            n/=i;
        }
        else
        i++;
    }
    return s1==s2?1:0;
}


int isVampire(int n)
{
    int i,j,newnum,copy,c,d;
    for(i=11;i<=99;i++)
    {
        for(j=11;j<=99;j++)
        {
            if(i*j==n && i*j<10000)
            {
                newnum=i*100+j;
                copy=newnum;
                c=0;
                while(copy>0)
                {
                    d=copy%10;
                    if(frequencyOfDigit(newnum,d)==frequencyOfDigit(n,d))
                    {
                        c++;
                    }
                    copy/=10;
                }
                if(c==4)
                return 1;

            }
        }
    }
    return 0;
}

int main()
{
    printf("countDigits(3528) = %d\n",countDigits(3528));
    printf("countDigitsrecuursion(736869) = %d\n",countDigitsrecuursion(736869));
    printf("sumofDigits(4628) = %d\n",sumofDigits(4628));
    printf("productofDigits(5278) = %d\n",productofDigits(5278));
    printf("frequencyOfDigit(5276832,2) = %d\n",frequencyOfDigit(5276832,2));
    printf("isPrime(53) = %s\n",(isPrime(53)==1)?"True":"False");
    printf("isPrime(50) = %s\n",(isPrime(50)==1)?"True":"False");
    printf("isPerfect(6) = %s\n",(isPerfect(6)==1)?"True":"False");
    printf("isPerfect(24) = %s\n",(isPerfect(24)==1)?"True":"False");
    printf("isPalindrome(2332) = %s\n",(isPalindrome(2332)==1)?"True":"False");
    printf("isPalindrome(5362) = %s\n",(isPalindrome(5362)==1)?"True":"False");
    printf("isArmstrong(370) = %s\n",(isArmstrong(370)==1)?"True":"False");
    printf("isArmstrong(578) = %s\n",(isArmstrong(578)==1)?"True":"False");
    printf("isSpecial(145) = %s\n",(isSpecial(145)==1)?"True":"False");
    printf("isSpecial(155) = %s\n",(isSpecial(155)==1)?"True":"False");
    printf("isDisarium(135) = %s\n",(isDisarium(135)==1)?"True":"False");
    printf("isDisarium(137) = %s\n",(isDisarium(137)==1)?"True":"False");
    printf("isBeam(25) = %s\n",(isBeam(25)==1)?"True":"False");
    printf("isBeam(70) = %s\n",(isBeam(70)==1)?"True":"False");
    printf("isSpy(1124) = %s\n",(isSpy(1124)==1)?"True":"False");
    printf("isSpy(1127) = %s\n",(isSpy(1127)==1)?"True":"False");
    printf("isBuzz(47) = %s\n",(isBuzz(47)==1)?"True":"False");
    printf("isBuzz(51) = %s\n",(isBuzz(51)==1)?"True":"False");
    printf("isAutomorphic(25) = %s\n",(isAutomorphic(25)==1)?"True":"False");
    printf("isAutomorphic(28) = %s\n",(isAutomorphic(28)==1)?"True":"False");
    printf("isSunny(63) = %s\n",(isSunny(63)==1)?"True":"False");
    printf("isSunny(68) = %s\n",(isSunny(68)==1)?"True":"False");
    printf("isKarpekar(45) = %s\n",(isKarpekar(45)==1)?"True":"False");
    printf("isKarpekar(49) = %s\n",(isKarpekar(49)==1)?"True":"False");
    printf("isMagic(50113) = %s\n",(isMagic(50113)==1)?"True":"False");
    printf("isMagic(857) = %s\n",(isMagic(857)==1)?"True":"False");
    printf("isHappy(28) = %s\n",(isHappy(28)==1)?"True":"False");
    printf("isHappy(30) = %s\n",(isHappy(30)==1)?"True":"False");
    printf("isTriangular(10) = %s\n",(isTriangular(10)==1)?"True":"False");
    printf("isTriangular(11) = %s\n",(isTriangular(11)==1)?"True":"False");
    printf("isNeon(9) = %s\n",(isNeon(9)==1)?"True":"False");
    printf("isNeon(15) = %s\n",(isNeon(15)==1)?"True":"False");
    printf("isEvil(45) = %s\n",(isEvil(45)==1)?"True":"False");
    printf("isEvil(47) = %s\n",(isEvil(47)==1)?"True":"False");
    printf("isSmith(666) = %s\n",(isSmith(666)==1)?"True":"False");
    printf("isSmith(624) = %s\n",(isSmith(624)==1)?"True":"False");
    printf("isVampire(1260) = %s\n",(isVampire(1260)==1)?"True":"False");
    printf("isVampire(1265) = %s\n",(isVampire(1265)==1)?"True":"False");

    return 0;
}