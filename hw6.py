
#need two for loops, one to work forward with indexing and one to work backwards
#need to check if elements to left are sorted
#then need to check if elements to right are sorted
#if you didn't have to change anything, then the list is already sorted
def cocktail_sort(l):
    end = len(l) - 1
    begin = 0

    #use begin and end to swap and work your way towards the middle
    #range (end, begin, -1) will work backwards
    
    swapping = "n"
    
    while swapping == "n": #this allows you to swap between forward and backward
        swapping = "already sorted" #this will allow you to exit the loop when the left is sorted
        for i in range(end):
            if l[i] > l[i+1]:
                l[i], l[i+1] = l[i+1], l[i] #swapping, this is siilar to bubble sort
                swapping = "n" #enter this condition? now continue this loop
        if swapping == "already sorted": break #break out of while loop, list is sorted
        #now, check the opposite direction
        swapping = "already sorted"
        end -= 1 #this helps you work your way towards the middle of the list
        for i in range(end, begin, -1):
            if l[i] > l[i+1]: #this will check if the leftmost element is greater than the rightmost element in that compairson but from the right direction
                l[i], l[i+1] = l[i+1], l[i] #this is similar to bubble sort with the swapping
                swapping ="n" #continue sorting the list
        begin += 1  #this helps you work your way towards the middle of the list
            
#here, inplement binary search
        #binary search implements two things: first it should check the bounds
def binary_search(item, l, left, right):
  if left == right:
    if l[left] > item: 
      return left
    else: #you need to return the next index
      return left + 1
  if left > right: return left
  #check if the left bound is greater than the right, within which you return left+1 because that's where the item belongs in the first pass
  #now, implement binary search
  med =(left + right) // 2
  if item < l[med]:
    return binary_search(item, l, left, med - 1)
  if item > l[med]:
    return binary_search(item, l, med + 1, right)
  else:
    return med


def opt_insertion_sort(l):
  length = len(l)
  for i in range(1, length): #cannot be range(length) because I was running into issue with 30 not moving
    item = l[i] 
    index = binary_search(item, l, 0, i - 1)
    l= l[0:index] + [item] + l[index:i] + l[i+1:]
  return l

   
if __name__ == "__main__":
    l = [5, 2, 2, 2, 2, 2, 1]
    cocktail_sort(l)
    assert l == [1, 2, 2, 2, 2, 2, 5]
    print("Sorted list:")
    print(opt_insertion_sort([1, 2, 3, 4, 5, 0]))
    print("All tests pass")
