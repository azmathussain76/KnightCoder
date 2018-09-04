def solution(A):
    # write your code in Python 3.6
    max_val = max(A)
    if (max_val) <= 0:
        max_val = 1
    a_freq = [0]*(max_val+1)
    for i in A:
        if i <= 0:
            next
        else:
            a_freq[i] += 1
    rval = 0
    for i in range(1,len(a_freq)):
        if a_freq[i] == 0:
            rval = i
            break
    if rval == 0:
        rval = max_val + 1
    return rval


# Main code
A = [1, 3, 6, 4, 1, 2]
A = [-3,-2,0,1,2,3,5,7]
#A = [1,2,3]
#A = [-1,-3]

val = solution(A)

print(val)