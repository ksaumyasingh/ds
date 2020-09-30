#include<stdio.h>
typedef struct date
{
	int day;
	int month;
	int year;
}Date;
Date date;
void setDate(Date d)
{
	date=d;
}
Date getDate(Date d)
{
	return d;
}
int getYear(Date d)
{
	return d.year;
}
int getDay(Date d)
{
	return d.day;
}
int getMonth(Date d)
{
	return d.month;
}
char getMonthName(Date d)
{
	switch(d.month)
	{
		case 1:
				return 'jan';
		case 2:
				return 'fab';
	}
}
int isCorrectMonth(int month)
{
	if(month<13&&month>0)
		return 1;
	return 0;
}
Date ad_Month(Date d,int month)
{
	int m;
	m=d.month+month;
	if(isCorrectMonth(m))
	{
		d.month=m;
		return d;
	}
	return d;
}




