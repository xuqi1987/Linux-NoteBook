//
// Created by root on 19-8-30.
//
#include "Http/HttpRequester.h"
#include <signal.h>
using namespace toolkit;


int main()
{
    //设置退出信号处理函数
    static semaphore sem;
    signal(SIGINT, [](int) { sem.post(); });// 设置退出信号
    //设置日志
    Logger::Instance().add(std::make_shared<ConsoleChannel>());
    Logger::Instance().setLevel(LDebug);

    string url = StrPrinter << "http://47.100.237.250:8003/api";
    ///////////////////////////////http post///////////////////////
    //创建一个Http请求器
    HttpRequester::Ptr requesterPost(new HttpRequester());
    //使用POST方式请求
    requesterPost->setMethod("POST");
    //设置http请求头
    requesterPost->addHeader("X-Requested-With", "XMLHttpRequest");
    requesterPost->addHeader("Origin", url);
    //设置POST参数列表
    HttpArgs args;
    args["hv"] = "test";
    args["rv"] = "en";
    args["warning"] = "zh";
    requesterPost->setBody(args.make());
    //开启请求
    requesterPost->startRequester(url,//url地址
                                  [](const SockException &ex,                          //网络相关的失败信息，如果为空就代表成功
                                     const string &status,                             //http回复的状态码，比如说200/404
                                     const HttpClient::HttpHeader &header,             //http回复头
                                     const string &strRecvBody) {                       //http回复body
                                      DebugL << "=====================HttpRequester POST==========================";
                                      if (ex) {
                                          //网络相关的错误
                                          WarnL << "network err:" << ex.getErrCode() << " " << ex.what();
                                      } else {
                                          //打印http回复信息
                                          _StrPrinter printer;
                                          for (auto &pr: header) {
                                              printer << pr.first << ":" << pr.second << "\r\n";
                                          }
                                          InfoL << "status:" << status << "\r\n"
                                                << "header:\r\n" << (printer << endl)
                                                << "\r\nbody:" << strRecvBody;
                                      }
                                  });

    sem.wait();
    return 0;
}