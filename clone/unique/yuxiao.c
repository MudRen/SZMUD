// Code of ShenZhou
// yuxiao.c ����
// Ryu

#include <weapon.h>
#include <ansi.h>
#include "/clone/unique/special_weapon.h"

inherit F_UNIQUE;
inherit SWORD;

void create()
{
        set_name("����",({ "yu xiao", "xiao" }) );
        set_weight(3000);
	set_color(HIG);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 7000000);
		set("rigidity", 10000);
                set("material", "steel");
                set("shape", "flute");
                set("long", 
		"һ�����������ͨ�徧Ө���̣������ڴ�������ߣ������Ѫ����Ȼ����\n"
		"������������ǧ��Ĺ��\n");
                set("wield_msg", 
		    HIG "$N��������һ֧����������ŵ�������������������˼���������㼴ƽ\n"
			"����$N�漴�͵���������Ц�����ټ��ģ��������ڳճ�ЦЦ����\n"NOR);
                set("unwield_msg", CYN "$N��$n�嵽���ᡣ\n" NOR);
                set("unequip_msg", CYN "$N��$n�嵽���ᡣ\n" NOR);
        }
	init_sword(120);
        setup();
	::create();
}
#include "/d/taohua/obj/flute.h"
#include "/d/taohua/obj/music.h"
