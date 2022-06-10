def max_min(array):
    # Length of the array
    num_of_elements = len(array)
    # If num of elements is 1 then return the element
    if num_of_elements == 1:
        return(array[0], array[0])
    # If num of elements is 2 then return max and min by comparing them
    elif num_of_elements == 2:
        if(array[0] < array[1]):
            return(array[0], array[1])
        else:
            return(array[1], array[0])
    # For more than two elements divide the array into sub groups
    else:
    # Divide equal
        mid = num_of_elements // 2
    # Store
        left = array[:mid]
        right = array[mid:]
    # Recursive Call
        [Lmin, Lmax] = max_min(left)
        [Rmin, Rmax] = max_min(right)
    # Finally find min, max values in left and right subarrays
        if(Lmin < Rmin):
            min = Lmin
        else:
            min = Rmin
        if(Lmax > Rmax):
            max = Lmax
        else:
            max = Rmax

    return min, max

# Main Function
array = [22, 13, -5, -8, 15, 60, 17, 31, 47]
min, max = max_min(array)
print("Given Array: ", array)
print(f"Minimum Element: {min} , Maximum Element: {max}")

array = [82, 36, 49, 91, 12, 14, 6, 76, 92, 55]
min, max = max_min(array)
print("Given Array: ", array)
print(f"Minimum Element: {min} , Maximum Element: {max}")

array = [50, 40, -5, -9, 45, 90, 65, 25, 75]
min, max = max_min(array)
print("Given Array: ", array)
print(f"Minimum Element: {min} , Maximum Element: {max}")