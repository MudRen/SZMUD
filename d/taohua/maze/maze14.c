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
		"east" : __DIR__"maze35",
		"south" : __DIR__"maze34",
//		"west" : __DIR__"",
		"north" : __DIR__"maze43",
	]));

	set("item_desc", ([
	"shibei" : "
�������У�Ԫ�ࡣ 
�������ţ��޽������˾̣������޾̡�
�����Ŷ��������أ����������޾̡�
�������������ú������ӣ�С�˸��ˡ�
�������ģ��������޾̡�
�������壺���ڽ��磬���磻����
�����Ͼţ�������֮�����޲�����
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 14);
	check_count(me, 14);
	return;
}
