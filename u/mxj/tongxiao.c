// Room Of Mxj
// have a good day

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIG "青铜箫" NOR,({ "tong xiao", "xiao" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("value", 400);
                set("material", "steel");
                set("shape", "flute");
                set("long", "一柄青铜打造的洞箫，通体铜绿斑斓，看起来有些年头了。\n");
                set("wield_msg", "$N从腰间抽出一支青铜箫。\n");
                set("unwield_msg", "$N将$n插到领後。\n" );
        }
	init_sword(40);
        setup();

}

#include "flute.h"
#include "music.h"

