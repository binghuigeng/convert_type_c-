#include <iostream>    //std::cout
#include <string>      // std::string, std::to_string, std::stoi, std::stol, std::stof, std::stod
#include <sstream>     // std::ostringstream, std::istringstream

using namespace std;

//模板函数：将string类型变量转换为常用的数值类型（此方法具有普遍适用性）
template <class Type>
Type stringToNum(const string& str)
{
    //采用sstream头文件中定义的字符串流对象来实现转换
    istringstream iss(str);  //构造输入字符串流，流的内容初始化为“str”的字符串
    Type num;
    iss >> num;    //从is流中读入一个int整数存入i中
    return num;
}

//C++中把string类型转换为int、long、float、double类型
int FromString();

//C++中把int、float、double类型转换为string类型
std::string ToString();

int main()
{
    cout << "Hello World!" << endl;

    //模板函数：将string类型变量转换为常用的数值类型（此方法具有普遍适用性）
    std::string str("12345.678935");
    cout << stringToNum<double>(str) << endl;

    //C++中把string类型转换为int、long、float、double类型
    FromString();

    //C++中把int、float、double类型转换为string类型
    std::string sim = ToString();
    printf("sim: %s\n", sim.c_str());

    return 0;
}

//C++中把string类型转换为int、long、float、double类型
int FromString()
{
    // 法一  采用sstream头文件中定义的字符串流对象来实现转换
    std::istringstream iss("12"); //构造输入字符串流，流的内容初始化为“12”的字符串
    int a;
    iss >> a; //从iss流中读入一个int整数存入i中

    // 法二  c++11标准
    std::string str = "12312";
    int a1 = stoi(str);     // string类型转换int类型

    std::string str2 = "12313";
    long b2 = stol(str2);     // string类型转换long类型

    std::string str3 = "12314.78";
    float c3 = stof(str3);     // string类型转换float类型

    std::string str4 = "12315.123456";
    double d4 = stod(str4);     // string类型转换double类型

    // 法三  采用标准库中atoi函数,对于其他类型也都有相应的标准库函数，比如浮点型atof(),long型atol()等等
    std::string s = "17";
    int k = atoi(s.c_str());

    cout << a1 << b2 << c3 << d4 << k << endl;

    return a;
}

//C++中把int、float、double类型转换为string类型
std::string ToString()
{
    int a1 = 9000;
    float b2 = 8000.12;
    double c3 = 7000.456789;

    // 法一  采用sstream中定义的字符串流对象来实现
    std::ostringstream oss;    //构造一个输出字符串流，流内容为空
    oss << a1 << b2 << c3;    //向输出字符串流中输出int整数a1的内容
    cout << oss.str() << endl;    //利用字符串流的str函数获取流中的内容
    printf("data: %s\n", oss.str().c_str());

    // 法二  c++11标准增加了全局函数std::to_string
    /***************************************************************
     * 使用这种方法要注意，需要添加对C++11 的支持
     * 如果使用的是CMake，在CMakeLists.txt中加上
     *     add_compile_options(-std=c++11)
     * 如果使用的是qmake，需要添加上
     *     QMAKE_CXXFLAGS += -std=c++11
     * ************************************************************/
    std::string data = std::to_string(a1);
    cout << data << std::to_string(b2) << std::to_string(c3) << endl;
    printf("data: %s %s %s\n", data.c_str(), std::to_string(b2).c_str(), std::to_string(c3).c_str());

    return oss.str();
}
