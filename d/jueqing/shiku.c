// Filename:   /d/jueqinggu/shiku.c ʯ��
// Jiuer, Aug 15, 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ʯ��");
	set("long",@LONG
���Ǹ���Ȼ���ɵ�ʯ�ߣ������ͷ�������и�Բ������Ĵ��
(hole)��ֻ���Ǵ�����һ�����ɣ����ڿ��д������У��������˾���
Ҳδ��������˭Ҫ�ǲ�С�Ĵӿ��е��˽������²����ٳ�ȥ��ʯ������
������������һ�ô���������Ƥ(shupi)�ִ��ֺ�
LONG);
	
	set("exits",([ 
		"east" : __DIR__"tongdao",])); 	
	
	set("objects", ([ 
		CLASS_D("jueqing") + "/qiu" : 1,  ]));
	
	set("item_desc", ([
		"hole" : HIW"�չ�ӿ���͸�������\n"NOR,
		"shupi" : "����(chop)�����Ƥ������(make)����������ȥ��\n"
		]));
	
	set("rope_count", 2);
	
	set("cost",2);
	setup();
}

void init()
{
	add_action("do_chop","chop");
	add_action("do_make","make");
	add_action("do_climb","climb");
}

int do_chop(string arg)
{
	object weapon, me = this_player();

	if( !arg || arg != "shupi")
		return notify_fail("��Ҫ��ʲô? \n");
	
	if( !objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("id") !="bishou")
		return notify_fail("����Ƥ����ð�ذ�ס�\n");
	
	if (query("rope_count") < 1)
		return notify_fail("�������Ƥ���������ˣ������ǳ�����ʱ�ٿ��ɡ�\n");
	
	me->receive_damage("jingli", 5);
	message_vision("$N�������еļһ�����ϰ���һЩ��Ƥ��\n", me);
	
	if ( random(10) >= 7) {
		write("����µ���Ƥ�ƺ��㹻��(make)һ������(rope)�ˡ�\n");
		me->set_temp("marks/��", 1);
	}
		me->start_busy(10);
		return 1;
}

int do_make(string arg)
{
	object ob, me = this_player();
	if( !arg || arg!="rope" )
		return notify_fail("��Ҫ����ô��\n");

	if( !me->query_temp("marks/��") )	
		return notify_fail("��Ҫ����ô��\n");

	write("�����������Ƥ����ʳ�����\n");
	me->delete_temp("marks/Ƭ");
	me->set_temp("marks/ok",1);	
	add("rope_count", -1);
	return 1;
}

int do_climb(string arg)
{
	object me = this_player();
	
	if ( !arg && arg != "up" && arg != "hole")
		return notify_fail("��Ҫ��ʲô��\n");
	
	if( !me->query_temp("marks/ok") )
		return notify_fail("��Ҫ��ʲô��\n");

	if ( arg == "up" || arg == "hole") {	
		message_vision("$N���������򶴿�������ȥ��\n", me);
		me->start_busy(10);
		me->move(__DIR__"liguifeng");
		me->delete_temp("marks/ok");
		message_vision("$N��������ش�ʯ��������������\n", me);
		return 1;
	}
    return 0;
}
