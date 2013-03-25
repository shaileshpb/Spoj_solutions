tc=int(raw_input())
for i in range(0,tc):
    n=float(raw_input());
    ans=0.0
	ans=float(ans)
    k=float(n)
    for j in range(0,n):
        ans=float(ans+(n/k))
        k=k-1
    print float(ans)