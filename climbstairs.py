import math

def climbStairs(n):
        ways=0

        num1s=n
        num2s=0

        ways+=math.factorial(num1s + num2s)/(math.factorial(num1s)*math.factorial(num2s))

        while num1s>1 :
            num1s-=2
            num2s+=1
            ways+=math.factorial(num1s + num2s)/(math.factorial(num1s)*math.factorial(num2s))
            
        ways=int(ways)
        return ways

print(climbStairs(8))