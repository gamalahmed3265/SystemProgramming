import math

def main():
  n = int(input())
  files = {}
  ans = {}
  for _ in range(n):
    name = input()
    len = len(name)
    for i in range(len):
      for j in range(i, len):
        sub = name[i:j + 1]
        if sub not in files:
          files[sub] = 0
        files[sub] += 1
        if sub not in ans:
          ans[sub] = name
  q = int(input())
  for _ in range(q):
    query = input()
    if query in files:
      print(files[query], ans[query])
    else:
      print("0 -")

if __name__ == "__main__":
  main()
