#include <Python.h>

#include "vcrypt.h"

static PyObject *vcrypt_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    vcrypt_1_1_256((char *)PyBytes_AsString((PyObject*) input), output, 1024); //TODO: change to N argument
#else
    vcrypt_1_1_256((char *)PyString_AsString((PyObject*) input), output, 1024); //TODO: change to N argument
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef vCryptMethods[] = {
    { "getPoWHash", vcrypt_getpowhash, METH_VARARGS, "Returns the proof of work hash using vCrypt" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef vCryptModule = {
    PyModuleDef_HEAD_INIT,
    "vdn_vcrypt",
    "...",
    -1,
    ScryptMethods
};

PyMODINIT_FUNC PyInit_vdn_vcrypt(void) {
    return PyModule_Create(&vCryptModule);
}

#else

PyMODINIT_FUNC initvdn_vcrypt(void) {
    (void) Py_InitModule("vdn_vcrypt", vCryptMethods);
}
#endif
