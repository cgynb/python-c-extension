#include <Python.h>

long long c_fib(int num){
    if(num == 1 || num == 2){
        return 1;
    }else{
        return c_fib(num-1) + c_fib(num-2);
    }
}
static PyObject* _gen_lst(PyObject* self){
//	printf("gen lst func run\n");
	PyObject* lst = PyList_New(0);
	PyList_Append(lst, PyUnicode_FromString("cgy"));
	return lst;
}

static PyObject* _gen_dct(PyObject* self){
//	printf("gen dct func run\n");
	long long age = 19;
	PyObject* dct = PyDict_New();
	PyDict_SetItemString(dct, "name", PyUnicode_FromString("cgy"));
	PyDict_SetItemString(dct, "age", PyLong_FromLong(age));
	return dct;
}

static PyObject* _show_name(PyObject* self, PyObject* args){
//	printf("show name func run\n");
	char* name = NULL;
    if (!PyArg_ParseTuple(args, "s", &name)) {
		printf("args error\n");
		exit(1);
    }
    return PyUnicode_FromString(name);
}

static PyObject* _prime_in_100(PyObject* self){
//	printf("prime num in 100 lst\n");
	PyObject* prime_lst = PyList_New(0);
	for(long i=1; i<=100; i++){
		if(isPrime(i)){
			PyList_Append(prime_lst, PyLong_FromLong(i));
		}
	}
	return prime_lst;
}

static PyObject* _is_prime(PyObject* self, PyObject* args){
//	printf("run\n");
	char num = 0;
    if (!PyArg_ParseTuple(args, "i", &num)) {
        printf("args error\n");
        exit(1);
    }
    if(isPrime(num)){
        Py_RETURN_TRUE;
    }else{
        Py_RETURN_FALSE;
    }
}

static PyObject* _fib(PyObject* self, PyObject* args){
    int num;
    if (!PyArg_ParseTuple(args, "i", &num)) {
        printf("args error\n");
        exit(1);
    }
    return PyLong_FromLong(c_fib(num));
}


int isPrime(int num){
    if(num <= 1){
        return 0;
    }
    for(int i=2; i<= sqrt(num); i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}


static struct PyMethodDef methods[] = {
	{"gen_lst", (PyCFunction)_gen_lst, METH_VARARGS},
	{"gen_dct", (PyCFunction)_gen_dct, METH_VARARGS},
	{"show_name", (PyCFunction)_show_name, METH_VARARGS},
	{"is_prime", (PyCFunction)_is_prime, METH_VARARGS},
	{"prime_in_100", (PyCFunction)_prime_in_100, METH_VARARGS},
	{"fib", (PyCFunction)_fib, METH_VARARGS},
	{NULL, NULL, NULL}
};

static struct PyModuleDef module = {
	PyModuleDef_HEAD_INIT,
	"cgy_ext",
	NULL,
	-1,
	methods
};

PyMODINIT_FUNC PyInit_cgy_ext(void){
	return PyModule_Create(&module);
}


