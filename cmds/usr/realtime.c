// realtime.c
#include <localtime.h>
#include <ansi.h>

inherit F_CLEAN_UP;

string chinese_time(int type,string get_time)
{
        //Define Varibles
        string e_time, week, month, year;
        string c_week, c_year, c_month, c_time;
        string ca_week, ca_year, ca_month, ca_time;


        //Define Day
        int day, hour, minute, second, chour, ehour, cehour, cday, eday, ceday;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
                "Aug","Sep","Oct","Nov","Dec"});



        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});

        if ( stringp(get_time) )
                e_time = get_time;
        else e_time = ctime(time());

        // e_time must is ctime(time string) like "Sun May  3 00:52:12 1998"
        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);


                //Change the Time Setting from Code Side
                hour = hour - 1;

        c_week  = chinese_number(member_array(week, week_name) + 1);
        c_month = chinese_number(member_array(month, month_name) + 1);

        c_year  = sprintf("%s%s%s%s",
                         chinese_number(year[0]-48),
                         chinese_number(year[1]-48),
                         chinese_number(year[2]-48),
                         chinese_number(year[3]-48));

        c_year = c_year + "年";
        c_month  = c_month + "月";
        c_week = " 星期"+c_week;

        c_time = chinese_number(day) + "日";
        c_time += chinese_number(hour) + "点";
        c_time += chinese_number(minute) + "分";
        // maybe not need srcond to show
        // c_time += chinese_number(second) + "秒";


        chour = hour - 15;
        ehour = hour - 9;
        cehour = hour - 13;

        cday = day;
        eday = day;
        ceday = day;

        if (chour < 1)
        {
        chour = 24 + chour;
        cday = day - 1;
        }

        if (ehour < 1)
        {
        ehour = 24 + ehour;
        eday = day - 1;
        }

        if (cehour < 1)
        {
        cehour = 24 + cehour;
        ceday = day - 1;
        }


        if (type) {
                switch( type ) {
                        case 1: return (member_array(month, month_name) + 1)+"月"+day+"日"+hour+"点"+minute+"分";
                        case 2: return (member_array(month, month_name) + 1)+"月"+cday+"日"+chour+"点"+minute+"分";
                        case 3: return (member_array(month, month_name) + 1)+"月"+eday+"日"+ehour+"点"+minute+"分";
                        case 4: return (member_array(month, month_name) + 1)+"月"+ceday+"日"+cehour+"点"+minute+"分";


                        case 5: return year+"年"+(member_array(month, month_name) + 1)+
                                "月"+day+"日"+hour+"点"+minute+"分";
                        case 6: return (member_array(month, month_name) + 1)+
                                "月"+day+"日"+hour+"点"+minute+"分";
                        default: return c_year+c_month+c_time+c_week;
                        }
                }
        return c_year+c_month+c_time+c_week;
}

int main(object me, string arg)
{
        int i;

        if(!arg||sscanf(arg,"%d",i)!=1)
    {
        write(HIG"----------------- 世界时间表 -------------------\n"NOR);
        write(HIY"         地区        |           时间           \n"NOR);
        write(HIG"------------------------------------------------\n"NOR);
        write(" 上海/北京时间       |现在是" + chinese_time(1,(string)localtime(time())) + "\n");
        write(HIG"------------------------------------------------\n"NOR);
        write(" 加拿大(西)时间(夏令)|现在是" + chinese_time(2,(string)localtime(time())) + "\n");
        write(HIG"------------------------------------------------\n"NOR);
        write(" 加拿大(东)时间      |现在是" + chinese_time(4,(string)localtime(time())) + "\n");
        write(HIG"------------------------------------------------\n"NOR);
        write(" 美国 (西)时间 (夏令)|现在是" + chinese_time(2,(string)localtime(time())) + "\n");
        write(HIG"------------------------------------------------\n"NOR);
        write(" 美国 (东)时间       |现在是" + chinese_time(4,(string)localtime(time())) + "\n");
        write(HIG"------------------------------------------------\n"NOR);
        write(" 英国时间            |现在是" + chinese_time(3,(string)localtime(time())) + "\n");
        write(HIG"------------------------------------------------\n"NOR);
    }
        else
                write("现在是" + chinese_time(i,(string)localtime(time())) + "。\n");
        return 1;
}

int help(object me)
{
     write(@HELP
指令格式: realtime

这个指令让你(你)知道现在的实际时间。

HELP
    );
    return 1;
}
