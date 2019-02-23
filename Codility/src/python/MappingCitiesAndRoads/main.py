# Cities and Roads
# We have an array that describes a connectivity for the network
# We assume only one node will be designated the capital T[P]=Q,
# where P==Q.
# To compute the distances from the capital, we can backwards trace
# From the capital, doing a reverse lookup in the array.
# To maintain storage requirements, we can only use an array of same
# size as T to store the distances.
# We will first compute the distances of each city from the capital.
# Then we will transform the data to the required format of
# M-1 roads, with a frequency map to show number of cities of each
# distance from the capital.
# Input is Array T, representing a graph of M vertices, each 
# representing of cities connected by M-1 edges.
# Output is Array D, representing the distribution of cities at different
# distances from the capital.  D will be M-1 in size.
# Time complexity: O(M)
# Space complexity: T(M) = 2M (for the R and D lists) plus another
# M for the K dict.  In total, spatial complexity is O(M).
def solution(T):
    # First create an adjacency count list K
    K = {}
    
    # And a list representing number of hops to get to each city
    # R[i] = j -- City i takes j hops from capital
    R = [0]*len(T)

    # Finally, we will use a list as the return value representing
    # a frequency map of city distances from the capital.
    # This list will be size M-1 because this graph of M vertices
    # has only M-1 edges (each node connected only once).
    # Note, I'm deliberately leaving D as size M so I can take
    # advantage of the alignment of distances to the indexes in the
    # list.  At the end of the method, I'll trim the head of D to
    # make it M-1.
    D = [0]*len(T)

    # First find the capital
    cap_index = -1
    for i in range(0,len(T)):
        if i == T[i]:
            cap_index = i
            break
    if cap_index == -1:
        return None

    # Now reverse T so we can backwards iterate from the capital
    # to the other cities.
    for i,v in enumerate(T):
        if i == cap_index:
            continue
        if v not in K:
            K[v] = [i]
        else:
            K[v].append(i)

    # Next recursively traverse from capital to each city, counting
    # along the way the route and storing it into the Route list, R
    RecursiveTraceMap(K, cap_index, R, 0)

    # Now we need to get the answer in the format requested by the
    # question.  From here transform the data in R to essentially
    # create a histogram of city distances from the capital.
    for i in R:
        D[i] += 1

    # Trim D to equal M-1 edges
    D = D[1:]

    return D

def RecursiveTraceMap(K, index, Routes, R_count):
    
    # Recursion Base case
    # We have reached a terminal node and can store the length
    if index in K:
        dest_list = K[index]
        R_count += 1
        for i in dest_list:
            Routes[i] = R_count
            RecursiveTraceMap(K, i, Routes, R_count)
    return 


T = [0]*10
T[0] = 9  
T[1] = 1    
T[2] = 4
T[3] = 9    
T[4] = 0    
T[5] = 4
T[6] = 8    
T[7] = 9    
T[8] = 0
T[9] = 1

S = [0]*5
S[0] = 1
S[1] = 3
S[2] = 1
S[3] = 3
S[4] = 1

L = [0]*10
L[0] = 1
L[1] = 2
L[2] = 2
L[3] = 1
L[4] = 1
L[5] = 1
L[6] = 1
L[7] = 1
L[8] = 1
L[9] = 1

L = [0]*10
L[0] = 1
L[1] = 1
L[2] = 1
L[3] = 1
L[4] = 1
L[5] = 1
L[6] = 1
L[7] = 1
L[8] = 1
L[9] = 1

val = solution(L)

print(val)