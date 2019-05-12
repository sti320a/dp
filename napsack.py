n = 6
wv = [(2, 3), (1, 2), (3, 6), (2, 1), (1, 3), (5, 85)]
W = 8

dp = [[0] * 10] * 10  # [[0,0,..,0], [0,0,..,0], ..., [0,0,..,0]]

for i in range(0, n):
    for w in range(0, W):
        if w >= wv[i][0]:
            dp[i+1][w] = max(dp[i][w-wv[i][0]] + wv[i][1], dp[i][w])
        else:
            dp[i+1][w] = dp[i][w]

print(dp[n][w])
