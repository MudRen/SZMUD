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
		"east" : __DIR__"maze3",
		"south" : __DIR__"maze41",
		"west" : __DIR__"maze39",
		"north" : __DIR__"maze61",
	]));

	set("item_desc", ([
	"shibei" : "
�����ڣ��ࡣ ��ڲ����ꡣ
�������ţ�������ͥ���޾̡�
�����Ŷ���������ͥ���ס�
��������������������������޾̡�
�������ģ����ڣ��ࡣ
�������壺�ʽڣ����������С�
������������ڣ����ף�������
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 60);
	check_count(me, 60);
	return;
}
