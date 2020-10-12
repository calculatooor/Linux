# 第三周

## 第二章 标准输入输出

#### 第一节

进程的运行=计算任务（指令）+I/O任务（资源）

​						cpu		+内存		+外设

​										映射（地址）

进程相互独立 4G地址空间 

进程间通信三种方式：OS内核转发（ns）+共享内存（ns）+共享文件（ms）

基于文件描述符（int fd;）：creat open read() write()

基于流（FILE*pt;）：fopen fread fwrite fclose

封装 {cout cin [文件流(文件描述符)]}

#### 第二节

函数`fwrite()` 的用法

```c
size_t fwrite(const void* ptr ,size_t size,size_t numb,FILE*stream);
//成功写入的项数                  每项长度     项目数			
fopen("./ftest.txt","w");
//                   w 以覆盖形式写
```

文件操作：

1. 由OS提供的基于文件描述符，更为底层。 Windows不支持
2. 由标准函数库提供，基于FILE流`int _fileno;`，`API`

## 环境

`gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0`

`GNU gdb (Ubuntu 8.1-0ubuntu3.2) 8.1.0.20180409-git`







