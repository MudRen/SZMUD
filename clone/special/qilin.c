// Code of ShenZhou
#include <ansi.h>

inherit ITEM;
inherit F_EQUIP;

void create()
{
        set_name( "�����", ({ "qilin bi", "qilin", "bi", "arm" }) );
	set_color(RED);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set("long", "����һ���ֱۣ��ഫ����������ʱ�ಲ���������룬��۱�����Ѫ�������ɡ�\n");
                set("unit", "��");
                set("value", 150);
                set("armor_type", "arm");
                set("armor_prop/armor", 1);
                set("armor_prop/strength", 20);
		set("wear_msg", "$N�����꡹һ������$n�����˶ϱ�֮����\n");
		set("remove_msg", "$N����һ�ᣬ��������һ������$nж��������\n");
                set("no_sell", 1);
        }
        setup();
}

void init()
{
	add_action("do_enfor", "jiali");
	add_action("do_enfor", "enforce");
}

int wear()
{
	set("embedded", 1);
        set("no_drop", 1);
        set("no_get", 1);
        set("owner", environment()->query("name"));
        ::wear();
        return 1;
}

int unequip()
{
	if( !wizardp(environment()) ) return 0;
}

string query_autoload()
{
        if( query("equipped") ) return query("name");
}

void autoload(string arg)
{
        set("name", arg);
        set("embedded", 1);
        set("no_drop", 1);
        set("no_get", 1);
        set("owner", environment()->query("name"));
        ::wear();
}

int do_enfor(string arg)
{
        int pts;
	object me = this_player();

	if( !query("embedded") ) return 0;

        if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
                return notify_fail("ָ���ʽ��enforce|jiali <ʹ�����������˵�>|none");

        if( !me->query_skill_mapped("force") )
                return notify_fail("������� enable һ���ڹ���\n");

        if( arg=="none" )
                me->delete("jiali");
        else {
                if( pts < 0 )
                        return notify_fail("��ֻ���� none ��ʾ���������������ֱ�ʾÿһ���ü���������\n");
                if( pts > (int)me->query_skill("force") / 3 * 2 )
                        return notify_fail("����ڹ����Ӳ�����ô������\n");
                me->set("jiali", pts);
        }

	if( pts > 150 )
		message_vision(RED"$N�����������˵����֮�ϣ�ֻ������������ֳ������ɫ��\n"NOR, me);
        write("������������" + chinese_number(pts)+"�������˵С�\n");
        return 1;
}
