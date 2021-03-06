// Code of ShenZhou
// baoguo1.c 保国寺大雄殿
// Shan: 96/06/22

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "大雄殿");
        set("long", @LONG
这里是报国寺大雄殿。报国寺是峨嵋山最大寺院之一。大雄殿内供着金光
灿灿的佛像，气宇轩昂。
LONG
        );
        set("exits", ([
                "out" : __DIR__"baoguo",
		"west": __DIR__"baoguo3",
		"north" : __DIR__"baoguo2",
        ]));

        set("objects", ([
                __DIR__"npc/xiang-ke.c": 2,
        ]));

	set("cost", 0);
        setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( me->query("family/family_name") != "峨嵋派" && dir == "west" )
		return notify_fail("保国寺禅房只接待峨嵋弟子，你要是诚心礼佛，在此多进几注香吧。\n");

	if ( me->query("gender") == "女性" && dir == "west" )
		return notify_fail("这位" + RANK_D->query_respect(me) +
				"，西面乃是男弟子休息的禅房，你一女子不太方便吧？！\n");

	return ::valid_leave(me, dir);
}
nosave string current_id = "";
nosave int current_job = 0;

int introduce_robber(object current_player);
int reset_to_normal();

void init() {
    object challenger, me = this_player();

    if ( (me->query("family/family_name") == "雪山派" ||
          me->query("family/family_name") == "血刀门")
         && (me->query("combat_exp") > 100000) ) {
        call_out("introduce_robber", random(10)+10, me);
        current_job = 1;
    }
}

int introduce_robber(object current_player)
{
    object robber;

    if ( objectp(present(current_player->query("id"), this_object())) )
    {
        robber = new(__DIR__"npc/robber");
        robber->setup_robber(current_player->query("combat_exp"));
        robber->move(this_object());
        message_vision(HIC"一个$N急急忙忙走了过来。\n"NOR, robber);
        message_vision(HIR"$N说道：雪山的秃驴个个好色之极。快快走开，勿妨碍峨嵋师太清修！\n" NOR, robber, current_player);
        robber->start_checking(current_player);
    }
    else
    {
        reset_to_normal();
    }
}

int reset_to_normal()
{

   current_job = 0;
   return 1;

}
