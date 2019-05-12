n = 6
W = 8
wv = [(2, 3), (1, 2), (3, 6), (2, 1), (1, 3), (5, 85)]
w = [2, 1, 3, 2, 1, 5]
v = [3, 2, 6, 1, 3, 85]

# 品物の番号と、ナップサックの空き容量を入れると、
# 取れる価値の最大値を返すメソッド


def rec(product_num, capacity):

    # 品物がもう残ってないとき
    if product_num == n:
        return 0

    # ナップサックの空き領域が品物の重さよりも小さい時（入れられない時）
    elif capacity <= w[product_num]:
        return rec(product_num+1, capacity)

    # ナップサックの空き容量があって、品物を入れるか入れないか選べるとき
    else:
        return max(
            # 品物を入れないで、今の状態の価値を返す
            rec(product_num + 1, capacity),
            # 品物を入れて、品物の価値を加算して返す（重さの分だけ空き容量を減算する）
            rec(product_num + 1, capacity - w[product_num]) + v[product_num]
        )


ans = rec(0, 8)
print(ans)
