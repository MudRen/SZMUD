// Code of ShenZhou
// ningbi-jian ���̽�
// qfy September 29, 1996

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("���̽�",({ "ningbi jian", "ningbi", "sword", "jian" }) );
        set_weight(4000);
	set_color(HIG);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 7000);
                set("material", "steel");
                set("long", 
		"�˽�Ϊ�ʵ����ͣ��Ͻ������������쳣��\n");
                set("wield_msg", 
		    HIG "$N���$n��ֻ���˽�����һ����ˮ���������ˣ�����Ѱ��������\n" NOR );
                set("unwield_msg", HIG "$N�����ؽ�$nһ��һ����������С�\n" NOR);
                set("unequip_msg", HIG "$N�����ؽ�$nһ��һ����������С�\n" NOR);
        }
	init_sword(200);
        setup();
}
