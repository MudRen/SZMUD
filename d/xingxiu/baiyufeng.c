// Code of ShenZhou
// �����
// maco
#include <ansi.h>

inherit ROOM;
string look_cave();

void close_cave();

void create()
{
	set("short", HIW"�����ɽ��"NOR);
	set("long", @LONG
���ǰ�����ɽ����һ��͹�ң�ɽ�����ƺ��и�����(cave)��
LONG
	);

	set("exits", ([ ]));
	set("item_desc", ([
	"cave" : (: look_cave :),
	]));

	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
}


void init()
{
	add_action("do_dig", "dig");
	add_action("do_jump", "jump");
}

int do_dig(string arg)
{
	object me, room;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg == "cave" && !query("exits/enter")) {

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("����æ���ء�\n");

	message_vision("$N���ֽ�ץ�����һ��͹�������ң����ֲ�ȥɳ�ӣ������������ʯһ����������������档\n����һ�̣���յĶ����ѿ�����\n", me);

	me->add("jingli", -50);

	set("exits/enter", __DIR__"jadecave");
		if( room = find_object(__DIR__"jadecave") ) {
			room->set("exits/out", __FILE__);
			message("vision", "һ��ϤϤ�������������������˴�����Ѷ����ڿ��ˡ�\n",room );
		}
	remove_call_out("close_cave");
	call_out("close_cave", 10);
	return 1;
	}
	else return 0;
}

void close_cave()
{
	object room;

	if( !query("exits/enter") ) return;
	message("vision", "�����ú�¡����¡�����������ֱ����ˡ�\n", this_object() );
		delete("exits/enter");
	if( room = find_object(__DIR__"jadecave") ) {
		room->delete("exits/out");
		message("vision", "����ý���΢΢�𶯣����ú�¡����¡�����������ֱ����ˡ�\n", room );
	}
}

int do_jump(string arg)
{
	object me, weapon;
	string msg, type;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="down" )
	{
		if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("����æ���ء�\n");

		if(me->query("rided"))
		return notify_fail("����������������ɣ�\n");

		message_vision("$N�����������ɽ��������ȥ��\n", me);
		me->move("/d/xingxiu/gucheng5");
		message("vision", me->name() + "��ɽ������������\n", environment(me), ({me}) );

		if( me->query_skill("dodge") < 200 ) {
		message_vision("�������顱��һ����$Nˤ�˸��߻���ء�\n", me);
		me->receive_damage("qi", 50+random(20), "���°����ˤ����");
		}

		me->start_busy(1);
		return 1;

	}
	else return 0;
}	

string look_cave()
{
	if( !query("exits/enter") ) return "ɽ���϶��ڵĺۼ��������ԣ�ֻ�������¾ã������ѱ�ɳ�Ӷ��������������ڿ�(dig)��Щɰʯ��\n";
	else return "ɽ���ںڳ����ģ���ôҲ�Ʋ�����\n";
}
