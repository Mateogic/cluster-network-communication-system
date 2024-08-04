//(规定的消息体)消息内容/类型.. 通过数据序列化 为字符/字节流(json字符串) 发送到远端
// 该字符/字节流(json字符串) 又通过数据反序列化 得到(规定的消息体)消息内容/类型..
// json效率高于xml，低于protobuf 但是学习成本低
// 无序
#include "json.hpp"
using json = nlohmann::json; // namespace

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// 示例1
string func1()

{
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing now?";

    string sendBuf = js.dump(); // json数据对象->序列化 json字符串
    // cout << sendBuf.c_str() << endl;
    return sendBuf;
}

// 示例2
void func2()
{
    json js;
    // 添加数组
    js["id"] = {1, 2, 3, 4, 5};
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};
    cout << js << endl;
}

// 示例3直接序列化一个map容器
void func3()
{
    json js;
    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    js["list"] = vec;
    // 直接序列化一个map容器
    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});
    js["path"] = m;
    cout << js << endl;
}
int main()
{
    // // func2();
    // string recvBuf = func1();
    // 数据的反序列化 json字符串->反序列化成数据对象 （看作容器 方便访问）
    // json jsbuf = json::parse(recvBuf);
    // cout << jsbuf["msg_type"] << endl;
    // cout << jsbuf["from"] << endl;
    // cout << jsbuf["msg"] << endl;
    // cout << jsbuf["to"] << endl;

    return 0;
}