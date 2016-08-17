#popen和pclose函数
##函数声明
```c
#include <stdio.h>

FILE* popen(const char *command, const char *type);
```
创建一个管道并启动另外一个进程。
* 成功返回文件指针，失败返回NULL
* command，shell命令
* type：r，调用进程读新进程的标准输出；w，调用进程写新进程的标准输入
```c
#include <stdio.h>

int pclose(FILE *stream);
```
* 成功返回shell种植状态，失败返回-1