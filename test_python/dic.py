from collections import defaultdict

my_dic = defaultdict(lambda: [1] * 2)

for (k,v) in  my_dic.items():
    print (k)
    print (v)
