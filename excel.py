def check_equal_name(name1, name2):
    spl1 = name1.split()
    spl2 = name2.split()
    return_string = ""
    haha = 2
    if (name1[0] == name2[0]):
        if len(spl1) < len(spl2):
            return_string = (spl1[0] + spl2[1] + spl1[1] + spl1[2])
            return return_string
        else:
            haha = 3
    else:
        return False


with open("1.txt", "r") as f:
    arr = []
    res = []
    for line in f.readlines():
        arr.append(line)

    for i in range(len(arr)):
        if (check_equal_name(arr[i], arr[i+1]) != False):
            res.append(arr[i])
        else:
            res.append(arr[i])
            res.append(arr[i + 1])
    with open("res.txt", "w") as result:
        for i in range(len(res)):
            print(res[i])
