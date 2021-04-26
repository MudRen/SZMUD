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
		"east" : __DIR__"maze51",
		"south" : __DIR__"maze61",
		"west" : __DIR__"maze62",
		"north" : __DIR__"maze38",
	]));

	set("item_desc", ([
	"shibei" : "
�������ã����ף���������
�������ţ�������淣������ģ�������
�����Ŷ��������ӣ�������֮�ꡣ
�����������������룬������淡�
�������ģ�������ڣ��ٹ���ʱ��
�������壺���ҹ��ã����֮�ǣ��������֮�������¼���������
����������Ů�п���ʵ��ʿ������Ѫ����������
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
	
	me->add_temp("taohua/count", 54);
	check_count(me, 54);
	return;
}
