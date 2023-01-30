def depth_first_search(arr):
    results = []

    def dfs(index, path):
        if index == len(arr):
            results.append(path)
            return
        
        for i in range(index, len(arr)):
            new_path = path + [arr[i]]
            dfs(i + 1, new_path)

    dfs(0, [])
    return results

arr = ["A", "B", "C"]
print(depth_first_search(arr))