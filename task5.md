# CS-MEDIUM-02
  

## part 1
 


### (1)经典现象0.1+0.2>0.3,为什么会出现这样的现象？
对于 0.1，十进制小数 0.1 转换为二进制的方法是不断乘以 2，取整数部分。具体过程如下：
0.1*2=0.2，整数部分为 0。  
0.2*2=0.4，整数部分为 0。  
0.4*2=0.8，整数部分为 0。  
0.8*2=1.6，整数部分为 1。  
0.6*2=1.2，整数部分为 1。  
0.2*2=0.4，整数部分为 0，此时又回到了步骤 2 的结果，开始循环。  
对于 0.2，同样的转换方法：  
0.2*2=0.4，整数部分为 0。  
0.4*2=0.8，整数部分为 0。 
0.8*2=1.6，整数部分为 1。  
0.6*2=1.2，整数部分为 1。  
0.2*2=0.4，整数部分为 0，也开始循环。  
所以，0.1 和 0.2 在计算机二进制中是无限循环小数。这是由于十进制小数的某些值在二进制表示中无法用有限位数精确表示。
所以如果0.1+0.2的输出结果用%0.10f表示就是不准确的0.3000000119
### (2)该如何获得精确值呢？
Java 中的 BigInteger 和 BigDecimal 类
BigInteger：  
用于表示任意大小的整数，没有大小限制，能处理超出基本数据类型范围的大整数运算。  
可以进行加、减、乘、除、取余等基本算术运算，也支持位运算、比较等操作。  
igDecimal   
用于表示任意精度的十进制数，可以避免浮点数运算中的精度损失问题。  
支持加、减、乘、除等算术运算，并且可以指定精度和舍入模式。  
Python 中的 Decimal 模块  
Decimal：  
Python 中的 decimal 模块提供了 Decimal 数据类型，用于进行高精度的十进制运算。  
可以精确地表示小数，并且可以控制精度、舍入方式等。  
C 语言中的 gmp.h 头文件  
gmp.h：  
gmp.h 是 GNU Multiple Precision Arithmetic Library（GMP）的头文件，用于进行高精度的整数和有理数运算。  
提供了丰富的函数来处理大整数、有理数等数据类型，可以进行加、减、乘、除、幂运算等。  
使用时需要先安装 GMP 库，然后在代码中包含 gmp.h 头文件。  

## part 2
### Step1 定点数的表示与存储
#### 以下代码仅仅能完成定点数的存储，提取符号，整数部分和小数部分
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>

    typedef struct {
    char sign;
    char* integerPart;
    char* fractionPart;
    } PointFixedNum;

    //提取输入的数据为符号，整数部分，小数部分，
    PointFixedNum parseDecimal(const char* input) {
        PointFixedNum result;
        result.sign = (input[0] == '-') ? '-' : '+';   //储存符号的ASCII值
        char* tempInput = _strdup(input);               //拷贝input的量
        char* dotPos = strchr(tempInput, '.');         //检索.出现的位置并返回地址
        if (dotPos) {                                  
            *dotPos = '\0';                             //将.换位\0，断开数据
             result.integerPart = _strdup(tempInput + (result.sign == '-' ? 1 : 0));  //如果是负号，从第二位开始储存，会在\0停止
            result.fractionPart = _strdup(dotPos + 1);                                //从\0后一位开始，直到字符串结尾的、0
    }
         else {                //即没有小数的模式
             result.integerPart = _strdup(tempInput + (result.sign == '-' ? 1 : 0));
            result.fractionPart = NULL;
    }
        free(tempInput);
        return result;
    }

    int main()
        {

        char input[500];
        
        char *fraction;
        printf("Enter a long decimal number: ");
        scanf_s("%s", input,500);
        PointFixedNum decimal = parseDecimal(input);
        fraction =convertString(decimal.fractionPart);
       
        printf("Sign: %c\nInteger part: %s\n", decimal.sign, decimal.integerPart);
        if (decimal.fractionPart) {
            printf("Fraction part: %s\n", decimal.fractionPart);
        }
        return 0;
    }
 #### 下面的代码可以完成十进制转化为二进制（我看错题了）的整数部分转化为二进制，小数部分我写的函数有问题失败了
 /*十进制含符号小数转化为二进制*/


    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>

    typedef struct {
        char sign;
        char* integerPart;
        char* fractionPart;
    } PointFixedNum;


    //提取输入的数据为符号，整数部分，小数部分，
    PointFixedNum parseDecimal(const char* input) {
        PointFixedNum result;
        result.sign = (input[0] == '-') ? '-' : '+';   //储存符号的ASCII值
        char* tempInput = _strdup(input);               //拷贝input的量
        char* dotPos = strchr(tempInput, '.');         //检索.出现的位置并返回地址
        if (dotPos) {                                  
        *dotPos = '\0';                             //将.换位\0，断开数据
        result.integerPart = _strdup(tempInput + (result.sign == '-' ? 1 : 0));  //如果是负号，从第二位开始储存，会在\0停止
        result.fractionPart = _strdup(dotPos + 1);                                //从\0后一位开始，直到字符串结尾的、0
        }
        else {                //即没有小数的模式
        result.integerPart = _strdup(tempInput + (result.sign == '-' ? 1 : 0));
        result.fractionPart = NULL;
        }
            free(tempInput);
            return result;
    }



    // 函数用于判断小数字符数组中的所有字符是否都为'0'
    int allZeros(char* fraction, int length)
    {
        length = strlen(fraction);
        for (int i = 0; i < length; i++) {
        // 如果有一个字符不是'0'，则返回 0
        if (fraction != '0'&& fraction!='.') {
            return 1;
        }
    }
        // 遍历完整个数组，所有字符都是'0'，返回 1
            return 0;
    }

    char* translate_intpart(char* intger)
    {
        int num;
        sscanf_s(intger, "%d", &num);   //格式化输出，将字符串转化为数字
        static char res[100];
        int n = 0;
        while (num) {
            res[n++] = '0' + num % 2;
            num /= 2;
    }

    for (int i = 0; i < n / 2; i++) {   //翻转数组
        char temp = res[i];
        res[i] = res[n - 1 - i];
        res[n - 1 - i] = temp;
    }
    return res;
    }



    //  转换小数部分,数字前面补0和小数点
    char* convertString(const char* original) {
        int len = strlen(original);
        char* result = (char*)malloc(len * sizeof(char));
        result[0] = '0';
        result[1] = '.';
    strcpy_s(result + 2,sizeof(result), original);   //将原数据前面补0和小数点赋给result，以便于后续sscanf格式化输出运算

    return result;
    }

    //小数部分改为二进制
    char* translate_fpart(char* fraction)
    {
    int num;
    sscanf_s(fraction, "%lf", &num);
    static char rest[32];
    int fractionIndex = 0;
        while (num > 0 && fractionIndex < 32) {
            num *= 2;
        if (num >= 1) {
            rest[fractionIndex++] = 1;
            num -= 1;
        }
        else {
            rest[fractionIndex++] = 0;
        }
    }

    return rest;
    }


    int main()
        {

        char input[500];
        
        char *fraction;
        printf("Enter a long decimal number: ");
        scanf_s("%s", input,500);
        PointFixedNum decimal = parseDecimal(input);
        fraction =convertString(decimal.fractionPart);
       
        printf("Sign: %c\nInteger part: %s\n", decimal.sign, decimal.integerPart);
        if (decimal.fractionPart) {
            printf("Fraction part: %s\n", decimal.fractionPart);
        }
        char* result_int = translate_intpart(decimal.integerPart);
        char* result_fraction = translate_fpart(fraction);
        printf("result=%c %s .%s", decimal.sign, result_int, result_fraction);

        
        return 0;
    }