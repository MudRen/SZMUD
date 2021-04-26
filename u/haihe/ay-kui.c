// 暗月之盔  ay-kui.c
// by naihe 02-05-16

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(BLU"暗月之盔"NOR, ({ "anyue kui", "kui" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
                set("long", "一顶普通模样的头盔，却散发着某种幽然的气息。\n");
                set("value", 0);
                set("material", "steel");
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
