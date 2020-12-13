#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date
{
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;

};
typedef struct Date Date;

Date *makeDate(int day, int month, int year, int hour, int minute, int second)
{
    Date *date=(Date *) malloc(sizeof(Date));
    date->day=day;
    date->month=month;
    date->year=year;
    date->hour=hour;
    date->minute=minute;
    date->second=second;

    return date;

}



struct Event
{
    Date *start;
    Date *end;
};
typedef struct Event Event;

Event *makeEvent(Date *start, Date *end)
{
    Event *event= (Event *) malloc(sizeof(Event));
    event->start=start;
    event->end=end;

    return event;
}

struct Calendar
{
    Event **events;
    size_t count;
};
typedef struct Calendar Calendar;

Calendar *cal;


Calendar *makeCalendar()
{
    Calendar *calendar= (Calendar *) malloc(sizeof(Calendar));
    calendar->events=NULL;
    calendar->count=0;

    return calendar;
}

size_t addCalendar(Event *e, Calendar *c)
{
    if(c->count==0 && c->events==NULL)
    {
        c->events=(Event **) malloc(sizeof(Event **));
        c->events[0]=(Event *) malloc(sizeof(Event *));
        c->events[0]=e;
        c->count++;
    }

    else
    {
        c->events[c->count]=(Event *) malloc(sizeof(Event *));
        c->events[c->count]=e;
        c->count++;
    }

    return c->count;
}

int compareDate(Calendar *c, int day1, int month1, int year1, int hour1, int minute1, int second1, int day2, int month2, int year2, int hour2, int minute2, int second2)
{
    int check;
    if ((year1 <= 9999 && year1 >= 0) && (year2 <= 9999 && year2 >= 0) && (month1 > 0 && month1 <= 12) &&
        (month2 <= 12 &&
         month2 > 0) && (day1 > 0 && day1 <= 31) && (day2 > 0 && day2 <= 31) && (hour1 >= 0 && hour1 < 24) &&
        (hour2 >= 0 &&
         hour2 < 24) && (minute1 >= 0 && minute1 < 60) && (minute2 >= 0 && minute2 < 60) && (second1 >= 0 &&
                                                                                             second1 < 60) &&
        (second2 >= 0 && second2 < 60))
    {
        if ((year2 > year1) || (year2 == year1 && month2 > month1) ||
            (year2 == year1 && month1 == month2 && day2 > day1) ||
            (year2 == year1 && month1 == month2 && day2 == day1 && hour2 > hour1) ||
            (year2 == year1 && month1 == month2 && day2 == day1 && hour2 == hour1 && minute2 > minute1) ||
            (year2 == year1 && month1 == month2 && day2 == day1 && hour2 == hour1 && minute2 == minute1 &&
             second2 > second1))
        {
            for(size_t i=0; i<c->count; i++)
            {
                if(((c->events[i]->start->year > year1) || (c->events[i]->start->year == year1 && c->events[i]->start->month > month1) ||
                    (c->events[i]->start->year == year1 && month1 == c->events[i]->start->month && c->events[i]->start->day > day1) ||
                    (c->events[i]->start->year == year1 && month1 == c->events[i]->start->month && c->events[i]->start->day == day1 && c->events[i]->start->hour > hour1) ||
                    (c->events[i]->start->year == year1 && month1 == c->events[i]->start->month && c->events[i]->start->day == day1 && c->events[i]->start->hour == hour1 && c->events[i]->start->minute > minute1) ||
                    (c->events[i]->start->year == year1 && month1 == c->events[i]->start->month && c->events[i]->start->day == day1 && c->events[i]->start->hour == hour1 && c->events[i]->start->minute == minute1 &&
                     c->events[i]->start->second > second1))&&((c->events[i]->start->year < year2) || (c->events[i]->start->year == year2 && c->events[i]->start->month < month2) ||
                                                               (c->events[i]->start->year == year2 && month2 == c->events[i]->start->month && c->events[i]->start->day < day2) ||
                                                               (c->events[i]->start->year == year2 && month2 == c->events[i]->start->month && c->events[i]->start->day == day2 && c->events[i]->start->hour < hour2) ||
                                                               (c->events[i]->start->year == year2 && month2 == c->events[i]->start->month && c->events[i]->start->day == day2 && c->events[i]->start->hour == hour2 && c->events[i]->start->minute < minute2) ||
                                                               (c->events[i]->start->year == year2 && month2 == c->events[i]->start->month && c->events[i]->start->day == day2 && c->events[i]->start->hour == hour2 && c->events[i]->start->minute == minute2 &&
                                                                c->events[i]->start->second < second2))) check=1;

                if(((c->events[i]->start->year > year2) || (c->events[i]->start->year == year2 && c->events[i]->start->month > month2) ||
                    (c->events[i]->start->year == year2 && month2 == c->events[i]->start->month && c->events[i]->start->day > day2) ||
                    (c->events[i]->start->year == year2 && month2 == c->events[i]->start->month && c->events[i]->start->day == day2 && c->events[i]->start->hour > hour2) ||
                    (c->events[i]->start->year == year2 && month2 == c->events[i]->start->month && c->events[i]->start->day == day2 && c->events[i]->start->hour == hour2 && c->events[i]->start->minute > minute2) ||
                    (c->events[i]->start->year == year2 && month2 == c->events[i]->start->month && c->events[i]->start->day == day2 && c->events[i]->start->hour == hour2 && c->events[i]->start->minute == minute2 &&
                     c->events[i]->start->second > second2))&&((c->events[i]->end->year > year1) || (c->events[i]->end->year == year1 && c->events[i]->end->month > month1) ||
                                                               (c->events[i]->end->year == year1 && month1 == c->events[i]->end->month && c->events[i]->end->day > day1) ||
                                                               (c->events[i]->end->year == year1 && month1 == c->events[i]->end->month && c->events[i]->end->day == day1 && c->events[i]->end->hour > hour1) ||
                                                               (c->events[i]->end->year == year1 && month1 == c->events[i]->end->month && c->events[i]->end->day == day1 && c->events[i]->end->hour == hour1 && c->events[i]->end->minute > minute1) ||
                                                               (c->events[i]->end->year == year1 && month1 == c->events[i]->end->month && c->events[i]->end->day == day1 && c->events[i]->end->hour == hour1 && c->events[i]->end->minute == minute1 &&
                                                                c->events[i]->end->second > second1))) check=1;

                if(((c->events[i]->end->year > year1) || (c->events[i]->end->year == year1 && c->events[i]->end->month > month1) ||
                    (c->events[i]->end->year == year1 && month1 == c->events[i]->end->month && c->events[i]->end->day > day1) ||
                    (c->events[i]->end->year == year1 && month1 == c->events[i]->end->month && c->events[i]->end->day == day1 && c->events[i]->end->hour > hour1) ||
                    (c->events[i]->end->year == year1 && month1 == c->events[i]->end->month && c->events[i]->end->day == day1 && c->events[i]->end->hour == hour1 && c->events[i]->end->minute > minute1) ||
                    (c->events[i]->end->year == year1 && month1 == c->events[i]->end->month && c->events[i]->end->day == day1 && c->events[i]->end->hour == hour1 && c->events[i]->end->minute == minute1 &&
                     c->events[i]->end->second > second1))&&((c->events[i]->end->year < year2) || (c->events[i]->end->year == year2 && c->events[i]->end->month < month2) ||
                                                             (c->events[i]->end->year == year2 && month2 == c->events[i]->end->month && c->events[i]->end->day < day2) ||
                                                             (c->events[i]->end->year == year2 && month2 == c->events[i]->end->month && c->events[i]->end->day == day2 && c->events[i]->end->hour < hour2) ||
                                                             (c->events[i]->end->year == year2 && month2 == c->events[i]->end->month && c->events[i]->end->day == day2 && c->events[i]->end->hour == hour2 && c->events[i]->end->minute < minute2) ||
                                                             (c->events[i]->end->year == year2 && month2 == c->events[i]->end->month && c->events[i]->end->day == day2 && c->events[i]->end->hour == hour2 && c->events[i]->end->minute == minute2 &&
                                                              c->events[i]->end->second< second2))) check=1;

                if(((c->events[i]->start->year > year1) || (c->events[i]->start->year == year1 && c->events[i]->start->month > month1) ||
                    (c->events[i]->start->year == year1 && month1 == c->events[i]->start->month && c->events[i]->start->day > day1) ||
                    (c->events[i]->start->year == year1 && month1 == c->events[i]->start->month && c->events[i]->start->day == day1 && c->events[i]->start->hour > hour1) ||
                    (c->events[i]->start->year == year1 && month1 == c->events[i]->start->month && c->events[i]->start->day == day1 && c->events[i]->start->hour == hour1 && c->events[i]->start->minute > minute1) ||
                    (c->events[i]->start->year == year1 && month1 == c->events[i]->start->month && c->events[i]->start->day == day1 && c->events[i]->start->hour == hour1 && c->events[i]->start->minute == minute1 &&
                     c->events[i]->start->second > second1))&&((c->events[i]->end->year < year2) || (c->events[i]->end->year == year2 && c->events[i]->end->month < month2) ||
                                                               (c->events[i]->end->year == year2 && month2 == c->events[i]->end->month && c->events[i]->end->day < day2) ||
                                                               (c->events[i]->end->year == year2 && month2 == c->events[i]->end->month && c->events[i]->end->day == day2 && c->events[i]->end->hour < hour2) ||
                                                               (c->events[i]->end->year == year2 && month2 == c->events[i]->end->month && c->events[i]->end->day == day2 && c->events[i]->end->hour == hour2 && c->events[i]->end->minute < minute2) ||
                                                               (c->events[i]->end->year == year2 && month2 == c->events[i]->end->month && c->events[i]->end->day == day2 && c->events[i]->end->hour == hour2 && c->events[i]->end->minute == minute2 &&
                                                                c->events[i]->end->second< second2))) check=1;


            }
            if(check==1)return 0;
            else return 1;
        }

    }
    return 0;
}

void freeCalendar(Calendar *c)
{
    for(size_t i=0; i<c->count; i++) {
        free(c->events[i]);
    }
    free(c->events);
    free(c);
}

void printCalendar(Calendar *c)
{
    for(size_t i=0; i<c->count; i++)
    {
        printf("%02d-%02d-%04d %02d:%02d:%02d ", c->events[i]->start->day, c->events[i]->start->month, c->events[i]->start->year, c->events[i]->start->hour, c->events[i]->start->minute, c->events[i]->start->second);
        printf("%02d-%02d-%04d %02d:%02d:%02d\n", c->events[i]->end->day, c->events[i]->end->month, c->events[i]->end->year, c->events[i]->end->hour, c->events[i]->end->minute, c->events[i]->end->second);

    }
}

void printFreeTime(Calendar *c, int year, int month, int day)
{
    int eventEndHour[c->count], eventEndMinute[c->count], eventEndSecond[c->count], eventStartHour[c->count], eventStartMinute[c->count], eventStartSecond[c->count];
    int check1=0;
    int check2=0;
    int inc=0;
    int swap=0;
    double time1=0, time2=0;
    double time=0;
    for(size_t j=0; j<c->count; j++)
    {
        eventEndHour[j]=0;
        eventEndMinute[j]=0;
        eventEndSecond[j]=0;
        eventStartHour[j]=0;
        eventStartMinute[j]=0;
        eventStartSecond[j]=0;
    }
    for(size_t i=0; i<c->count; i++)
    {
        if(((c->events[i]->start->year<year) || (c->events[i]->start->year==year  && c->events[i]->start->month<month) ||(c->events[i]->start->year==year  && c->events[i]->start->month==month && c->events[i]->start->day==day))&&(c->events[i]->end->year==year  && c->events[i]->end->month==month && c->events[i]->end->day==day))
        {
            eventEndHour[i]=c->events[i]->end->hour;
            eventEndMinute[i]=c->events[i]->end->minute;
            eventEndSecond[i]=c->events[i]->end->second;
            inc++;
            check1=1;

        }
        if((c->events[i]->start->year==year  && c->events[i]->start->month==month && c->events[i]->start->day==day)&&(c->events[i]->end->year==year  && c->events[i]->end->month==month && c->events[i]->end->day==day))
        {
            eventEndHour[i]=c->events[i]->end->hour;
            eventEndMinute[i]=c->events[i]->end->minute;
            eventEndSecond[i]=c->events[i]->end->second;
            eventStartHour[i]=c->events[i]->start->hour;
            eventStartMinute[i]=c->events[i]->start->minute;
            eventStartSecond[i]=c->events[i]->start->second;
            inc++;

        }

        if((c->events[i]->start->year==year  && c->events[i]->start->month==month && c->events[i]->start->day==day)&&(c->events[i]->end->year!=year  || c->events[i]->end->month!=month || c->events[i]->end->day!=day))
        {
            eventStartHour[i]=c->events[i]->start->hour;
            eventStartMinute[i]=c->events[i]->start->minute;
            eventStartSecond[i]=c->events[i]->start->second;
            inc++;
            check2=1;

        }

    }

    for(size_t i=0; i<c->count; i++)
    {
        for(size_t j=1; j<c->count-1; j++)
        {
            if (eventStartHour[j-1] > eventStartHour[j])
            {
                swap=eventStartHour[j-1];
                eventStartHour[j-1]=eventStartHour[j];
                eventStartHour[j]=swap;

                swap=eventStartMinute[j-1];
                eventStartMinute[j-1]=eventStartMinute[j];
                eventStartMinute[j]=swap;

                swap=eventStartSecond[j-1];
                eventStartSecond[j-1]=eventStartSecond[j];
                eventStartSecond[j]=swap;
            }
        }
    }

    for(size_t i=0; i<c->count; i++)
    {
        for(size_t j=1; j<c->count-1; j++)
        {
            if (eventStartHour[j-1] == eventStartHour[j])
            {
                swap=eventStartMinute[j-1];
                eventStartMinute[j-1]=eventStartMinute[j];
                eventStartMinute[j]=swap;

                swap=eventStartSecond[j-1];
                eventStartSecond[j-1]=eventStartSecond[j];
                eventStartSecond[j]=swap;
            }
        }
    }

    for(size_t i=0; i<c->count; i++)
    {
        for(size_t j=1; j<c->count-1; j++)
        {
            if (eventStartMinute[j-1] == eventStartMinute[j])
            {
                swap=eventStartSecond[j-1];
                eventStartSecond[j-1]=eventStartSecond[j];
                eventStartSecond[j]=swap;
            }
        }
    }

    for(size_t i=0; i<c->count; i++)
    {
        for(size_t j=1; j<c->count-1; j++)
        {
            if (eventEndHour[j-1] > eventEndHour[j])
            {
                swap=eventEndHour[j-1];
                eventEndHour[j-1]=eventEndHour[j];
                eventEndHour[j]=swap;

                swap=eventEndMinute[j-1];
                eventEndMinute[j-1]=eventEndMinute[j];
                eventEndMinute[j]=swap;

                swap=eventEndSecond[j-1];
                eventEndSecond[j-1]=eventEndSecond[j];
                eventEndSecond[j]=swap;
            }
        }
    }

    for(size_t i=0; i<c->count; i++)
    {
        for(size_t j=1; j<c->count-1; j++)
        {
            if (eventEndHour[j-1] == eventEndHour[j])
            {
                swap=eventEndMinute[j-1];
                eventEndMinute[j-1]=eventEndMinute[j];
                eventStartMinute[j]=swap;

                swap=eventEndSecond[j-1];
                eventEndSecond[j-1]=eventEndSecond[j];
                eventEndSecond[j]=swap;
            }
        }
    }

    for(size_t i=0; i<c->count; i++)
    {
        for(size_t j=1; j<c->count-1; j++)
        {
            if (eventStartMinute[j-1] == eventStartMinute[j])
            {
                swap=eventEndSecond[j-1];
                eventEndSecond[j-1]=eventEndSecond[j];
                eventEndSecond[j]=swap;
            }
        }
    }

    if(check1==0 && check2==0)
    {
        printf("00:00:00 - %d:%d:%d\n", eventStartHour[0], eventStartMinute[0], eventStartSecond[0]);

        time1=(eventStartHour[0]*3600+eventStartMinute[0]*60+eventStartSecond[0]);

        time=time1/60;

        printf("%.2lf\n", time);



        for(int i=0; i<inc-1; i++)
        {
            printf("%d:%d:%d - %d:%d:%d\n", eventEndHour[i], eventEndMinute[i], eventEndSecond[i], eventStartHour[i+1], eventStartMinute[i+1], eventStartSecond[i+1]);
            time1=eventEndHour[i]*3600+eventEndMinute[i]*60+eventEndSecond[i];
            time2=eventStartHour[i+1]*3600+eventStartMinute[i+1]*60+eventStartSecond[i+1];
            time=(time2-time1)/60;
            printf("%.2lf\n", time);
        }

        printf("%d:%d:%d - 23:59:59\n", eventEndHour[inc], eventEndMinute[inc], eventEndSecond[inc]);
        time2=86400;
        time1=eventEndHour[inc]*3600+eventEndMinute[inc]*60+eventEndSecond[inc];
        time=(time2-time1)/60;
        printf("%.2lf\n", time);
    }

    if(check1==1 && check2==0)
    {
        for(int i=0; i<inc-1; i++)
        {
            printf("%d:%d:%d - %d:%d:%d\n", eventEndHour[i], eventEndMinute[i], eventEndSecond[i], eventStartHour[i], eventStartMinute[i], eventStartSecond[i]);
            time1=eventEndHour[i]*3600+eventEndMinute[i]*60+eventEndSecond[i];
            time2=eventStartHour[i]*3600+eventStartMinute[i]*60+eventStartSecond[i];
            time=(time2-time1)/60;
            printf("%.2lf\n", time);
        }

        printf("%d:%d:%d - 23:59:59\n", eventEndHour[inc], eventEndMinute[inc], eventEndSecond[inc]);
        time2=86400;
        time1=eventEndHour[inc]*3600+eventEndMinute[inc]*60+eventEndSecond[inc];
        time=(time2-time1)/60;
        printf("%.2lf\n", time);
    }

    if(check1==0 && check2==1)
    {
        printf("00:00:00 - %d:%d:%d\n", eventStartHour[0], eventStartMinute[0], eventStartSecond[0]);

        time1=(eventStartHour[0]*3600+eventStartMinute[0]*60+eventStartSecond[0]);

        time=time1/60;

        printf("%.2lf\n", time);



        for(int i=0; i<inc-1; i++)
        {
            printf("%d:%d:%d - %d:%d:%d\n", eventEndHour[i], eventEndMinute[i], eventEndSecond[i], eventStartHour[i+1], eventStartMinute[i+1], eventStartSecond[i+1]);
            time1=eventEndHour[i]*3600+eventEndMinute[i]*60+eventEndSecond[i];
            time2=eventStartHour[i+1]*3600+eventStartMinute[i+1]*60+eventStartSecond[i+1];
            time=(time2-time1)/60;
            printf("%.2lf\n", time);
        }


    }

    if(check1==1 && check2==1)
    {
        for(int i=0; i<inc; i++)
        {
            printf("%d:%d:%d - %d:%d:%d\n", eventEndHour[i], eventEndMinute[i], eventEndSecond[i], eventStartHour[i], eventStartMinute[i], eventStartSecond[i]);
            time1=eventEndHour[i]*3600+eventEndMinute[i]*60+eventEndSecond[i];
            time2=eventStartHour[i]*3600+eventStartMinute[i]*60+eventStartSecond[i];
            time=(time2-time1)/60;
            printf("%.2lf\n", time);
        }
    }
}







int main() {
    cal = makeCalendar();
    char input[42];
    char z;
    char *token;
    char cut[] = " :-";
    int i = 0;
    int operator=0;




    while(operator==0) {
        fgets(input, sizeof(input), stdin);

        z = input[0];

        switch (z) {
            case 'q' : {
                operator=1;
                break;
            }
            case 'A':
            case 'a': {
                int year1 = 0, year2 = 0, month1 = 0, month2 = 0, day1 = 0, day2 = 0, hour1 = 0, hour2 = 0, minute1 = 0, minute2 = 0, second1 = 0, second2 = 0;
                Date *d1, *d2;
                Event *e;
                token = strtok(input, cut);

                i=0;

                while (token != NULL) {


                    if (i == 1) {
                        day1 = atoi(token);
                    }
                    if (i == 2) {
                        month1 = atoi(token);
                    }
                    if (i == 3) {
                        year1 = atoi(token);
                    }
                    if (i == 4) {
                        hour1 = atoi(token);
                    }
                    if (i == 5) {
                        minute1 = atoi(token);
                    }
                    if (i == 6) {
                        second1 = atoi(token);
                    }
                    if (i == 7) {
                        day2 = atoi(token);
                    }
                    if (i == 8) {
                        month2 = atoi(token);
                    }
                    if (i == 9) {
                        year2 = atoi(token);
                    }
                    if (i == 10) {
                        hour2 = atoi(token);
                    }
                    if (i == 11) {
                        minute2 = atoi(token);
                    }
                    if (i == 12) {
                        second2 = atoi(token);
                    }
                    token = strtok(NULL, cut);
                    i++;
                }
                if (compareDate(cal, day1, month1, year1, hour1, minute1, second1, day2, month2, year2, hour2, minute2, second2))
                {
                    d1 = makeDate(day1, month1, year1, hour1, minute1, second1);
                    d2 = makeDate(day2, month2, year2, hour2, minute2, second2);
                    e = makeEvent(d1, d2);
                    cal->count = addCalendar(e, cal);
                }


                break;
            }
            case 'F':
            case 'f': {
                int day, month, year;

                int j=0;

                token = strtok(input, cut);

                while (token != NULL) {


                    if (j == 1) {
                        day = atoi(token);
                    }
                    if (j == 2) {
                        month = atoi(token);
                    }
                    if (j == 3) {
                        year = atoi(token);
                    }

                    token = strtok(NULL, cut);
                    j++;
                }


                printFreeTime(cal, year, month, day);

                break;
            }
            case 'S':
            case 's': {
                printCalendar (cal);

                break;
            }

            default: {

                break;
            }


        }

    }


    freeCalendar(cal);

    return 1;
}



