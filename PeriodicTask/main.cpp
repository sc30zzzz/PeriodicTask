// main.cpp
#include "include/Utilities/PeriodicTask.h"
#include <iostream>
#include <unistd.h>

// 定义一个简单的函数，作为定时任务要执行的操作
void myFunction() {
    std::cout << "This is a periodic task running!" << std::endl;
}

int main() {
    // 创建一个任务管理器
    PeriodicTaskManager taskManager;

    // 创建一个周期性任务，每 2 秒执行一次
    PeriodicFunction periodicTask(&taskManager, 2.0f, "MyPeriodicTask", myFunction);

    // 启动任务
    periodicTask.start();
    return 0;
}
