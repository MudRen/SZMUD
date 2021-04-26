// Code of ShenZhou
// ��ɽ��
// qfy 16/10/1996

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
����ɽ���ڵ�һ���ѷ����γɵ���խ������ʮ����Զ����������
����ͦ���������ߡ�����ͷת���ұߣ�ʹ���޷�Ԥ֪������ʲô��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"right" :  __DIR__"jinshe1",
		"out" : __DIR__"cliff",
	]));
	   
	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	object room1, room2;

	if ( present("skeleton", me) && dir == "out" )
		return notify_fail("������ź��ǵ��Ƕ�ȥѽ��\n");

	if ( !( room1 = find_object(__DIR__"jinshedong") ) )
		room1 = load_object(__DIR__"jinshedong");

	if ( !( room2 = find_object(__DIR__"jinshe1") ) )
		room2 = load_object(__DIR__"jinshe1");

	if ( dir == "out" && !me->query_temp("buried") && me->query_temp("visited") &&
	(present("skeleton", room1) || present("skeleton", room2) || present("skeleton", environment(me)) ) ) 
		call_out("poison", 10, me);

	me->delete_temp("buried");
	me->delete_temp("visited");

	return ::valid_leave(me, dir);
}

int poison(object me)
{
	tell_object(me, HIR "��һ����͸��������ԭ���ڽ��߶������˶������ڷ����ˣ�\n" NOR);
	me->receive_wound("qi", me->query("max_qi")+100, "������������");

	return 1;
}
