/*ʮ���ƺ�����С��ת��Ϊ������*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char sign;
    char* integerPart;
    char* fractionPart;
} PointFixedNum;


//��ȡ���������Ϊ���ţ��������֣�С�����֣�
PointFixedNum parseDecimal(const char* input) {
    PointFixedNum result;
    result.sign = (input[0] == '-') ? '-' : '+';   //������ŵ�ASCIIֵ
    char* tempInput = _strdup(input);               //����input����
    char* dotPos = strchr(tempInput, '.');         //����.���ֵ�λ�ò����ص�ַ
    if (dotPos) {                                  
        *dotPos = '\0';                             //��.��λ\0���Ͽ�����
        result.integerPart = _strdup(tempInput + (result.sign == '-' ? 1 : 0));  //����Ǹ��ţ��ӵڶ�λ��ʼ���棬����\0ֹͣ
        result.fractionPart = _strdup(dotPos + 1);                                //��\0��һλ��ʼ��ֱ���ַ�����β�ġ�0
    }
    else {                //��û��С����ģʽ
        result.integerPart = _strdup(tempInput + (result.sign == '-' ? 1 : 0));
        result.fractionPart = NULL;
    }
    free(tempInput);
    return result;
}



// ���������ж�С���ַ������е������ַ��Ƿ�Ϊ'0'
int allZeros(char* fraction, int length)
{
    length = strlen(fraction);
    for (int i = 0; i < length; i++) {
        // �����һ���ַ�����'0'���򷵻� 0
        if (fraction != '0'||fraction!='.') {
            return 1;
        }
    }
    // �������������飬�����ַ�����'0'������ 1
    return 0;
}

char* translate_intpart(char* intger)
{
    int num;
    sscanf_s(intger, "%d", &num);   //��ʽ����������ַ���ת��Ϊ����
    static char res[100];
    int n = 0;
    while (num) {
        res[n++] = '0' + num % 2;
        num /= 2;
    }

    for (int i = 0; i < n / 2; i++) {   //��ת����
        char temp = res[i];
        res[i] = res[n - 1 - i];
        res[n - 1 - i] = temp;
    }
    return res;
}



//  ת��С������,����ǰ�油0��С����
char* convertString(const char* original) {
    int len = strlen(original);
    char* result = (char*)malloc(len * sizeof(char));
    result[0] = '0';
    result[1] = '.';
    strcpy_s(result + 2,sizeof(result), original);   //��ԭ����ǰ�油0��С���㸳��result���Ա��ں���sscanf��ʽ���������

    return result;
}

//С�����ָ�Ϊ������
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