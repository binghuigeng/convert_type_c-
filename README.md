# convert_type_c++
关于c++数据类型的相互转换，有些方法需要c++11支持。

## 使用这种方法要注意，需要添加对C++11 的支持
1. 如果使用的是CMake，在CMakeLists.txt中加上add_compile_options(-std=c++11)。
2. 如果使用的是qmake，需要添加上，QMAKE_CXXFLAGS += -std=c++11。

# 删除空文件夹（文件）
1. rmdir directoryname

# 删除非空文件夹（文件）
1. rm -rf directoryname
