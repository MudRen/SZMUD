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
		"east" : __DIR__"maze60",
		"south" : __DIR__"maze52",
		"west" : __DIR__"maze8",
		"north" : __DIR__"maze53",
	]));

	set("item_desc", ([
	"shibei" : "
����忣������ϣ������������������ˣ��꼪��
������������忣�������
���������������忣��˹�֮�ʡ�
�������������������
�������ģ����������
�������壺���������
���������������˶�������������ˡ�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 39);
	check_count(me, 39);
	return;
}
