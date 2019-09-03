//
// Created by xuqi on 2019-09-03.
//

#ifndef CSV_W_H
#define CSV_W_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <thread>
#include "Thread/semaphore.h"

using namespace std;
using namespace toolkit;

namespace io
{


template<unsigned column_count>
class CSVWriter
{
public:

    CSVWriter() = delete;
    CSVWriter(const CSVWriter &) = delete;
    CSVWriter &operator=(const CSVWriter &);

    explicit CSVWriter(string filename)
    :m_row(0)
    ,m_column(0)
    {
        //m_pThread = std::make_shared<thread>([this]() { this->run(); });

    }

    template<class ...ColNames>
    void write_header(ColNames...cols){
        static_assert(sizeof...(ColNames)>=column_count, "not enough column names specified");
        static_assert(sizeof...(ColNames)<=column_count, "too many column names specified");
        set_column_names(std::forward<ColNames>(cols)...);

    }

    template<class ...ColNames>
    void write_row(ColNames...cols){
        static_assert(sizeof...(ColNames)>=column_count, "not enough column names specified");
        static_assert(sizeof...(ColNames)<=column_count, "too many column names specified");
        fill_column(std::forward<ColNames>(cols)...);
    }

    template<typename T>
    CSVWriter& add(T &str){
        if (m_column > 0)
            m_context << ",";
        m_context << str;
        m_column++;
        return *this;
    }


    template<typename T>
    CSVWriter& add(T&& str){
        return this->add(string(str));
    }

    template<typename T>
    CSVWriter& operator<<(const T& t){
        return this->add(t);
    }
    string toString(){
        return m_context.str();
    }

private:
    void run() {};

    stringstream m_head;
    stringstream m_context;
    int m_row;
    int m_column;

    template<class ...ColNames>
    void set_column_names(std::string s, ColNames...cols)
    {
        m_head << std::move(s) << ",";
        set_column_names(std::forward<ColNames>(cols)...);
    }

    void set_column_names(){}

    template<class ...ColNames>
    void fill_column(std::string s, ColNames...cols)
    {
        m_context << std::move(s) << ",";
        fill_column(std::forward<ColNames>(cols)...);
    }
    void fill_column(){}

    bool m_bExitFlag;
    std::shared_ptr<thread> m_pThread;
    semaphore m_sem;
    mutex m_mutex;
};
}
#endif //CSV_W_H
