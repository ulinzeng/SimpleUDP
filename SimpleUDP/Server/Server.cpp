// Server.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <WinSock2.h>
#include <Ws2ipdef.h>
#include <Ws2tcpip.h>

#include "SimpleUDP.h"
struct sockaddr;

#define BUFF_LENGTH 1024

int main()
{
    Net::InitNetwork();
    Net::SimpleUDP sock;

    sockaddr_in addrinfo{};
    addrinfo.sin_family = AF_INET;
    addrinfo.sin_port = htons(529);
    inet_pton(AF_INET, "127.0.0.1", &addrinfo.sin_addr);

    sock.Bind(reinterpret_cast<sockaddr*>(&addrinfo), sizeof(addrinfo));
    while (true)
    {
        char buff[BUFF_LENGTH] = {};
        int revLength = sock.ReceiveData(reinterpret_cast<uint8_t*>(buff), BUFF_LENGTH);
        if (revLength > 0)
        {
            std::cout << buff << std::endl;
        }
    }
    Net::CleanupNetwork();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
