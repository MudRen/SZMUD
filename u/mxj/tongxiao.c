// Room Of Mxj
// have a good day

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIG "��ͭ��" NOR,({ "tong xiao", "xiao" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("value", 400);
                set("material", "steel");
                set("shape", "flute");
                set("long", "һ����ͭ����Ķ��ͨ��ͭ�̰�쵣���������Щ��ͷ�ˡ�\n");
                set("wield_msg", "$N��������һ֧��ͭ�\n");
                set("unwield_msg", "$N��$n�嵽���ᡣ\n" );
        }
	init_sword(40);
        setup();

}

#include "flute.h"
#include "music.h"

