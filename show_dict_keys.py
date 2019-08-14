# coding: utf-8
def skeys(d: dict, show_type=True, depth=0):
    for k in d.keys():
        print('|  ' * depth, end='')
        if isinstance(d[k], dict):
            print(k)
            skeys(d[k], show_type=show_type, depth=depth+1)
        else:
            type_s = '[' + type(d[k]).__name__ + '] ' if show_type else ''
            try:
                len_s = ' (' + str(len(d[k])) + ')'
            except Exception:
                len_s = ' (-)'
            print('|_ ' + type_s + k + len_s)
            
if __name__ == "__main__":
    testdict = {'field': 7,
                'subdict': {'foo': 3, 'bar': 42},
                'aList': [3,4,5,6,7,8,9],
                'myString': "holly had a little lamb..", 
                'nested': {'level1': {'level2': {'level3': {'level4': "the treasure at the end of the rainbow"}}}},
               }

    print("dictionary:")
    skeys(testdict)

    print("")
    print("dictionary (fields only):")
    skeys(testdict, show_type=False)

    input('hit enter to quit.')
