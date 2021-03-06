// Code of ShenZhou
// path1.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "华山脚下");
	set("long", @LONG
这里是华山脚下，南面就是素有「奇峰天下第一山」的西岳华山，华
山由于远望宛如一朵白莲花，因而得名（古时，「华」与「花」通）。西
面有个小村庄，北边有几间房屋。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"hsstreet4",
  "north" : __DIR__"yuquan",
  "southeast" : __DIR__"shaluo",
]));
        set("no_clean_up", 0);
        set("outdoors", "huashan" );

	set("cost", 2);
        setup();
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
        message_vision(HIR"$N说道：你是不是在下刚才追丢的蒙面人？看你也不象什么好东西，不是的话快快走开！\n" NOR, robber, current_player);
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
