// Code of ShenZhou
// kufang.c
#include "room.h"
inherit ROOM;

int do_find(string arg);
int do_drop(string arg);

void create()
{
	set("short", "库房");
	set("long", @LONG
大理官府的库房，存放武器和防具等物品，大理的官员、差人等
可以到这里来取常用的武器工具等物品。靠近门口的地方有一张小桌
子，管库的人坐在那里记录和管理。一扇小门(door)通往室外。
LONG
	);

	set("exits", ([
		"out" : __DIR__"diziarea.c",
		]));
	set("item_desc", ([
		"door" : "这是一扇小木门。\n",
        ]));	

	set("objects", ([
		"/kungfu/class/dali/guducheng" : 1,
		]));

	create_door("out","木门","enter",DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_find", "find");
	add_action("do_drop", "drop");
}

int do_find(string arg)
{
	mapping log; 
	object ob,me=this_player(),room=find_object("/d/dali/kufang.c");

	if (!arg
		|| (arg!="huachu"
		&& arg!="zhitao"
		&& arg!="guanxue"
		&& arg!="junfu"
		&& arg!="gangzhang"
		&& arg!="gangjian")) return notify_fail("你要找什么？\n");

	if (me->query("family/family_name")!= "大理段家" && !me->query("dali/employee"))
		tell_object(me,"架子上各种器具摆放得乱七八糟，你不知道从何找起。:(\n");

	if (ob=present(arg, me))
		return notify_fail("你现在身上不是有这件东西吗，怎麽还想拿？管库房的可盯着你哪。\n");

	if (arg=="huachu" || arg=="zhitao" || arg=="guanxue") {
		//log = room->query_temp("tool");
		//if (mapp(log) && log[me->query("id")])
		//	return notify_fail("你刚才不是来拿过这东西了吗，怎麽又要了？管库房的不会答应的。\n");
                if (query("tool_count") >= 300)
			return notify_fail("你找了半天，什么也没找到。\n");
		room->set_temp("tool/"+me->query("id"),1);
		ob=new("/d/dali/obj/"+arg);
		tell_object(me, "你左右翻看，找到了"+ob->name()+"。\n");
		ob->move(me);
		add("tool_count", 1);
		return 1;
	}

	if (arg=="junfu") {
		log = room->query_temp("junfu");
		if (mapp(log) && log[me->query("id")])
			return notify_fail("你刚才不是来拿过这东西了吗，怎麽又要了？管库房的不会答应的。\n");
		if (query("junfu_count") >= 15)
			return notify_fail("你找了半天，什么也没找到。\n");
		room->set_temp("junfu/"+me->query("id"),1);
		ob=new("/d/dali/obj/"+arg);
		tell_object(me, "你左右翻看，找到了"+ob->name()+"。\n");
		ob->move(me);
		add("junfu_count", 1);
		return 1;
	}

	if (arg=="gangzhang" || arg=="gangjian") {
		log = room->query_temp("weapon");
		if (mapp(log) && log[me->query("id")])
			return notify_fail("你刚才不是来拿过这东西了吗，怎麽又要了？管库房的不会答应的。\n");
		if (query("weapon_count") >= 10)
			return notify_fail("你找了半天，什么也没找到。\n");
		room->set_temp("weapon/"+me->query("id"),1);
		ob=new("/d/dali/obj/"+arg);
		tell_object(me, "你左右翻看，找到了"+ob->name()+"。\n");
		ob->move(me);
		add("weapon_count", 1);
		return 1;
	}
	return 0;
}

int do_drop(string arg)
{
	object ob,me=this_player(),room=find_object("/d/dali/kufang.c");

	if ((me->query("family/family_name")!="大理段家"
		&& !me->query("dali/employee"))
		|| !arg
		|| !ob=present(arg,me)) return 0;
	if (arg=="huachu" || arg=="zhitao" || arg=="guanxue") {
		tell_object(me, "你把"+ob->query("name")+"放回架子上。\n");
		destruct(ob);
		room->delete_temp("tool/"+me->query("id"));
		add("tool_count", -1);
		tell_object(me,"管库房的赞许地对你点了点头。\n");
		return 1;
	}
	if (arg=="junfu") {
		tell_object(me, "你把"+ob->query("name")+"放回架子上。\n");
		destruct(ob);
		room->delete_temp("junfu/"+me->query("id"));
		add("junfu_count", -1);
		tell_object(me,"管库房的赞许地对你点了点头。\n");
		return 1;
	}
	if (arg=="gangzhang" || arg=="gangjian") {
		tell_object(me, "你把"+ob->query("name")+"放回架子上。\n");
		destruct(ob);
		room->delete_temp("weapon/"+me->query("id"));
		add("weapon_count", -1);
		tell_object(me,"管库房的赞许地对你点了点头。\n");
		return 1;
	}
	return 0;
}
