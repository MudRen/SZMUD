// 暗月之戒  ay-ring.c
// by naihe 02-05-16

#include <ansi.h>
#include <armor.h>

inherit FINGER;

int query_autoload() { return 1; }

void create()
{
        set_name(BLU"暗月之戒"NOR, ({ "anyue ring", "ring","jie"}));
        set("weight",100);
        set("long", "一枚散发着幽幽气息的小戒指，上面似乎还刻着两个小字。\n");
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

void del_me()
{
	message_vision(""BLU"暗月之戒"NOR"忽地发出一阵幽幽的叹息声，就此消失不见。\n",this_player());
        destruct(this_object());
}

void do_wear()
{
	if(this_player()->query("id")=="spark")
	{
		set("long", "一枚散发着幽幽气息的小戒指，上面刻着两个小字：奈何。\n");
		return;
	}

	if(this_player()->query("id")=="naihe")
	{
		set("long", "一枚散发着幽幽气息的小戒指，上面刻着两个小字：闪烁。\n");
		return;
	}

	call_out("del_me",1+random(5));
}

