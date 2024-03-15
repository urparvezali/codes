a = "bglosz691052"
b = "691052bglosz"
while 1:
    s = input()
    if s == 'the end.':
        break
    print("".join([b[a.index(i)] if i in a else i for i in s]))
