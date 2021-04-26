// Code of ShenZhou
// �����
// maco
#include <ansi.h>

inherit ROOM;
string look_stone();

void create()
{
	set("short", "�����ɽ��");
	set("long", @LONG
���ǰ������ϵ�ɽ����������ȥ������ʮ�߰��ɸߣ�����
����Զ�������Ϊ�͡���������఼͹��ƽ��ɽ��(stone)��
LONG
	);

	set("exits", ([
		"down" : __DIR__"jaderoom1",
	]));

	set("item_desc", ([
	"stone" : (: look_stone :),
	]));
	set("cost", 1);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_tie", "tie");
}

int do_climb(string arg)
{
	object me, room;

	room = load_object("/d/xingxiu/jaderoom1");
	me = this_player();
	
	if( !query("tied_stone") )  return 0;

	if( !arg || arg=="" ) return 0;

	if( arg == "up")
		return notify_fail("�������´�����ȴ������������������Ҳ���Ǹ���š�\n");
	if( arg == "down" )
	{

		if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("����æ���ء�\n");

		if(me->query("rided"))
		return notify_fail("����������������ɣ�\n");

		message_vision("$N��������������ȥ��\n", me);
		tell_object(room, me->name()+"������������������\n" );
		me->move(room);

		me->start_busy(1);
		return 1;

	}
	else return notify_fail("��Ҫ����������\n");
}	

int valid_leave(object me, string dir)
{
	object room;
	room = find_object("/d/xingxiu/jaderoom1");
	
	if(dir == "down") return notify_fail("�������̫�ߣ�ֱ������ȥ������û��������������ʲ�������ȥ�ɡ�\n");
	return ::valid_leave(me, dir);
}

int do_tie(string arg)
{
	object me, ob;
	me = this_player();

	if ( !arg || arg == "" ) return 0;
	
	if ( !objectp(ob = present("sheng zi", me)) ) return 0;

	if ( arg == "stone" ) {
		message_vision("$N������һ����ɽʯ�ϸ��Ρ�\n", me);
		set("tied_stone", 1);
		destruct(ob);
		}
		return 1;
	return 0;
}

string look_stone()
{
	if( !this_object()->query("tied_stone") ) return "��͹��ƽ��ɽ�ң������ͺͺ��ʲ��Ҳû�С�\n";
	else return "��͹��ƽ��ɽ�ң��������һ�����ӣ�Ҳ���������������(climb)ɽ�ڡ�\n";
}
