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

        c_week  = chinese_number(member_array(week, week_name) + 1);
        c_month = chinese_number(member_array(month, month_name) + 1);

        c_year  = sprintf("%s%s%s%s",
                         chinese_number(year[0]-48),
                         chinese_number(year[1]-48),
                         chinese_number(year[2]-48),
                         chinese_number(year[3]-48));

        c_year = c_year + "��";
        c_month  = c_month + "��";
        c_week = " ����"+c_week;

        c_time = chinese_number(day) + "��";
        c_time += chinese_number(hour) + "��";
        c_time += chinese_number(minute) + "��";
        // maybe not need srcond to show
        // c_time += chinese_number(second) + "��";


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
                        case 1: return (member_array(month, month_name) + 1)+"��"+day+"��"+hour+"��"+minute+"��";
                        case 2: return (member_array(month, month_name) + 1)+"��"+cday+"��"+chour+"��"+minute+"��";
                        case 3: return (member_array(month, month_name) + 1)+"��"+eday+"��"+ehour+"��"+minute+"��";
                        case 4: return (member_array(month, month_name) + 1)+"��"+ceday+"��"+cehour+"��"+minute+"��";


                        case 5: return year+"��"+(member_array(month, month_name) + 1)+
                                "��"+day+"��"+hour+"��"+minute+"��";
                        case 6: return (member_array(month, month_name) + 1)+
                                "��"+day+"��"+hour+"��"+minute+"��";
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
        write(HIG"----------------- ����ʱ��� -------------------\n"NOR);
        write(HIY"         ����        |           ʱ��           \n"NOR);
        write(HIG"------------------------------------------------\n"NOR);
        write(" �Ϻ�/����ʱ��       |������" + chinese_time(1,(string)localtime(time())) + "\n");
        write(HIG"------------------------------------------------\n"NOR);
        write(" ���ô�(��)ʱ��(����)|������" + chinese_time(2,(string)localtime(time())) + "\n");
        write(HIG"------------------------------------------------\n"NOR);
        write(" ���ô�(��)ʱ��      |������" + chinese_time(4,(string)localtime(time())) + "\n");
        write(HIG"------------------------------------------------\n"NOR);
        write(" ���� (��)ʱ�� (����)|������" + chinese_time(2,(string)localtime(time())) + "\n");
        write(HIG"------------------------------------------------\n"NOR);
        write(" ���� (��)ʱ��       |������" + chinese_time(4,(string)localtime(time())) + "\n");
        write(HIG"------------------------------------------------\n"NOR);
        write(" Ӣ��ʱ��            |������" + chinese_time(3,(string)localtime(time())) + "\n");
        write(HIG"------------------------------------------------\n"NOR);
    }
        else
                write("������" + chinese_time(i,(string)localtime(time())) + "��\n");
        return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: realtime

���ָ������(��)֪�����ڵ�ʵ��ʱ�䡣

HELP
    );
    return 1;
}

