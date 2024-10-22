# CS-MEDIUM-02
  

## part 1
 


### (1)��������0.1+0.2>0.3,Ϊʲô���������������
���� 0.1��ʮ����С�� 0.1 ת��Ϊ�����Ƶķ����ǲ��ϳ��� 2��ȡ�������֡�����������£�
0.1*2=0.2����������Ϊ 0��  
0.2*2=0.4����������Ϊ 0��  
0.4*2=0.8����������Ϊ 0��  
0.8*2=1.6����������Ϊ 1��  
0.6*2=1.2����������Ϊ 1��  
0.2*2=0.4����������Ϊ 0����ʱ�ֻص��˲��� 2 �Ľ������ʼѭ����  
���� 0.2��ͬ����ת��������  
0.2*2=0.4����������Ϊ 0��  
0.4*2=0.8����������Ϊ 0�� 
0.8*2=1.6����������Ϊ 1��  
0.6*2=1.2����������Ϊ 1��  
0.2*2=0.4����������Ϊ 0��Ҳ��ʼѭ����  
���ԣ�0.1 �� 0.2 �ڼ������������������ѭ��С������������ʮ����С����ĳЩֵ�ڶ����Ʊ�ʾ���޷�������λ����ȷ��ʾ��
�������0.1+0.2����������%0.10f��ʾ���ǲ�׼ȷ��0.3000000119
### (2)����λ�þ�ȷֵ�أ�
Java �е� BigInteger �� BigDecimal ��
BigInteger��  
���ڱ�ʾ�����С��������û�д�С���ƣ��ܴ����������������ͷ�Χ�Ĵ��������㡣  
���Խ��мӡ������ˡ�����ȡ��Ȼ����������㣬Ҳ֧��λ���㡢�ȽϵȲ�����  
igDecimal   
���ڱ�ʾ���⾫�ȵ�ʮ�����������Ա��⸡���������еľ�����ʧ���⡣  
֧�ּӡ������ˡ������������㣬���ҿ���ָ�����Ⱥ�����ģʽ��  
Python �е� Decimal ģ��  
Decimal��  
Python �е� decimal ģ���ṩ�� Decimal �������ͣ����ڽ��и߾��ȵ�ʮ�������㡣  
���Ծ�ȷ�ر�ʾС�������ҿ��Կ��ƾ��ȡ����뷽ʽ�ȡ�  
C �����е� gmp.h ͷ�ļ�  
gmp.h��  
gmp.h �� GNU Multiple Precision Arithmetic Library��GMP����ͷ�ļ������ڽ��и߾��ȵ����������������㡣  
�ṩ�˷ḻ�ĺ�������������������������������ͣ����Խ��мӡ������ˡ�����������ȡ�  
ʹ��ʱ��Ҫ�Ȱ�װ GMP �⣬Ȼ���ڴ����а��� gmp.h ͷ�ļ���  


#### �������е���λ����  
���ƣ�<<����  
��һ���������������ƶ�ָ����λ��������Ƴ���λ���������ұ��� 0 ��䡣  
���磬������ 5��������Ϊ 00000101������ 2 λ�����Ϊ 20��������Ϊ 00010100����  
�� C �����п���ʹ�� << ������������Ʋ�����  
����һλ�൱�ڳ��� 2������ n λ�൱�ڳ��� 2 �� n �η���  
  
���ƣ�>>����  
��һ���������������ƶ�ָ����λ�����ұ��Ƴ���λ��������������޷������������ 0 ��䣨�߼����ƣ���������з����������ݷ���λ������䣬������ 0 ��䣬������ 1 ��䡣���������ƣ�  
���磬������ -5��������Ϊ 11111011������ 2 λ�����Ϊ -2��������Ϊ 11111110������-5/2=-3/2=-2������ȡ������   
�� C �����п���ʹ�� >> ������������Ʋ�����  
����һλ�൱�ڳ��� 2��ȡ�������֣����� n λ�൱�ڳ��� 2 �� n �η���ȡ�������֡�   



#### �����߾��ȣ�
��ʵ��Ӧ���У����Բ������·��������ٸ����������������  
ʹ�ø��߾��ȵ��������ͣ��� double ���ͣ���ռ�� 64 λ�洢�ռ䣬�����ṩ���ߵľ��ȡ�  
����ֱ�ӱȽ������������Ƿ���ȣ�����ʹ��һ����С����Χ���ж������Ƿ�ӽ������磬�ж�����������֮��ľ���ֵ�Ƿ�С��һ����С������  
��һЩ�Ծ���Ҫ��ǳ��ߵĳ��ϣ�����ʹ�ö������������������������㡣���������Ծ�ȷ��ʾС���������㷶Χ���ޣ������������ͨ�����Ӻͷ�ĸ����ʾ���������ܹ����о�ȷ�����㣬������Ч����Խϵ͡�  



## part 2
### Step1 �������ı�ʾ��洢
#### ���´����������ɶ������Ĵ洢����ȡ���ţ��������ֺ�С������
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
 #### ����Ĵ���������ʮ����ת��Ϊ�����ƣ��ҿ������ˣ�����������ת��Ϊ�����ƣ�С��������д�ĺ���������ʧ����
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
        if (fraction != '0'&& fraction!='.') {
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