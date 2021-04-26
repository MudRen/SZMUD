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
		"east" : __DIR__"maze40",
		"south" : __DIR__"maze57",
		"west" : __DIR__"maze51",
		"north" : __DIR__"maze50",
	]));

	set("item_desc", ([
	"shibei" : "
�����㣺�࣬�޾̣����꣬����������
�������������㣬���ף���������
�����Ŷ���������
����������������£����֮�ߣ����ߡ�
�������ģ������ݡ�
�������壺����£��꣬���˼��������ס�
������������㣬�ס�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 32);
	check_count(me, 32);
	return;
}
