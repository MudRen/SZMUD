// Code of ShenZhou
// jinshe-jian ���߽�
// qfy September 18, 1996

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name("���߽�",({ "jinshe jian", "jinshe", "sword", "jian" }) );
        set_weight(4000);
	set_color(HIY);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 7000000);
                set("material", "steel");
                set("long", 
		"�˽�������һ�����������ɣ���β���ɽ�������ͷ���ǽ��⣬����ֲ棬\n"
		"���Խ��⾹�����档�˽����ɻƽ������������������������һ��Ѫ��\n"
		"�����������͵İ��⣬���ǹ��졣\n");
                set("wield_msg", 
		    HIY "$Nһ��$n����ʱ�������ˡ�������ܡ�����"+GRN+"����"+HIY+"��Ѫ�����Ž���Ķ�����\n"
		    "��һ�����߲�ͣ��Ť�����ӣ������˶��͡�\n" NOR);
                set("unwield_msg", HIY "$N��$n��ϸ���ò�����ò��ס�\n" NOR);
                set("unequip_msg", HIY "$N��$n��ϸ���ò�����ò��ס�\n" NOR);
        }
	init_sword(120);
        setup();
	::create();
}
