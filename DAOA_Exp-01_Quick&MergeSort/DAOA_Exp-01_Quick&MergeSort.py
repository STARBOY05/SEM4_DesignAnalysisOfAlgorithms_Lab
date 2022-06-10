# Quick Sort Algorithm
def Partition(array, start, end):
    pivot = array[start]
    low = start + 1
    high = end
    while True:
        while low <= high and array[high] >= pivot:
            high -= 1
        while low <= high and array[low] <= pivot:
            low += 1
        if low <= high:
            array[low], array[high] = array[high], array[low]
        else:
            break
    array[start], array[high] = array[high], array[start]
    return high

def Quick_Sort(array, start, end):
    if start >= end:
        return

    low = Partition(array, start, end)
    Quick_Sort(array, start, low-1)
    Quick_Sort(array, low+1, end)
# 1
array = [44,33,11,55,77,90,40,60,99,22,88]
# print("Array before sorting: ", array)
Quick_Sort(array, 0, len(array) - 1)
# print("Array after sorting: ", array)
# 2
array = [17, 9, 22, 31, 7, 12, 10, 21, 13, 29, 18, 20, 11]
# print("Array before sorting: ", array)
# Quick_Sort(array, 0, len(array) - 1)
# print("Array after sorting: ", array)
# 3
array = [100, 76, 80, 9, 111, 50]
# print("Array before sorting: ", array)
# Quick_Sort(array, 0, len(array) - 1)
# print("Array after sorting: ", array)

# Merge Sort Algorithm
def merge(array,left,right):
    i = j = k = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            array[k] = left[i]
            i += 1
        else:
            array[k] = right[j]
            j += 1
        k += 1

    # For all the remaining values
    while i < len(left):
        array[k] = left[i]
        i += 1
        k += 1

    while j < len(right):
        array[k]=right[j]
        j += 1
        k += 1

def mergeSort(array):
    if len(array) > 1:
        mid = int(len(array) / 2)
        left = array[:mid]
        right = array[mid:]

        # Recursive call on each half)
        mergeSort(left)
        mergeSort(right)
        merge(array,left,right)

# # 1
array = [44,33,11,55,77,90,40,60,99,22,88]
print("Array before sorting: ", array)
mergeSort(array)
print("Array after sorting: ", array)


# # 2
# array = [17, 9, 22, 31, 7, 12, 10, 21, 13, 29, 18, 20, 11]
# print("Array before sorting: ", array)
# mergeSort(array)
# print("Array after sorting: ", array)

# # 3
# array = [100, 76, 80, 9, 111, 50]
# print("Array before sorting: ", array)
# mergeSort(array)
# print("Array after sorting: ", array)

# Quick Sort Algorithm with pivot at end
def Partition(array, start, end):
    pivot = array[end]
    low = start
    high = end-1

    while True:
        while low <= high and array[high] >= pivot:
            high -= 1
        while low <= high and array[low] <= pivot:
            low += 1
        if low <= high:
            array[low], array[high] = array[high], array[low]
        else:
            break

    array[start], array[high] = array[high], array[start]
    return high

def Quick_Sort(array, start, end):
    if start >= end:
        return

    low = Partition(array, start, end)
    Quick_Sort(array, start, low-1)
    Quick_Sort(array, low+1, end)
        
array = [5,1,4,3,2]
# print("Array before sorting: ", array)
Quick_Sort(array, 0, len(array) - 1)
# print("Array after sorting: ", array)   


# PIVOT AS END
# Quick Sort Algorithm
def Partition(array, start, end):
    pivot = array[end]
    low = start
    high = end-1
    while True:
        while low <= high and array[high] >= pivot:
            high -= 1
        while low <= high and array[low] <= pivot:
            low += 1
        if low <= high:
            array[low], array[high] = array[high], array[low]
        else:
            break
    array[end], array[low] = array[low], array[end]
    return low

def Quick_Sort(array, start, end):
    if start >= end:
        return

    high = Partition(array, start, end)
    Quick_Sort(array, start, high-1)
    Quick_Sort(array, high+1, end)
# 1
array = [44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88]
# print("Array before sorting: ", array)
Quick_Sort(array, 0, len(array) - 1)
# print(" Array after sorting: ", array)
