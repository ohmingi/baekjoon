dp = [0]*1000001

n = int(input())

dp[1] = 0
dp[2] = 1
dp[3] = 1
dp[4] = 2
dp[5] = 3

for i in range(6,n+1):
    dp[i] = dp[i-1]+1

    if i%2 == 0:
        dp[i] = min(dp[i],dp[i//2]+1)
    if i%3 == 0:
        dp[i] = min(dp[i],dp[i//3]+1)

print(dp[n])