# 第八周

## 第5章 进程控制

| 高地址         |              |
| -------------- | ------------ |
| 栈             |              |
|                |              |
| 堆             |              |
| 未初始化数据段 |              |
| 初始化数据段   | 全局变量存储 |
| 正文段         |              |

1. goto label 函数内的跳转

2. `setjmp longjmp`实现函数间的跳转

`static jmp_buf g_stack_env;`

`jmp_buf`保存跳转前的函数状态 寄存器 全局【局部？】

`setjmp(g_stack_env)`设置断点 跳转前0 跳转回来1

如果优化`gcc 8-4.c -o 8-4 `	`./8-4.u -O2`修改的变化未保存

进程 PCB(`PID`可见 其余不可见)

进程	派生 fork `vfork` clone(线程 可共享资源的进程)

```console
cat /proc/1/
ps -ef
cat /proc/sys/kernel/sched_child_runs_first
```

fork 返回两个值 给父进程 大于0值 给子进程0值

### 1.进程标识

​	PID的值在0~MAXPID-1之间，系统在创建进程时从一个循环递增的计数器中获取新的PID值,如果已经存在与该计数器值相同的进程,则简单地递增计数器直到有一个自由PID为止。

​	表示PID的类型是`pid_t`，它是有符号整数类型。

​	函数`getpid()`可获得进程的PID，`getppid()`可获得父进程的PID。

```c
#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void);
pid_t getppid(void);
```

### 2.进程创建

应用进程创建进程的唯一方法是通过现有的进程调用`fork()`函数。

```c
#include <sys/types.h>
#include <unistd.h>

pid_t fork(void);
```

若`fork()`调用成功,父进程和子进程同时存在,且子进程几乎完全是对父进程的复制。子进程有自己的存储空间(包括堆和栈空间),并且其中的内容与父进程的内容完全相同。子进程也执行与父进程完全相同的程序,父子进程共享此程序的代码段。

`fork()`父、子进程分别以不同的返回值从`fork()`返回:	子进程返回0，父进程返回子进程的PID。