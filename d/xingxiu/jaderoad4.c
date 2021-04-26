// Code of ShenZhou
// �����
// maco
#include <ansi.h>

inherit ROOM;
string look_long();

void create()
{
	set("short", "ͨ��");
	set("long", (: look_long :));

	set("exits", ([
		"north" : __DIR__"jaderoad5",
	]));
	set("item_desc", ([
	"door" : "ʯ���ϵ�������֮�����ۣ��������º�����ǰ�����������ż���\n",
	]));
	set("cost", 1);
	setup();
}

string look_long()
{
	string desc;
	desc = 
	"һ���������������ͨ����������ɢ���������Ǻ��ǡ�\n";
	if(!query("exits/out"))
	desc += "����һ����ʯ����(door)�ϵ������ۣ��߲���͹��\n";
	else desc +="������һ�����ŵ���ʯ���š�\n";
	return desc;
}


void init()
{
	add_action("do_push", "push");
	add_action("do_pull", "pull");
}

int do_push(string arg)
{
	object me, room;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg == "door") {
		if(query("exits/out")) {
			message_vision("$N˫�ֳ��ţ������ƶ���ʯ���š�ֻ����ߴߴ֮�����������һ�����죬ʯ�Ź����ˡ�\n", me );
			delete("exits/out");
			if( room = find_object(__DIR__"jaderoad3") ) {
			room->delete("exits/enter");
			message("vision", "ֻ����ߴߴ֮�����������һ�����죬ʯ���Ѵ�������˹��ϡ�\n", room );
			return 1;
			}
		}
		else {
			message_vision("$N˫�ֳ��ţ�����������ȥ��������ʯ������˿����������˫�ֹ�ͷ�ŵ���ʹ��\n", me);
			me->receive_wound("qi", 200 +random(10), "�����������������");
			me->receive_damage("qi", 220 + random(10), "�����������������");
	return 1;
		}
	}
	else return 0;
}

int do_pull(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg == "door") {
	
		if(query("exits/out"))
			return notify_fail("��ʯ�����Ѿ��ǿ��ŵ��ˡ�\n");

	message_vision("$N��Ҫ��ʯ������������ʯ����ȫ������֮����\n", me);
	return 1;
	}
	else return 0;
}
