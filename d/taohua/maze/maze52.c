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
		"east" : __DIR__"maze41",
		"south" : __DIR__"maze15",
		"west" : __DIR__"maze23",
		"north" : __DIR__"maze39",
	]));

	set("item_desc", ([
	"shibei" : "
�����ޣ����䱳��������������ͥ���������ˣ��޾̡�
��������������ֺ���޾̣������ꡣ
���������������裬�������棬���Ĳ��졣
���������������ޣ�����⹣���޹�ġ�
�������ģ��������޾̡�
�������壺���丨�������򣬻�����
�����Ͼţ����ޣ�����
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 52);
	check_count(me, 52);
	return;
}
