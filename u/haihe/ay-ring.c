// 暗月之戒  ay-ring.c
// by naihe 02-05-16

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name(BLU"暗月之戒"NOR, ({ "anyue ring", "ring","jie"}));
        set("weight",100);
	if(random(2)==1)
                set("long", "一枚散发着幽幽气息的小戒指，上面刻着两个小字：奈何。\n");
	else set("long","一枚散发着幽幽气息的小戒指，上面刻着两个小字：闪烁。\n");

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("value",0);
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
