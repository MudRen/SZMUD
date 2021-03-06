//                标准描述长度示例                                   |
// 为了减少房间出口数量而增添的通道  ★dc_tongdao.c

inherit ROOM;

void create()
{
	set("short", "小通道");
	set("long", "这是一条小通道，往西北回到赌场大厅，通道尽头是个洗手的地方，而别的
方向则各是几个玩游戏的单间。\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);

	set("exits", ([
	    "northwest" : __DIR__"dc_dating",
	    "adj":__DIR__"adj",
	    "bdj":__DIR__"bdj",
	    "cdj":__DIR__"cdj",
	    "north":__DIR__"dc_lav",
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
	add_action("do_skills",  "study");
	add_action("do_skills",  "du");
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
	tell_object(this_player(), "这里不是练功的地方。\n");
	return 1;
}

int do_study(string arg)
{
	tell_object(this_player(), "这里不是读书的地方。\n");
	return 1;
}
