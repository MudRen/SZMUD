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
		"east" : __DIR__"maze33",
		"south" : __DIR__"maze45",
		"west" : __DIR__"maze1",
//		"north" : __DIR__"",
	]));

	set("item_desc", ([
	"shibei" : "
�����񣺷�֮���ˣ����������꣬����С����
������������é�㣬����⹣��꼪�ࡣ
�������������С� С�˼������˷�ࡣ
�������������ߡ�
�������ģ������޾̣�������
�������壺�ݷ񣬴��˼��� ����������ϵ�ڰ�ɣ��
�����Ͼţ�����ȷ��ϲ��
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 12);
	check_count(me, 12);
	return;
}
