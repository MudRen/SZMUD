// Code of ShenZhou
// tiexiao.c ����
// kane

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(YEL "����" NOR,({ "tie xiao", "xiao" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("value", 300);
                set("material", "steel");
                set("shape", "flute");
                set("long", "һ����ͨ���ƶ����������Щ׹�֡�\n");
                set("wield_msg", "$N��������һ֧���\n");
                set("unwield_msg", "$N��$n�嵽���ᡣ\n" );
        }
	init_sword(20);
        setup();

}

#include "flute.h"
#include "music.h"
