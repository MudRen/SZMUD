// Code of ShenZhou
//For check ppl's IP,it's immportant in mirror site.
//By Sure 2/2001
#include "/doc/help.h"

string check_ip(object ob, object *user);

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_checkip","checkip");
}

void create()
{
       set_name(HIG "IP̽����" NOR, ({"tance qi", "finder"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("long",
               "����һ��ʮ��С�ɱ��µ�̽������ר���������������ҵġ� \n"+
                        HIW"�����ڡ�ཡ�����ཡ������š�\n"NOR);

               set("value", 5000);
               set("unit", "��");
                set("material", "steel");
               set("no_get", 1);
       }
}


int do_checkip(string arg)
{
        int i, num;
        string msg, result;
        object *user;

        user = users();

        for(i = 0;i < sizeof(user);i++)
                user[i]->set_temp("pending/ipcheck", 0);

        msg = "\n����������IP��\n\n";
        num = 0;
        for(i = 0;i < sizeof(user);i++) {
                if(user[i]->query_temp("pending/ipcheck") )     continue;


                if( result = check_ip(user[i], user) ) {
msg += HIW + result + NOR"Ŀǰ����"HIY + query_ip_name(user[i]) + NOR"�����С�\n";
                        num++;
                }
        }
        if(num == 0)    msg += "\n�������Ŀǰ������ҵ� IP ������ͬ��\n";

        if(num > 0)     msg += sprintf("\n ��������� 2 ��һ�������ͬ IP ����%d ��\n",num);
        write(msg);
        return 1;
}

string check_ip(object ob, object *user)
{
        int i, find = 0;
        string result, ip, id;

        id = ob->query("id");
        ip = query_ip_name(ob);
        result = ob->query("name") + "(" + ob->query("id") + ")  ";
        for(i = 0;i < sizeof(user);i++) {
                if(user[i]->query("id") != id && query_ip_name(user[i]) == ip) {

                        result += user[i]->query("name") + "(" + user[i]->query("id") + ")  ";
                        user[i]->set_temp("pending/ipcheck", 1);
                        if(id && user[i]->query("id") )
                                find++;
                }
        }

        if( find )      return result;

        return 0;
}
