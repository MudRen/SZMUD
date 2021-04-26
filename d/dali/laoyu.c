// Code of ShenZhou
// Room: /d/newdali/laoyu.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "牢狱");
	set("long", @LONG
大理虽为蛮夷之地，然而百姓大多安守热业，少有犯事，因此牢狱里空空是
也，只有几个牢头在角落里自斟自饮。墙角上散散地扔着几把钥匙。
LONG
	);

	set("no_clean_up", 0);
	set("cost", 1);
set("objects", ([
     "/d/dali/npc/yuzu" : 1,
]));


	setup();
}
void init()
{
        object ob = this_player();

        if( (int)ob->query_condition("dali_jail") <= 0 )
        {
                message("vision",
                        HIY "只听牢房铁门匡地一响，一个昏昏沉沉的家伙被扔了进来！\n"NOR,
                        environment(ob), ob);

                tell_object(ob, "狱卒嘿嘿地笑着：今儿个你可落在我手里了...！\n");

                ob->apply_condition("dali_jail", 60);
        }
}
