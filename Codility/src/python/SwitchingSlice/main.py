# Switching Slice
# 
# Condition to satisfy for switching slice (aka "SS" or "ss")
# for Array of N elements, for a slice of (P,Q)
# 0 <= P <= Q <= N
# A[P] = A[P+2] = A[P+4] ...
# A[P+1] = A[P+3] = A[P+5]
# But A[P] does not have to equal A[P+1]
# start counting the switchig slice, but break the chain once
# the above conditions are violated
def solution(A):
    # write your code in Python 3.6
    max_ss_len = 0

    curr_ss_len = 0

    # Handle case where A is single-element or two-element
    # Note: Minimum iterable window size is 3, as single- and
    # two-element arrays have a switching length of 1
    # A 3-element array where no switching occurs is a special-case
    # As the even switch length is zero, but the odd switch length 
    # is still one
    # Note: A zero-element array is not switching, and function
    # will return 0
    if len(A) < 3:
        return len(A)
    else:
        if len(A) == 3:
            return 1

    # Use look-behind, sliding-window
    # Minimum window size is 3, which is why we
    # preset the current ss lengh to 3 when we find a 
    # new switching slice
    # Example [a,b,a]--length of this SS is 3
    for i in range(2,len(A)):
        if A[i] == A[i-2]:
            if curr_ss_len == 0:
                curr_ss_len += 3
            else:
                curr_ss_len += 1
            if curr_ss_len > max_ss_len:
                max_ss_len = curr_ss_len
        else:
            curr_ss_len = 0
        
    return max_ss_len

A = [5,4,-3,4,-3,5,-3,5]
#A = [1,2,3,4,5,6]
#A = [1]
#A = [1,2,1,3,1,3,1]
#A = [1,2,3]
A = [1,2,1]

val = solution(A)

print("val is %d" % val)