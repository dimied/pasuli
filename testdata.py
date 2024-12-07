import random

xLimit = 0x1 << 72
yLimit = 0x1 << 72
divLimit = 0x1 << 32

addResult = []
subResult = []
mulResult = []
divResult = []

numTests = 2000

for i in range(0, numTests):
    x = random.randint(0, xLimit)
    y = random.randint(0, yLimit)
    d = random.randint(0, divLimit)
    add = x + y
    sub = x - y
    mul = x * y
    div = x // d
    rest = x % d
    addResult.append([x, y, add])
    subResult.append([x, y, sub])
    mulResult.append([x, y, mul])
    divResult.append([x, d, div, rest])
    # print("{", x, ",", y, ",", add, ",", sub, ",", mul, "}")


def numBytes(x):
    return (x.bit_length() + 7) // 8


def toByteArray(x):
    res = []
    while x > 0:
        res.append(x & 0xFF)
        x >>= 8
    return res


def cLikeArray(v):
    res = "{"
    a = False
    for i in v:
        if a:
            res += ", "
        res += str(i)
        a = True
    res += "}"
    return res


nC = False
print('#include "myint_test_data.h"')

print("IntTest addTests[" + str(numTests) + "] = {")
for v in addResult:
    print("{")
    print(' ptrA: "' + str(v[0]) + '",')
    print(' ptrB: "' + str(v[1]) + '",')
    print(' ptrC: "' + str(v[2]) + '",')

    print(" signA:0, signB:0, signC:0,")

    b1 = toByteArray(v[0])
    n1 = len(b1)
    print(" aBytes: " + cLikeArray(b1) + ",")

    b2 = toByteArray(v[1])
    n2 = len(b2)
    print(" bBytes: " + cLikeArray(b2) + ",")

    b3 = toByteArray(v[2])
    n3 = len(b3)
    print(" cBytes: " + cLikeArray(b3) + ",")

    print(" numBytesA: " + str(n1) + ",")
    print(" numBytesB: " + str(n2) + ",")
    print(" numBytesC: " + str(n3) + "")

    print("},")

print("};")

print("IntTest subTests[" + str(numTests) + "] = {")
for v in subResult:
    print("{")
    print(' ptrA: "' + str(v[0]) + '",')
    print(' ptrB: "' + str(v[1]) + '",')
    print(' ptrC: "' + str(v[2]) + '",')

    signA = 0
    signB = 0
    signC = 0
    if v[2] < 0:
        signC = 1
        v[2] = -v[2]
    print(
        " signA:" + str(signA) + ", signB:" + str(signB) + ", signC:" + str(signC) + ","
    )
    b1 = toByteArray(v[0])
    n1 = len(b1)
    print(" aBytes: " + cLikeArray(b1) + ",")

    b2 = toByteArray(v[1])
    n2 = len(b2)
    print(" bBytes: " + cLikeArray(b2) + ",")

    b3 = toByteArray(v[2])
    n3 = len(b3)
    print(" cBytes: " + cLikeArray(b3) + ",")

    print(" numBytesA: " + str(n1) + ",")
    print(" numBytesB: " + str(n2) + ",")
    print(" numBytesC: " + str(n3) + "")

    print("},")

print("};")

print("IntTest mulTests[" + str(numTests) + "] = {")
for v in mulResult:
    print("{")
    print(' ptrA: "' + str(v[0]) + '",')
    print(' ptrB: "' + str(v[1]) + '",')
    print(' ptrC: "' + str(v[2]) + '",')

    print(" signA:0, signB:0, signC:0,")

    b1 = toByteArray(v[0])
    n1 = len(b1)
    print(" aBytes: " + cLikeArray(b1) + ",")

    b2 = toByteArray(v[1])
    n2 = len(b2)
    print(" bBytes: " + cLikeArray(b2) + ",")

    b3 = toByteArray(v[2])
    n3 = len(b3)
    print(" cBytes: " + cLikeArray(b3) + ",")

    print(" numBytesA: " + str(n1) + ",")
    print(" numBytesB: " + str(n2) + ",")
    print(" numBytesC: " + str(n3) + "")

    print("},")

print("};")

print("IntTest divTests[" + str(numTests) + "] = {")
for v in divResult:
    print("{")
    print(' ptrA: "' + str(v[0]) + '",')
    print(' ptrB: "' + str(v[1]) + '",')
    print(' ptrC: "' + str(v[2]) + '",')

    print(" signA:0, signB:0, signC:0,")

    b1 = toByteArray(v[0])
    n1 = len(b1)
    print(" aBytes: " + cLikeArray(b1) + ",")

    b2 = toByteArray(v[1])
    n2 = len(b2)
    print(" bBytes: " + cLikeArray(b2) + ",")

    b3 = toByteArray(v[2])
    n3 = len(b3)
    print(" cBytes: " + cLikeArray(b3) + ",")

    print(" numBytesA: " + str(n1) + ",")
    print(" numBytesB: " + str(n2) + ",")
    print(" numBytesC: " + str(n3) + ",")

    r3 = toByteArray(v[3])
    nr3 = len(r3)
    print(' ptrR: "' + str(v[3]) + '",')
    print(" rBytes: " + cLikeArray(r3) + ",")
    print(" numBytesR: " + str(nr3) + "")

    print("},")

print("};")
