#include <iostream>
#include <string>
#include <unistd.h>
#include <Python.h>
#include  <pythonrun.h>

using namespace std;
string getPyAddr()
{
    cout << "Hello World" << endl;
    char path[1024];
    getcwd(path, sizeof(path));
    string path1 = path;
    cout << path1 << endl;
    string key = "cmake-build-debug";
    int start = path1.find(key);
    string path2 = path1.substr(0, start);
    cout << path2 << endl;
    return path2;
}

int main(){
    Py_Initialize();
    string path = getPyAddr();
    PyObject* main_module = PyImport_ImportModule("__main__");
    //这一步的作用：将python的sys.path添加到环境变量中


}