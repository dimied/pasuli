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
print("")
print("")
print('#include "myint_test_data.h"')
print("")
print("")


def generateAddTests():

    idx = 0
    print("")
    print("")
    for v in addResult:
        b1 = toByteArray(v[0])
        b2 = toByteArray(v[1])
        b3 = toByteArray(v[2])

        n = "aBytesAdd" + str(idx)
        print("unsigned char " + n + "[20] = " + cLikeArray(b1) + ";")
        n = "bBytesAdd" + str(idx)
        print("unsigned char " + n + "[20] = " + cLikeArray(b2) + ";")
        n = "cBytesAdd" + str(idx)
        print("unsigned char " + n + "[20] = " + cLikeArray(b3) + ";")
        idx += 1

    idx = 0
    print("")
    print("")
    print("IntTest addTests[" + str(numTests) + "] = {")
    for v in addResult:
        s = "INIT_INT_TEST("
        s += '"' + str(v[0]) + '",'
        s += '"' + str(v[1]) + '",'
        s += '"' + str(v[2]) + '",'
        s += "0,0,0,"  # signs

        b1 = toByteArray(v[0])
        b2 = toByteArray(v[1])
        b3 = toByteArray(v[2])
        n1 = len(b1)
        n2 = len(b2)
        n3 = len(b3)
        # bytes
        s += "aBytesAdd" + str(idx) + ","
        s += "bBytesAdd" + str(idx) + ","
        s += "cBytesAdd" + str(idx) + ","
        # num bytes
        s += str(n1) + ","
        s += str(n2) + ","
        s += str(n3) + ")"
        print(s + ",")
        idx += 1

    print("};")


def generateSubTests():

    idx = 0
    print("")
    print("")
    for v in addResult:
        b1 = toByteArray(v[0])
        b2 = toByteArray(v[1])
        b3 = toByteArray(v[2])

        n = "aBytesSub" + str(idx)
        print("unsigned char " + n + "[20] = " + cLikeArray(b1) + ";")
        n = "bBytesSub" + str(idx)
        print("unsigned char " + n + "[20] = " + cLikeArray(b2) + ";")
        n = "cBytesSub" + str(idx)
        print("unsigned char " + n + "[20] = " + cLikeArray(b3) + ";")
        idx += 1

    idx = 0
    print("")
    print("")
    print("IntTest subTests[" + str(numTests) + "] = {")
    for v in subResult:

        signA = 0
        signB = 0
        signC = 0
        if v[2] < 0:
            signC = 1
            v[2] = -v[2]

        s = "INIT_INT_TEST("
        s += '"' + str(v[0]) + '",'
        s += '"' + str(v[1]) + '",'
        s += '"' + str(v[2]) + '",'
        s += "0,0," + str(signC) + ","  # signs

        b1 = toByteArray(v[0])
        b2 = toByteArray(v[1])
        b3 = toByteArray(v[2])
        n1, n2, n3 = len(b1), len(b2), len(b3)
        # bytes
        s += "aBytesSub" + str(idx) + ","
        s += "bBytesSub" + str(idx) + ","
        s += "cBytesSub" + str(idx) + ","
        # num bytes
        s += str(n1) + ","
        s += str(n2) + ","
        s += str(n3) + ")"
        print(s + ",")
        idx += 1

    print("};")


def generateMulTests():
    idx = 0
    print("")
    print("")
    for v in mulResult:
        b1 = toByteArray(v[0])
        b2 = toByteArray(v[1])
        b3 = toByteArray(v[2])

        n = "aBytesMul" + str(idx)
        print("unsigned char " + n + "[20] = " + cLikeArray(b1) + ";")
        n = "bBytesMul" + str(idx)
        print("unsigned char " + n + "[20] = " + cLikeArray(b2) + ";")
        n = "cBytesMul" + str(idx)
        print("unsigned char " + n + "[20] = " + cLikeArray(b3) + ";")
        idx += 1

    idx = 0
    print("")
    print("")

    print("IntTest mulTests[" + str(numTests) + "] = {")
    for v in mulResult:
        s = "INIT_INT_TEST("
        s += '"' + str(v[0]) + '",'
        s += '"' + str(v[1]) + '",'
        s += '"' + str(v[2]) + '",'
        s += "0,0,0,"  # signs

        b1 = toByteArray(v[0])
        b2 = toByteArray(v[1])
        b3 = toByteArray(v[2])
        n1 = len(b1)
        n2 = len(b2)
        n3 = len(b3)
        # bytes
        s += "aBytesMul" + str(idx) + ","
        s += "bBytesMul" + str(idx) + ","
        s += "cBytesMul" + str(idx) + ","
        # num bytes
        s += str(n1) + ","
        s += str(n2) + ","
        s += str(n3) + ")"
        print(s + ",")
        idx += 1

    print("};")


def generateDivTests():
    idx = 0
    print("")
    print("")
    for v in divResult:
        b1 = toByteArray(v[0])
        b2 = toByteArray(v[1])
        b3 = toByteArray(v[2])
        rest = toByteArray(v[2])

        n = "aBytesDiv" + str(idx)
        print("unsigned char " + n + "[20] = " + cLikeArray(b1) + ";")
        n = "bBytesDiv" + str(idx)
        print("unsigned char " + n + "[20] = " + cLikeArray(b2) + ";")
        n = "cBytesDiv" + str(idx)
        print("unsigned char " + n + "[20] = " + cLikeArray(b3) + ";")
        n = "rBytesDiv" + str(idx)
        print("unsigned char " + n + "[20] = " + cLikeArray(rest) + ";")
        idx += 1

    idx = 0
    print("")
    print("")
    print("IntTest divTests[" + str(numTests) + "] = {")
    for v in divResult:

        s = "INIT_INT_TEST_DIV("
        s += '"' + str(v[0]) + '",'
        s += '"' + str(v[1]) + '",'
        s += '"' + str(v[2]) + '",'
        s += "0,0,0,"  # signs

        b1 = toByteArray(v[0])
        b2 = toByteArray(v[1])
        b3 = toByteArray(v[2])
        n1, n2, n3 = len(b1), len(b2), len(b3)

        rest = toByteArray(v[3])
        nrest = len(rest)
        # bytes
        s += "aBytesDiv" + str(idx) + ","
        s += "bBytesDiv" + str(idx) + ","
        s += "cBytesDiv" + str(idx) + ","
        # num bytes
        s += str(n1) + ","
        s += str(n2) + ","
        s += str(n3) + ","
        #rest
        s += '"' + str(v[3]) + '",'
        s += "bBytesDiv" + str(idx) + ","
        s += str(nrest) + ")"
        print(s + ",")
        idx += 1

    print("};")


generateAddTests()
generateSubTests()
generateMulTests()
generateDivTests()




