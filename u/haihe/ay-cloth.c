// 暗月之衣。 ay-cloth.c
// by naihe 02-05-15

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(BLU"暗月之衣"NOR, ({ "anyue cloth","anyue yi","yi"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long","一件普通模样的衣服，却散发着某种幽然的气息。\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

void init()
{
	add_action("do_wear","wear");
}

void do_wear()
{
	if(this_player()->query("id")!="naihe" && this_player()->query("id")!="spark")
	{
		message_vision("$N忽地发出一阵幽幽的叹息声，就此消失不见。\n",this_object());
        	destruct(this_object());
	}
}
