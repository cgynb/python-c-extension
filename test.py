from timeit import repeat
from math import ceil


def py_fib(n):
    if n == 1 or n == 2:
        return 1
    return py_fib(n-1) + py_fib(n-2)


c = sum(repeat("fib(15)", setup="from cgy_ext import fib", number=10000, repeat=10))
py = sum(repeat("py_fib(15)", setup="from __main__ import py_fib", number=10000, repeat=10))
print(f"c: {c}s")
print(f"py: {py}s")
print(f"py is {ceil(py / c)} times more than c")
