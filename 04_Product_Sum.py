# Given a special array find the product sum of special array.
# A special array is an array consisting of integers and or other special array.
# The product of the array sum is the sum of array*(level of array)
# EXAMPLE:
# [5,2,[7,-1],3,[6,[-13,8],4]]
     # ^s*2   ^s*2  ^s*3 ^s*1 -- s is sum of that array.
# (5 + 2 + (7+-1)*2 + (6+(-13+8)*3+4)*2)*1 = 12

# Time - O(n) Space - O(k) - recursive calls(k - max inner array levels)

def productSum(array,mul = 1):
    sum = 0
    for x in array:
        if type(x) == list:
            sum+= productSum(array,mul+1)
        else:
            sum+= x
    return sum*mult