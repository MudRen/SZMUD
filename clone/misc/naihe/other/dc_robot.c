// 机器人演示厅，给玩家挂机器人的。  ★dc_robot.c
// by naihe  2002-04-16  于茂名
// 请勿擅自更改本文件源码，谢谢！

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"机器人演示厅"NOR);
	set("long", "这里是宽敞而明亮的机器人演示厅，平时常会有些新的游戏机在上市之前到
这里来作一番演示。有几个客人在大厅四周的长椅子上坐着休息；在没有商家展
示作品的时候这里显得静悄悄的，让人感到一份意外的宁静。\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);

	set("objects", ([
	    __DIR__"obj/yizi" : 1,
	    ]));

	set("exits", ([
	    "east" : __DIR__"dc_dating",
	    ]));

	setup();
}

void init()
{
	add_action("do_skills",  "exercise");
	add_action("do_skills",  "dazuo");
	add_action("do_skills",  "respirate");
	add_action("do_skills",  "tuna");
	add_action("do_skills",  "practice");
	add_action("do_skills",  "lian");
	add_action("do_study",  "study");
	add_action("do_study",  "du");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
        add_action("do_food", "he");
}

int do_food(string arg)
{
	tell_object(this_player(), "吃喝请到二楼茶座。\n");
	return 1;
}

int do_skills(string arg)
{
	tell_object(this_player(), "新的机器人太神奇了！你看着看着忘记了练功。\n");
	return 1;
}

int do_study(string arg)
{
	tell_object(this_player(), "新的机器人太神奇了！你读着读着根本不知道自己在读什么。\n");
	return 1;
}
