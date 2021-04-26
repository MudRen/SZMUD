// Code of ShenZhou
// Room: /d/dali/dinganfu6.c
#include "room.h"
inherit ROOM;

int do_find(string);
int do_find(string);

void create()
{
	set("short", "�ⷿ");
	set("long", @LONG
����ٸ��Ŀⷿ����������ͷ��ߵ���Ʒ������Ĺ�Ա�����˵ȿ��Ե�����
��ȡ���õ��������ߵ���Ʒ�������ſڵĵط���һ��С���ӣ��ܿ������������
��¼�͹���һ��С��(door)ͨ�����⡣
LONG);
	set("item_desc", ([
		"door" : "����һ��Сľ�š�\n",
        ]));	
	set("objects", ([
		"/kungfu/class/dali/guducheng" : 1,
		]));
	set("exits", ([
		"out" : __DIR__"dinganfu2",
		]));
	create_door("out","ľ��","enter",DOOR_CLOSED);
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
}
void reset()//make this room no refresh
{
	::reset();
	set("no_clean_up", 1);
}
void init()
{
	add_action("do_find", "find");
	add_action("do_drop", "drop");
}
int do_find(string arg)
{
	mapping log; 
	object ob,me=this_player(),room=find_object("/d/dali/dinganfu6.c");
	if (!arg
		|| (arg!="huachu"
		&& arg!="zhitao"
		&& arg!="guanxue"
		&& arg!="junfu"
		&& arg!="gangzhang"
		&& arg!="gangjian")) return notify_fail("��Ҫ��ʲô��\n");
	if (me->query("family/family_name")!= "����μ�" && !me->query("dali/employee"))
		return notify_fail("�����ϸ������߰ڷŵ����߰��㣬�㲻֪���Ӻ�����:(\n");
	if (ob=present(arg, me))
		return notify_fail("���������ϲ�����������������ỹ���ã��ܿⷿ�Ŀɶ������ġ�\n");
	if (arg=="huachu" || arg=="zhitao" || arg=="guanxue")
	{
		log = room->query_temp("tool");
		if (mapp(log) && log[me->query("id")])
			return notify_fail("��ղŲ������ù��ⶫ������������Ҫ�ˣ��ܿⷿ�Ĳ����Ӧ�ġ�\n");
		if (query("tool_count") >= 30)
			return notify_fail("�����˰��죬ʲôҲû�ҵ���\n");
		room->set_temp("tool/"+me->query("id"),1);
		ob=new(__DIR__"obj/"+arg);
		tell_object(me, "�����ҷ������ҵ���"+ob->name()+"��\n");
		ob->move(me);
		add("tool_count", 1);
		return 1;
	}
	if (arg=="junfu")
	{
		log = room->query_temp("junfu");
		if (mapp(log) && log[me->query("id")])
			return notify_fail("��ղŲ������ù��ⶫ������������Ҫ�ˣ��ܿⷿ�Ĳ����Ӧ�ġ�\n");
		if (query("junfu_count") >= 15)
			return notify_fail("�����˰��죬ʲôҲû�ҵ���\n");
		room->set_temp("junfu/"+me->query("id"),1);
		ob=new(__DIR__"obj/"+arg);
		tell_object(me, "�����ҷ������ҵ���"+ob->name()+"��\n");
		ob->move(me);
		add("junfu_count", 1);
		return 1;
	}
	if (arg=="gangzhang" || arg=="gangjian")
	{
		log = room->query_temp("weapon");
		if (mapp(log) && log[me->query("id")])
			return notify_fail("��ղŲ������ù��ⶫ������������Ҫ�ˣ��ܿⷿ�Ĳ����Ӧ�ġ�\n");
		if (query("weapon_count") >= 10)
			return notify_fail("�����˰��죬ʲôҲû�ҵ���\n");
		room->set_temp("weapon/"+me->query("id"),1);
		ob=new(__DIR__"obj/"+arg);
		tell_object(me, "�����ҷ������ҵ���"+ob->name()+"��\n");
		ob->move(me);
		add("weapon_count", 1);
		return 1;
	}
	return 0;
}
int do_drop(string arg)
{
	object ob,me=this_player(),room=find_object("/d/dali/dinganfu6.c");
	if ((me->query("family/family_name")!="����μ�"
		&& !me->query("dali/employee"))
		|| !arg
		|| !ob=present(arg,me)) return 0;
	if (arg=="huachu" || arg=="zhitao" || arg=="guanxue")
	{
		tell_object(me, "���"+ob->query("name")+"�Żؼ����ϡ�\n");
		destruct(ob);
		room->delete_temp("tool/"+me->query("id"));
		add("tool_count", -1);
		tell_object(me,"�ܿⷿ������ض�����˵�ͷ��\n");
		return 1;
	}
	if (arg=="junfu")
	{
		tell_object(me, "���"+ob->query("name")+"�Żؼ����ϡ�\n");
		destruct(ob);
		room->delete_temp("junfu/"+me->query("id"));
		add("junfu_count", -1);
		tell_object(me,"�ܿⷿ������ض�����˵�ͷ��\n");
		return 1;
	}
	if (arg=="gangzhang" || arg=="gangjian")
	{
		tell_object(me, "���"+ob->query("name")+"�Żؼ����ϡ�\n");
		destruct(ob);
		room->delete_temp("weapon/"+me->query("id"));
		add("weapon_count", -1);
		tell_object(me,"�ܿⷿ������ض�����˵�ͷ��\n");
		return 1;
	}
	return 0;
}
