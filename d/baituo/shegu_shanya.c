// Code of ShenZhou
// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�߹�ɽ��");
	set("long", @LONG
�����߹ȸߴ��Ķ��£����������ľ��Ҳ���Ӳݣ�һ�ɻ�������
��Ψ�з������ԣ����ϴӶ��ߺ�Х�������Ӹ����£���Ŀ����������
Զ��(view)����˷�������ɽ�����ơ�
LONG
	);

	set("exits", ([ 
	    "southdown" : __DIR__"shegu19",
	]));

	set("objects", ([
	    "/d/xueshan/npc/tuying" : 2,
	]));

	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

void init()
{
	add_action("do_view","view");
	add_action("do_view","tiaowang");
}

int do_view(string arg)
{
	object me = this_player(), room;
	string msg;

	if( !arg || arg=="" ) 
		return notify_fail( "��Ҫ���ĸ��������������Դ�ƽ��˸���λ��ѡ��\n");

	switch (arg) {
	case "north" :
	case "n" :
	msg = "��������Զ��������һƬ��ɽ���롣\n";
		break;

	case "south" :
	case "s" :
	msg = "�����Ϸ�Զ�����߹ȵ��ƾ�����ǰ������ңң�����ȿڡ�\n";

	room = load_object("/d/baituo/shegu1");
	if( room->query("defense") ) 
	msg += RED"�ȿ�������Ѫ��ɫ�Ķ������������\n"NOR;
	else msg += HIW"ԭ�������ܲ��Ĺȿڣ���ʱȴ��Ȼ���ʣ����е���������Ӱ�����ˡ�\n"NOR;
		break;

	case "east" :
	case "e" :
	msg = "��������Զ������Խ��һƬ�������ᣬ���ǻ�ɳçç�Ĵ�Į��\n";
		break;

	case "west" :
	case "w" :
	msg = "��������Զ�������������߹���ľ��\n";
		break;

	case "northeast" :
	case "ne" :
	msg = "��������Զ��������һƬ��ɽ���롣\n";
		break;

	case "northwest" :
	case "nw" :
	msg = "��������Զ��������Զ��ɽ������ɼï�ܣ�������죬һ�����ٲ����ڶ��£�����׳�ۡ�\n";

	room = load_object("/d/baituo/shegu27");
        if( present("dang gui", room) ) 
	msg += HIW"һ����ȥ������ñ˶�ɽ�У����й�����������������\n"NOR;
	else if( present("pusiqu she", room) ) 
	msg += HIR"��ң��ɽ�о�ɫ����Ȼ������Щ�ľ��������ٶ�����ȥ��Խ��Խ���ò��Ծ���\n"NOR;
	else msg += "�����еع�����ɽ�����������������˲��١�\n";
		break;

	case "southeast" :
	case "se" :
	msg = "��������Զ������Խ��һƬ�������ᣬ���ǻ�ɳçç�Ĵ�Į��\n";
		break;

	case "southwest" :
	case "sw" :
	write("��������Զ�������������߹�������ġuħ��̲�v�ش�����\n\n");
	room = load_object("/d/baituo/shegu32");
	COMMAND_DIR"std/look"->look_room(me, room);
	msg = "����������Զ�����ǾӸ����£��������������\n";
		break;

	default:
		return notify_fail( "��Ҫ���ĸ��������������Դ�ƽ��˸���λ��ѡ��\n");
	}
	write(msg);
	return 1;
}
