// 暗月披风。 ay-pifeng.c
// by naihe 02-05-15

#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
	set_name(BLU"暗月披风"NOR, ({"anyue manteau","manteau","pifeng","pi"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long","一件普通模样的披风，却散发着某种幽然的气息。\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

void init()
{
	add_action("do_wear","wear");
}

void del_me()
{
        message_vision(""BLU"暗月披风"NOR"忽地发出一阵幽幽的叹息声，就此消失不见。\n",this_player());
        destruct(this_object());
}

void do_wear()
{
	if(this_player()->query("id")!="naihe" && this_player()->query("id")!="spark")
	{
		call_out("del_me",1+random(5));
	}
}

