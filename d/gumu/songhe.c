// songhe.c 松鹤泉
// by April 01.08.28

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", "松鹤泉");
    set("long", @LONG
这是古墓内的一眼温泉。一串串像珍珠似的泉泡，从池底的石缝里骨
突突的升起，似乎永不枯竭，不溢不涸。此泉又名为花月潭，乃取自花前
月下之意。
LONG
    );
    
    set("exits", ([
		"south" : __DIR__"houtang",
    ]));

	set("cost", 1);
    set("resource/water", 1);

    setup();
}

void init()
{
	add_action("do_wash", "wash");
    add_action("do_drink", "drink");
}

int do_wash(string arg)
{
	object me = this_player();
	if ( !arg || arg != "face" ) return 0;

	message_vision(CYN"$N轻轻地捧起一些温泉水洗了洗脸。\n"NOR, me);

	if ( me->query("gender") == "女性" && 
    me->query_skill("beauty", 1) < 150) {
		tell_object(me, CYN"你觉得发现了一些新的驻颜窍门。\n"NOR);
		me->improve_skill("beauty", me->query_per()*2);
		me->receive_damage("jing", 10, "把脸洗破，羞死了");
	}
	
	return 1;
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<me->max_water_capacity()) {
            me->set("water", current_water+10+random(20));
            message("vision", me->name()+"捧了一把温泉喝了下去。\n"
            , environment(me), ({me}) );
            write("你捧了一把温泉喝了下去。泉水甘甜，一入胸腹，一缕热气温暖心脾，气血通畅。\n");
        if ((int)me->query("eff_qi") != 
            (int)me->query("max_qi"))
            me->receive_curing("qi", random(10));
        }
        else write("你一口气喝了好多玉液泉，已经再也喝不下了。\n");

        return 1;
}

