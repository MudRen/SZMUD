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
		"east" : __DIR__"maze7",
//		"south" : __DIR__"",
		"west" : __DIR__"maze24",
		"north" : __DIR__"maze18",
	]));

	set("item_desc", ([
	"shibei" : "
��������Ԫ�࣬�ü����ˣ���������������
�����������������󼪡�
�����Ŷ����������á����޾̡�
���������������ء�
�������ģ����ú����ɽ�����޾̡�
�������壺�꼪�����ס�
����������ڤ�������ڲ�Ϣ֮�ꡣ
��  �� �� �� ��
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 46);
	check_count(me, 46);
	return;
}
