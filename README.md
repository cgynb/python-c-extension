# c extension example

If you really want to speed up you code to process large amounts of data, you could try to write some function in c.

# usage

1. compare the time of running `fib(15)` 100000 times in c and python
2. a tutorial to write c extension

# steps
## run test file
```cmd
git clone https://github.com/cgynb/c-python-extension
pip install .
python test.py
```
result: 
```
c: 0.1483301s
py: 8.8122067s
py is 60 times more than c
```

## write an extension
### import Python.h head file
```C
#include <Python.h>
``` 
### write you function
If you want to convert basic type (like int float) into python object, you can google `c python api`, or you can get info from [https://docs.python.org/3/c-api/concrete.html](https://docs.python.org/3/c-api/concrete.html).

You could find some example in src/cgy_ext.c.

......