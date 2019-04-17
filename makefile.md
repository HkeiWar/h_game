vpath %.h /lib/SDL/include/SDL2  搜索文件路径
test = ${wildcard ${src_dir}/*.c} 获取${src_dir}目录下的所有.c文件赋值到test  wildcard函数
test1 = ${test:%.c=%.o} 把test里的所有.c替换成.o 
1、makefile里的函数

makefile里的函数使用，和取变量的值类似，是以一个‘$’开始，然后是一个括号里面是函数名和需要的参数列表，多个变量用逗号隔开，像这样

return = $(functionname  arg1,arg2,arg3...)。

可能这里的'$'更像是从某个地址取值类似的操作。

 

2、 wildcard

使用：SRC = $(wildcard *.c ./foo/*.c) 

搜索当前目录及./foo/下所有以.c结尾的文件，生成一个以空格间隔的文件名列表，并赋值给SRC.当前目录文件只有文件名，子目录下的文件名包含路径信息，比如./foor/bar.c。

 

3、notdir

使用：SRC = $(notdir wildcard)

去除所有的目录信息，SRC里的文件名列表将只有文件名。

 

4、patsubst

使用：OBJ = $(patsubst %.c %.o $(SRC)) 

patsubst是patten substitude的缩写，匹配替代的意思。这句是在SRC中找到所有.c 结尾的文件，然后把所有的.c换成.o。

$@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件。