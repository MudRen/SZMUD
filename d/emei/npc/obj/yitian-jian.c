// Code of ShenZhou
// yitian-jian.c

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h";
void create()
{
	set_name("���콣", ({ "yitian jian", "yitian", "sword" }) );
	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
                set("long", "һ���ĳ������ĹŽ����������ý�˿���������֣������졹��\n");
		set("value", 10000);
		set("material", "steel");
                set("wield_msg",
			HIG"ֻ�����һ����$N�������Ѿ�����һ��$n������ȳ���˭������ !\n"NOR);
                set("unwield_msg", HIG"$N�����е�$n��������Ľ��ʡ�\n"NOR);
                set("unequip_msg", HIG"$N�����е�$n��������Ľ��ʡ�\n"NOR);
        }

	init_sword(300);
        setup();
	::create();
}

