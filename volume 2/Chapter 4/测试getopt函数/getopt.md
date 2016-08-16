#命令行参数解析函数——getopt
##函数声明如下：
	#include <unistd.h>
	
	int getopt(int argc, char * const argv[], const char * optstring);
	extern int optind, opterr, optopt;
	extern char *optarg;
	
##说明：
* argc：参数个数
* argv：参数字符串数组
* optstring：选项字母和“：”组成的字符串。字母后有一个“：”，表示该选项必须有参数；没有，表示不能带参数；若有两个，表示可带可不带。
* optind：argv数组的当前索引值
* optarg：当前选项的字符串参数
* opterr：当遇到无效选项或缺少参数选项时，该变量的值为零
* optopt：无效选项的字母，返回值为“？” 或“：”

每次使用*相同的参数*调用该函数，成功返回选项字母，否则返回-1。

##改变函数错误输出
1. 在调用getopt函数之前，设置opterr=0，不会输出任何错误信息
2. optstring的第一个字符是“：”，也不会输出任何错误信息。并根据错误情况返回不同字符：
* 无效选项：返回“？”
* 缺少参数：返回“：”， 否则会返回“？”

