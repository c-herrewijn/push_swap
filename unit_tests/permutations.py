from itertools import permutations

p = permutations(range(5))

for items in p:
    order = " ".join(str(item) for item in items)
    # print(f"./push_swap {order}")
    print(f"./push_swap {order} | wc -l")
    # print(f"ARG=\"{order}\"; ./push_swap $ARG | ./checker_Mac $ARG")

