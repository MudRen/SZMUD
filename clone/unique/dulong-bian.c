// Code of ShenZhou
// dulong-bian.c ������ 
// Ryu

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit WHIP;

void create()
{
        set_name("������",({ "dulong bian", "bian", "whip", "dulong" }) );
        set_weight(700);
	set_color(YEL);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 7000000);
		set("rigidity", 100000);
		set("poison_applied", 300);
                set("material", "leather");
                set("long", 
		"����һ������Ҳ�Ƶ���ɫ��ޣ������������࣬��ͷװ��ʮ��ֻ���λεļ����������\n");
		set("wield_msg", "$N��ৡ���һ����������һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�������\n");
        }
	init_whip(50);
        setup();
	::create();
}
