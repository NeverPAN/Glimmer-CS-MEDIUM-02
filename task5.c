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
        if (fraction != '0'||fraction!='.') {
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