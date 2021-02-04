# https://zerojudge.tw/ShowProblem?problemid=f634
from sys import stdin
(n ,m)= map(int, stdin.readline().split())

#測試時用這個 1.5s
st= []
for _ in range(m):
    st.append(stdin.readline())
st = set(st)

# submit 這個 1.1s
#st = set( stdin.readlines())

A= ['1':0, '2':0, '3':0}
B= {'1':0, '2':0, '3':0}

for key in st:
    st.add(key)
    (s,a,b) = key.split()
    A[a]+=1
    B[b]+=1
    

ans = int(round((A['1']+A['2']+A['3'])*1000 /n, 0))
print(f"navy:{A['1']} army:{A['2']} air:{A['3']}")
print(f"officer:{B['1']} sergeant:{B['2']} soldier:{B['3']}")
print(f"survival rate: {ans//10}.{ans % 10}%")


