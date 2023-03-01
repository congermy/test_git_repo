#include <iostream>
#include <string>
#include <unistd.h>
#include <Python.h>
#include <pythonrun.h>
using namespace std;

int main() {
    string string1 = "Yes";
    //Calling Python Function
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    PyObject *pModule = PyImport_ImportModule("func");
    PyObject *pFunc = PyObject_GetAttrString(pModule, "function");
    //PyObject *pName = PyBytes_FromString(string1.c_str());
    //如果Python函数有返回值，可以用PyArg_ParseTuple来获取返回值
    PyObject *pRet;
    //pRet = PyObject_CallFunction(pFunc, "s", pName);
    pRet = PyObject_CallFunction(pFunc, "s", (char *)string1.c_str());
    //format: sO代表传入的参数是一个字符串和一个对象。此外，还有i代表整型，f代表浮点型，O代表对象等等。

    char *pStr = NULL;
    PyArg_Parse(pRet, "s", &pStr);
    cout << pStr << endl;
    Py_Finalize();

    return 0;
}