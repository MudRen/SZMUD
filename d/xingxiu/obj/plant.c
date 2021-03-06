// u/jiuer/desplant.c

#include "ansi.h"
inherit ITEM;

string* names = ({
        GRN"骆驼刺"NOR,
        HIG"仙人掌"NOR,
        "沙枣花",
});

string* longs = ({
	"一株生长在沙漠的木本植物，因骆驼常食之而得名。\n",
	"这是一株满身是毛刺的鲜绿的仙人掌。\n",
	"这是一株干旱地区生长的小树，花味甚香，果可食。\n",
});

void create()
{
    int i = random(sizeof(longs));

    set_name(names[i], ({"plant", "zhiwu"}));
    set_weight(i*100 + 300); 
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("long", longs[i]);
	set( "remain", 2 );
	set("unit","株");
	set("material", "wood");
    }
    setup();
}

void init()
{
	add_action("do_ji", "ji");
}

int do_ji(string arg)
{
	object obj, me;

	if (!arg || (arg != "plant" && arg != "zhiwu"))
		return notify_fail("什么？\n");

	if ( query( "remain" ) < 1 ) 
	return notify_fail( "你费了半天劲也不能从"+query("name")+"多挤出一滴水。\n" );
	me = this_player();
	if (me->query("neili") < 10)
		return notify_fail("你力气不足，不能从植物根中挤出水份！\n");
	message_vision(HIW"$N吸了口气，两手抱住植物根茎，使劲想挤出点水份！\n"NOR,me); 
	write(HIW"只听得“嘭”的一声，你从树根里挤出点水份，喝得眼冒金星，你狂饮起来！\n"NOR);
	me->add("neili", -10);
	add( "remain", -1 );
    if ( me->query( "water" ) < (10+me->query("str"))*10 )
    me->add("water",  80);
	//destruct(this_object());
	return 1;
}
