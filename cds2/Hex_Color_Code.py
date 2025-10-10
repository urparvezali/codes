n = int(input())
s = ""
for i in range(n):
    s+=input()
ll = []
ss=""
for i in range(len(s)):
    if s[i]=='#':
        c=0
        while ((s[i+c]>='A' and s[i+c]<='F') or (s[i+c]>='a' and s[i+c]<='f') or (s[i]>='0' and s[i]<='9') or s[i]=='#') and c<7 and s+c<len(s):
            ss+=str(s[i+c])
            +c
        ll.append(ss)
        ss=""

print(ll)