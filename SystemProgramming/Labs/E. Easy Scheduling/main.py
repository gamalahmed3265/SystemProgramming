import math
def solve(h, p):
    sum = 1
    a = 0
    for i in range(1, h):
        k = pow(2, i) - a
        a = 0
        if k <= p:
            sum += 1
        else:
            if k % p != 0:
                sum += 1
                a = p - (k % p)
            sum += k // p
    print(sum)

def main():
 
  t = int(input())

  for _ in range(t):
    h, p = map(int, input().split())

    print(solve(h, p))


if __name__ == "__main__":
  main()
