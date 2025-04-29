n, m = map(int, input().split())
maxcount = 0

arr = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)

result = []

def dfs(start):
    stack = [start]
    visited[start] = True
    cnt = 1

    while stack:
        node = stack.pop()
        for i in arr[node]:
            if not visited[i]:
                visited[i] = True
                stack.append(i)
                cnt += 1
    return cnt

for _ in range(m):
    a, b = map(int, input().split())
    arr[b].append(a)

for i in range(1, n + 1):
    visited = [False] * (n + 1)  # 방문 배열을 매번 초기화
    if not arr[i]:
        continue
    count = dfs(i)
    if count > maxcount:
        maxcount = count
        result.clear()
        result.append(i)
    elif count == maxcount:
        result.append(i)

print(*result)
