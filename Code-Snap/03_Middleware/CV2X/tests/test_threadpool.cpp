//
// Created by xuqi on 2019-08-05.
//
#include "../inc/V2xThreadPool.h"
#include "../inc/V2xThread.h"
#include "Util/ResourcePool.h"
#include "../inc/V2xMsg.h"

using namespace std;
using namespace toolkit;
using namespace v2x;

namespace v2x {

class Consumer : public V2xThreadPool{
public:
    void Run(int num) override
    {
        if(msg_queue == nullptr)
        {
            ErrorL << "msg queue not set"<<endl;
            return;
        }

        V2xMsg::ValuePtr msg;

        // 如果队列为空，则等待
        while(msg_queue->pop(msg))
        {
            InfoL << "我是消费者:" << num << ": 我拿到了商品，商品内容是:"<< *msg << "商品地址" << msg;
            usleep(100*num);
            // 不再使用，放回资源池
            msg.reset();
        }
    }
    Consumer(int threadnum)
        : V2xThreadPool(threadnum)
    {

    }

    void setMsgQueue(const V2xMsg::Queue::Ptr &msgQueue)
    {
        msg_queue = msgQueue;
    }
private:
    // 消息队列的指针
    V2xMsg::Queue::Ptr msg_queue;
};


class Producer : public V2xThread {
public:
    void Run() override
    {

        if(msg_queue == nullptr)
        {
            ErrorL << "msg queue not set"<<endl;
            return;
        }

        // 设置一个资源池，最多回收10个V2xMsg的内存
        ResourcePool<V2xMsg> r_pool;
        r_pool.setSize(2);

        for (int i =0; i < 2000; i++)
        {
            // 从资源池中获取一个对象的指针,并赋值不同的值
            V2xMsg::ValuePtr msg = r_pool.obtain();
            string text = StrPrinter <<"我是商品"<< i  << endl;
            msg->assign(text);

            // 把偶数放入队列
            if (i %2 == 0)
            {
                // 把对象放入队列
                msg_queue->push(msg);
            }
            else
            {
                InfoL << "不是偶数，放回资源池"<< msg<<endl;
                // 手动释放msg，把msg 放回RecycleResourcePool
                msg.reset();
            }
            usleep(100);
        }

    }

    void setMsgQueue(const V2xMsg::Queue::Ptr &msgQueue)
    {
        msg_queue = msgQueue;
    }
private:
    // 消息队列的指针
    V2xMsg::Queue::Ptr msg_queue;

};
};

int main()
{
    // Log串口输出
    Logger::Instance().add(make_shared<ConsoleChannel>());
    // Log 等级为Trace
    Logger::Instance().setLevel(LTrace);

    // 定义V2xMsg类型的消息队列,并且new出一个消息队列
    V2xMsg::Queue::Ptr msg_queue = make_shared<V2xMsg::Queue>();

    // 使用V2xThread线程创建生产者/
    std::shared_ptr<Producer> producer = make_shared<Producer>();
    producer->setMsgQueue(msg_queue);

    // 创建10个消费者
    std::shared_ptr<Consumer> consumers = make_shared<Consumer>(10);
    consumers->setMsgQueue(msg_queue);

    //消费者们先启动
    consumers->Start();

    sleep(1);

    //生产者启动
    producer->Start();

    while (1)
    {
        sleep(100);
    }
    return 0;
}