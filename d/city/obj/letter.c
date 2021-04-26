// Code of ShenZhou
// Write by Wzfeng 12-29


#include <ansi.h>
#include <localtime.h>

inherit ITEM;
static string *sym_di = ({ "��","��","��","î","��","��","��","δ","��","��","��","��" });
string chinese_time(int date)
{
    mixed *local;
    int i;

    local = localtime(date);
    i = (local[LT_HOUR]+1) % 2 * 2 + local[LT_MIN] / 30;
    return sprintf("������%s��%s��%sʱ%s",
    chinese_number(local[LT_MON] + 1),
    chinese_number(local[LT_MDAY]),
    sym_di[((local[LT_HOUR] + 1) % 24) / 2],
    i?chinese_number((local[LT_HOUR]+1) % 2 * 2 + 
    local[LT_MIN] / 30 ) + "��":"��");
}

void create()
{       
    set_name("�ź�", ({"letter","xin han"}));
    set("long", "����һֻ�Ѿ���õ��ź���\n");

    set_weight(5);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("can_shi", 1);

    }
}

void init ()
{
    add_action("do_read", "read");
    add_action("do_shi", "chai");
    add_action("do_shi", "open");
}

int do_shi(string arg)
{
    object ob;
    string str_time;
    if(!arg) return notify_fail("��Ҫ��ʲô��\n");

    ob = present(arg, this_player());

    if(!ob)  return notify_fail("�����ϲ�û������ź���\n");

    if(!ob->query("can_shi"))
        return notify_fail("�Բ����㲻�ܲ������Ʒ��\n");
        
    str_time=chinese_time(ob->query("letter/time"));

    switch( ob->query("letter/send_level"))
    {
        case 1:
        {
            message_vision("ֻ��$N�ӻ����ó�һ��������������ķ���˺�������������ż���\n", this_player());
            ob->set("long", 
                "����һ�����д������ţ���ɶ�(read)�������ݡ�����д�ţ�\n"
                +this_player()->query("name")+"      ������\n"+
                ob->query("letter/from")+"��������վת��\n"
                "������վǩ����"+str_time+"��\n");
            ob->set_name("��", ({"xin","letter"}));
        }

        break;
        case 2:
        {
            message_vision("ֻ��$N�������ó�һ�������������Ľ�����ķ���˺����ȡ��������ż���\n", this_player());
            ob->set("long", 
                "����һ�����д������ţ���ɶ�(read)�������ݡ�����д�ţ�\n"
                +this_player()->query("name")+"      ������\n"+
                ob->query("letter/from")+"��������վת��\n"
                "������վǩ����"+str_time+"��\n");
            ob->set_name(YEL"��"NOR, ({"xin","letter"}));
        }

        break;
        case 3:
        {
            message_vision("ֻ��$N������ȡ��һ�����ң�С������Ľ�����ķ���˺����ȡ��������ż���\n", this_player());
            ob->set("long", 
                "����һ�����д������ţ���ɶ�(read)�������ݡ�����д�ţ�\n"
                +this_player()->query("name")+"      ������\n"+
                ob->query("letter/from")+"��������վת��\n"
                "������վǩ����"+str_time+"��\n");
            ob->set_name(HIR"��"NOR, ({"xin","letter"}));
        }
        break;

    }

    ob->set("can_read_letter",1);
    ob->set("can_add_jinnang",1);
    set("can_shi",0);
    return 1;
}

int do_read(string arg)
{
     object ob_letter;
     int i;
     mapping letter;


     if(!arg) return notify_fail("��Ҫ��ʲô�ż���\n");
        ob_letter = present(arg, this_player());

    if(!ob_letter)
        return notify_fail("�����ϲ�û������ż���\n");
    if(!ob_letter->query("can_read_letter"))
        return notify_fail("�Բ������޷�������������κζ�����\n");
        
        
    //letter=ob->query("letter");
    letter=ob_letter->query("letter");
    if(!ob_letter->query("be_read"))
        {
        letter["time"]=chinese_time(letter["time"]);
    }
    printf("�����ű��⡿��%s\n�������ˡ���%s\n���ż����ݡ���\n%s\n\t\t%sд��%s\n\n\n",
    letter["title"],
    letter["to"],
    letter["text"],
    letter["from"],
    letter["time"]
    );
    ob_letter->set("be_read",1);

    return 1;
}

