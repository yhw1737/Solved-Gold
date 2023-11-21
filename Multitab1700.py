N,K=map(int,input().split())
L=list(input().split())
T=[]
r=0
for n,i in enumerate(L):
    if i not in T:
        if len(T)>=N:
            f=-1
            for v in T:
                f=max((L+T).index(v, n),f)
            T.remove((L+T)[f])
            r+=1
        T.append(i)
print(r)