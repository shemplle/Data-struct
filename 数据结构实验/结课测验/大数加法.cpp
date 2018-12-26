#include<stdio.h>
#include<string.h>

#define MAX 1000    // ���������λ�� 

 
/*
  �����ӷ� 
  ������ 
  num1Ϊ��һ�����������ַ����鱣��
  num2Ϊ�ڶ�������
  sum���鱣����ӵĽ��  ����num1+num2=sum
  ����ֵ����������sum����Ч���ȣ�����������λ�� 
 */
int Addition(char num1[], char num2[], int sum[])
{
    int i, j, len;
    int n2[MAX] = {0};
    int len1 = strlen (num1); // ��������num1�ĳ��ȣ���������λ�� 
    int len2 = strlen (num2); // ��������num2�ĳ��ȣ���������λ�� 

    len = len1>len2 ? len1 : len2; // ��ȡ�ϴ��λ��
    //��num1�ַ�����������ַ�ת��Ϊ�������֣������򱣴�����������sum�У�����λ��ǰ����λ�ں�
    for (i = len1-1, j = 0; i >= 0; i--, j++) 
        sum[j] = num1[i] - '0';
    // ת���ڶ����� 
    for (i = len2-1, j = 0; i >= 0; i--, j++)
        n2[j] = num2[i] - '0';
    // ������������� 
    for (i = 0; i <= len; i++)
    {
        sum[i] += n2[i];  // �������ӵ�λ��ʼ��� 
        if (sum[i] > 9)   // �ж��Ƿ��н�λ 
        {   // ��λ 
            sum[i] -= 10;
            sum[i+1]++;
        }
    }
    if(sum[len] != 0)  // �ж����λ�Ƿ��н�λ 
        len++;
    return len;   // ���غ͵�λ�� 
}

int main()
{
    int i, len;
    int sum[MAX] = {0}; // ��ż���Ľ������λ��ǰ����λ�ں󣬼�sum[0]�ǵ�λ 
    char num1[MAX] ,num2[MAX] ;
	scanf("%s %s",num1 ,num2) ; 
    len = Addition(num1, num2, sum);    // ������� 
    printf("%s\n  +\n%s\n  =\n", num1, num2);
    // ���������ͽ��
    for (i = len-1; i >= 0; i--)
        printf("%d", sum[i]);
    printf("\n"); 
    return 0;
}
