# Linux编程作业

## `p38 t6` 

​	査看你的系统的头文件 limits. h。系统相关的静态限制值有哪些?它们的值各为多少?特别地,整数类型、浮点类型和双精度类型的最大、最小值各为多少?

### 头文件位置

```Console
 /usr/lib/gcc/x86_64-linux-gnu/7/include
 /usr/local/include
 /usr/lib/gcc/x86_64-linux-gnu/7/include-fixed
 /usr/include/x86_64-linux-gnu
 /usr/include
```

```C
	_LIBC_LIMITS_H_	1
	MB_LEN_MAX	16
	_LIMITS_H	1
	CHAR_BIT	8
    SCHAR_MIN	(-128)
	SCHAR_MAX	127
    UCHAR_MAX	255

/* Minimum and maximum values a `signed short int' can hold.  */
#  define SHRT_MIN	(-32768)
#  define SHRT_MAX	32767
        
/* Maximum value an `unsigned short int' can hold.  (Minimum is 0.)  */
#  define USHRT_MAX	65535
    
/* Minimum and maximum values a `signed int' can hold.  */
#  define INT_MIN	(-INT_MAX - 1)
#  define INT_MAX	2147483647

/* Maximum value an `unsigned int' can hold.  (Minimum is 0.)  */
#  define UINT_MAX	4294967295U
        
/* Minimum and maximum values a `signed long int' can hold.  */
#  if __WORDSIZE == 64
#   define LONG_MAX	9223372036854775807L
#  else
#   define LONG_MAX	2147483647L
#  endif
#  define LONG_MIN	(-LONG_MAX - 1L)

/* Maximum value an `unsigned long int' can hold.  (Minimum is 0.)  */
#  if __WORDSIZE == 64
#   define ULONG_MAX	18446744073709551615UL
#  else
#   define ULONG_MAX	4294967295UL
#  endif	        
        
/* Number of decimal digits, q, such that any floating-point number with q
   decimal digits can be rounded into a floating-point number with p radix b
   digits and back again without change to the q decimal digits,

	p * log10(b)			if b is a power of 10
	floor((p - 1) * log10(b))	otherwise
*/
```

## `p66 t7`

​	为什么说gets()是危险的函数？

```c
char * gets(char *s);
```

​	`gets()`不要求提供字符串s的空间大小,这导致 gets成了危险的函数:它没有为字符串s的溢出提供保护!当要读入的行长度超过字符串s所能容纳的大小时,超出的部分将越过s提供的空间而覆盖其他的数据或程序。因此最好不要使用 `gets()`。

##  `p66 t10`

​	设某个文件含n个记录,文件的第一个字(4字节)给出记录的总个数n,随后的n个字给出各个记录的长度(字节数),剩余部分则由各个记录组成。编写一个根据文件指针和记录编号(从1开始编号)读取第k个记录的函数。

```c
char * m_read(const char *pathname,int k)
{    
    int size.i;
    long int position,n;
    char *buffer;
    FILE *stream = fopen(pathname,"r");  
    fgets(n,5,stream);//读总个数n
    for(i=k,position=4+n;i>1;i--)
    {
       position+=getc(stream) ;
    }
    size=getc(stream);
    buffer=(char *)malloc(size+1);  
    fseek(stream,position,SEEK_SET);
    fgets(buffer,size,stream);
    reutrn buffer;
}
```





