def cocktail_sort(l):
    end = len(l) - 1
    begin = 0
    
    swapping = "n"
    
    while swapping == "n":
        swapping = "already sorted"
        for i in range(end):
            if l[i] > l[i+1]:
                l[i], l[i+1] = l[i+1], l[i] 
                swapping = "n" 
        if swapping == "already sorted": break 
        swapping = "already sorted"
        end -= 1 
        for i in range(end, begin, -1):
            if l[i] > l[i+1]: 
                l[i], l[i+1] = l[i+1], l[i] 
                swapping ="n" 
        begin += 1  
            

def binary_search(item, l, left, right):
  if left == right:
    if l[left] > item: 
      return left
    else: 
      return left + 1
  if left > right: return left
  med =(left + right) // 2
  if item < l[med]:
    return binary_search(item, l, left, med - 1)
  if item > l[med]:
    return binary_search(item, l, med + 1, right)
  else:
    return med


def opt_insertion_sort(l):
  length = len(l)
  for i in range(1, length):
    item = l[i] 
    index = binary_search(item, l, 0, i - 1)
    l= l[0:index] + [item] + l[index:i] + l[i+1:]
  return l

   
if __name__ == "__main__":
    l = [5, 2, 2, 2, 2, 2, 1]
    cocktail_sort(l)
    assert l == [1, 2, 2, 2, 2, 2, 5]
    l = opt_insertion_sort([1, 2, 3, 4, 5, 0])
    assert l == [0, 1, 2, 3, 4, 5]
    print("All tests pass")
