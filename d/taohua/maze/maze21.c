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
		"east" : __DIR__"maze50",
		"south" : __DIR__"maze51",
		"west" : __DIR__"maze38",
		"north" : __DIR__"maze17",
	]));

	set("item_desc", ([
	"shibei" : "
  ����ྣ��ࡣ ��������
�������ţ���У��ֺ���޾̡�
�����������ɷ���ǣ��޾̡�
���������������⣬������С�ߣ��޾̡�
�������ģ���Ǭ�����ý�ʸ�������꣬����
�������壺��Ǭ�⣬�ûƽ��������޾̡�
�����Ͼţ���У������ס�
��  �� �� �� � �� Ů
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 21);
	check_count(me, 21);
	return;
}
