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
		"east" : __DIR__"maze17",
		"south" : __DIR__"maze38",
		"west" : __DIR__"maze31",
		"north" : __DIR__"maze10",
	]));

	set("item_desc", ([
	"shibei" : "
�����ң��࣬���ꡣ
�������ţ��Ͷң�����
�����Ŷ����ڶң�����������
�������������ң��ס�
�������ģ��̶ң�δ�����鼲��ϲ��
�������壺���ڰ���������
�������������ҡ�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 58);
	check_count(me, 58);
	return;
}
