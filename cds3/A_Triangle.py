l=list(map(int,input().split()))
l.sort()
seg=False
for i in range(2):
    for j in range(i+1,3):
        for k in range(j+1,4):
            if l[i]+l[j]>l[k]:
                print("TRIANGLE")
                exit()
            if l[i]+l[j]==l[k]:
                seg=True
if seg:
    print("SEGMENT")
else:
    print("IMPOSSIBLE")