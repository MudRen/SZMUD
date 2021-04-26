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
		"east" : __DIR__"maze16",
		"south" : __DIR__"maze9",
//		"west" : __DIR__"",
		"north" : __DIR__"maze14",
	]));

	set("item_desc", ([
	"shibei" : "
������׳�����ꡣ
�������ţ�׳��ֺ�����ף����ڡ�
�����Ŷ����꼪��
����������С����׳���������裬������ ���򴥷�������ǡ�
�������ģ��꼪����������������׳�ڴ���֮����
�������壺ɥ�����ף��޻ڡ�
�������������򴥷��������ˣ������죬�����������򼪡�
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
	
	me->add_temp("taohua/count", 34);
	check_count(me, 34);
	return;
}
