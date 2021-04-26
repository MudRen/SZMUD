// Code of ShenZhou
// Write by Wzfeng 4/1/1998
//ע�⣬����������㷨��û������������ȥ�ģ�����ÿһ���ͷһ��
//�޸�string chinese_time(int date)����



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
        set_name("��", ({"letter","xin"}));
		set("long", "һ���Ѿ�д�õ��ţ�����ö�(read)�����������ݡ�\n");
		set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                 set("unit", "��");
                }
		set("can_read_letter1",1);
}

void init ()
{
        add_action("do_read", "read");
}


int do_read(string arg)
{
         object ob_letter;
          int i;
         mapping letter;


        if(!arg) return notify_fail("��Ҫ��ʲô�ż���\n");
           ob_letter = present(arg, this_player());

		if(!ob_letter)
                return notify_fail("�����Ϻ���û������ż���\n");
        if(!ob_letter->query("can_read_letter1"))
                return notify_fail("�Բ������޷�������������κζ�����\n");
	
		letter=ob_letter->query("letter");
        printf("�����ű��⡿��%s\n�������ˡ���%s\n���ż����ݡ���\n%s\n\t\t%sд��%s\n\n\n",
        letter["title"],
	letter["to"],
        letter["text"],
	letter["from"],
	chinese_time((letter["time"]))
		);
		 return 1;
}

