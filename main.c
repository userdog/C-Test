#include<stdio.h>

//定义日期结构体
typedef struct
{
    int year;
    int month;
    int day;
}DATE;

//判断某一年是否为闰年
int Judge_Year(int year)
{
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return 1;
    else
        return 0;

}

//计算指定日期距离1990年1月1日的总天数
int Count_TotalDay(DATE currentDate)
{
    //定义一个每月天数的数组，其中二月默认平年28天
    int perMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int totalDay = 0;
    int year = 0, month = 0, day = 0;

    //求出指定日期前一年到1990年1月1日的总天数
    for (year = 1990; year < currentDate.year; year++)
    {
        if(Judge_Year(year))
            totalDay += 366;
        else
            totalDay += 365;
    }

    //如果指定年份为闰年，则二月为29天
    if(Judge_Year(currentDate.year))
    {
        perMonth[2] = 29;
    }

    //将指定日期月份之前所有月天数累计到totalDay中
    for (month = 0; month < currentDate.month; month++)
    {
        totalDay += perMonth[month]; 
    }

    //将指定日期本月内天数累计到totalDay中
    totalDay += currentDate.day;
    
    return totalDay;
}

int main(void)
{  
    DATE today;          //指定日期
    int totalDay = 0;   //指定日期到1990年1月1日总天数
    int result = 0;    //总天数totalDay对5求余结果

    printf("请输入指定日期,包括年,月,日,例如: 1990 1 30\n");
    printf("请输入->\n");

    scanf("%d %d %d",&today.year,&today.month,&today.day); 
    
    totalDay = Count_TotalDay(today);
    result = totalDay % 5;

    if(result > 0 && result < 4)
        printf("今天打鱼\n");
    else
        printf("今天晒网\n");

    return 0;
}