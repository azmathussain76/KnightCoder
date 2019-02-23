# Mary giving away her N/2 candies to her brother
# She is trying to retain the greatest variety, so using a 
# Python dictionary to store the frequencies, since they can
# vary greatly from N=2..100000
# solution (T)
# Input: Array of ints
# Output: returns an integer indicating the number of different 
# candies Mary retains
# Time complexity: O(n log n)
# Space complexity: O(n) for the dictionary
def solution(T):
    # write your code in Python 3.6

    # Build the dictionary of frequencies for the T's elements
    T_dict = {}
    for t in T:
        if t in T_dict:
            T_dict[t] += 1
        else:
            T_dict[t] = 1
    
    # Compute the number to give away
    give_num = int(len(T)/2)

    # Use a greedy strategy where Mary starts by giving away
    # the most like candies until she fulfills N/2 given
    # Each time we exhause a candy type, remove it from the dict
    while give_num > 0:
        curr_max = max(T_dict, key=T_dict.get)
        if give_num >= T_dict[curr_max]:
            give_num -= T_dict[curr_max]
            del T_dict[curr_max]
        else:
            T_dict[curr_max] -= give_num
            give_num = 0
    
    #print(T_dict)
    # Remaining candies should be the length of the dictionary
    keep_val = len(T_dict)

    return keep_val

from time import time


T = [3, 4, 7, 7, 6, 6]
s_time = time()
T = [80, 80, 1000000000, 80, 80, 80, 80, 80, 80, 123456789]
e_time = time()
T = [1,2,3,4,5,6,7,8]
#T = [1,2,3,4]
#T = [1,2,3,4,5,5,5,5]
#T = [1,2,3,4,5,5,5,6,6,6]

const_time = e_time - s_time

s_time = time()
val =  solution(T)
e_time = time()

diff_time = e_time - s_time

l = len(T)

print(val)
print("time was %f" % diff_time)
print("N is %d" % l)
from math import log
complexity = l*log(l,2)
print("complexity is %f" % complexity)
print("%f" % (diff_time/complexity))
print("const time %f" % const_time)