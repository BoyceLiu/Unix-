#popen��pclose����
##��������
```c
#include <stdio.h>

FILE* popen(const char *command, const char *type);
```
����һ���ܵ�����������һ�����̡�
* �ɹ������ļ�ָ�룬ʧ�ܷ���NULL
* command��shell����
* type��r�����ý��̶��½��̵ı�׼�����w�����ý���д�½��̵ı�׼����
```c
#include <stdio.h>

int pclose(FILE *stream);
```
* �ɹ�����shell��ֲ״̬��ʧ�ܷ���-1