def fun(n):
	x,cnt=1,1
	for k in range(19):
		i,tmp=k,0
		while(i>0 and (x^(1<<i))<=n):
				tmp+=i+1
				break
			i-=1
		x=x<<1+1
		cnt+=tmp
	return cnt

a, b = list(map(int, input().split()))
print(fun(b)-fun(a-1))