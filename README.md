# python-c-extension

这是一个编写python的c扩展的基本样例

# 使用：

可以点击直接下载[轮子文件](https://github.com/cgynb/python-c-extension/raw/main/cgy_ext-1-cp39-cp39-win_amd64.whl)
然后使用`pip install cgy_ext-1-cp39-cp39-win_amd64.whl`
这个提供了四个函数

```c
prime_in_100
gen_lst
gen_dct
show_name
```


具体也可以查看test.py

# 编写

## 1. 编写.c文件

总共有5个步骤

1. 导入这个头文件`#include <Python.h>` 里面有很多c/python的api
2. 编写你的函数

```c
static PyObject* _gen_lst(PyObject* self){
	printf("gen lst func run\n");
	PyObject* lst = PyList_New(0);
	PyList_Append(lst, PyUnicode_FromString("cgy"));
	return lst;
}
```

3. 将所有函数添加到这个结构体内

```c
static struct PyMethodDef methods[] = {
	{"gen_lst", (PyCFunction)_gen_lst, METH_VARARGS},
	{"gen_dct", (PyCFunction)_gen_dct, METH_VARARGS},
	{"show_name", (PyCFunction)_show_name, METH_VARARGS},
	{"prime_in_100", (PyCFunction)_prime_in_100, METH_VARARGS},
	{NULL, NULL, NULL}
};
```

4. 写一下模块的信息

```c
static struct PyModuleDef module = {
	PyModuleDef_HEAD_INIT,
	"cgy_ext",
	NULL,
	-1,
	methods
};

```
5. 生成模块
```c
PyMODINIT_FUNC PyInit_cgy_ext(void){
	return PyModule_Create(&module);
}
```

## 2. 编写setup.py文件
这里要写你的库的信息
详见setup.py

## 3. 编译
运行这个命令 `pip install .`

# python-c-extension

这是一个编写python的c扩展的基本样例

# 使用：

可以点击直接下载[轮子文件](https://github.com/cgynb/python-c-extension/raw/main/cgy_ext-1-cp39-cp39-win_amd64.whl)
然后使用`pip install cgy_ext-1-cp39-cp39-win_amd64.whl`
这个提供了四个函数

```c
prime_in_100
gen_lst
gen_dct
show_name
```


具体也可以查看test.py

# 编写

## 1. 编写.c文件

总共有5个步骤

1. 导入这个头文件`#include <Python.h>` 里面有很多c/python的api
2. 编写你的函数

```c
static PyObject* _gen_lst(PyObject* self){
	printf("gen lst func run\n");
	PyObject* lst = PyList_New(0);
	PyList_Append(lst, PyUnicode_FromString("cgy"));
	return lst;
}
```

3. 将所有函数添加到这个结构体内

```c
static struct PyMethodDef methods[] = {
	{"gen_lst", (PyCFunction)_gen_lst, METH_VARARGS},
	{"gen_dct", (PyCFunction)_gen_dct, METH_VARARGS},
	{"show_name", (PyCFunction)_show_name, METH_VARARGS},
	{"prime_in_100", (PyCFunction)_prime_in_100, METH_VARARGS},
	{NULL, NULL, NULL}
};
```

4. 写一下模块的信息

```c
static struct PyModuleDef module = {
	PyModuleDef_HEAD_INIT,
	"cgy_ext",
	NULL,
	-1,
	methods
};

```
5. 生成模块
```c
PyMODINIT_FUNC PyInit_cgy_ext(void){
	return PyModule_Create(&module);
}
```

## 2. 编写setup.py文件
这里要写你的库的信息
详见setup.py

## 3. 编译
运行这个命令 `pip install .`

