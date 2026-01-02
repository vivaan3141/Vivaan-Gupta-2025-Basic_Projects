import ctypes
import matplotlib.pyplot as plt


lib = ctypes.CDLL(
    "/Users/vivaananika/CLionProjects/linreg.cpp/liblinreg.dylib"
)

lib.slope.argtypes = (
    ctypes.POINTER(ctypes.c_double),
    ctypes.POINTER(ctypes.c_double),
    ctypes.c_int
)
lib.slope.restype = ctypes.c_double

lib.yInt.argtypes = (
    ctypes.POINTER(ctypes.c_double),
    ctypes.POINTER(ctypes.c_double),
    ctypes.c_int
)
lib.yInt.restype = ctypes.c_double

n = int(input("How many data points? \n"))

XArray = ctypes.c_double * n
YArray = ctypes.c_double * n

x = XArray()
y = YArray()

for i in range(n):
    x[i] = float(input(f"X value {i + 1}\n"))
    y[i] = float(input(f"Y value {i + 1}\n"))

m = lib.slope(x, y, n)
b = lib.yInt(x, y, n)

print("Slope =", m)
print("Y int =", b)

xPred = float(input("X value for prediction:\n"))
print((xPred * m) + b)

plt.scatter(x, y)


x1=-100
y1=(x1*m)+b
x2=100
y2=(x2*m)+b
plt.plot([x1, x2], [y1, y2])

plt.xlabel('X')
plt.ylabel('Y')
plt.title('Regression Points')
plt.grid(True)

plt.show()
