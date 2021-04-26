// Code of ShenZhou
// Room: 
// Date: 

inherit ROOM;

#include "/d/taohua/maze/maze.h"


void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ����ԼĪ���˶�ߵĴ�ʯ�鹹�ɵ���ʯ�󣬹�ģ�ƺ�����
��̧����ȥ�����ܾ������ص�������Ᾱ�ʯ����ȫ��������·ͨ��ʯ��
֮�⣬��֮���г�������������������������ͷ����ʯ������һ��б��
��ʯ��(shibei)�������ڸ����С�
LONG
	);

	set("exits", ([
		"east" : __DIR__"maze24",
//		"south" : __DIR__"",
		"west" : __DIR__"maze15",
		"north" : __DIR__"maze41",
	]));

	set("item_desc", ([
	"shibei" : "
�����٣�Ԫ���࣬�����ꡣ ���ڰ������ס�
�������ţ����٣��꼪��
�����Ŷ������٣����޲�����
�������������٣��������� ����֮���޾̡�
�������ģ����٣��޾̡�
�������壺֪�٣����֮�ˣ�����
�������������٣����޾̡�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 19);
	check_count(me, 19);
	return;
}
