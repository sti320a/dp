n = 3
a = [-9, -16]

dp = [0] * 1010

for i in range(0, len(a)):
    dp[i + 1] = max(dp[i], dp[i] + a[i])

print(dp[n])
