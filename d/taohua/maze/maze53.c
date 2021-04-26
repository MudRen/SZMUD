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
		"east" : __DIR__"maze61",
		"south" : __DIR__"maze39",
		"west" : __DIR__"maze20",
		"north" : __DIR__"maze62",
	]));

	set("item_desc", ([
	"shibei" : "
��������Ů�鼪�����ꡣ
�����������轥�ڸɣ�С���������ԣ��޾̡�
�����������轥���ͣ���ʳ����������
�����������轥��½���������������в������ף������ܡ�
�������ģ��轥��ľ������������޾̡�
�������壺�轥���꣬�����겻�У���Ī֮ʤ������
�����Ͼţ��轥���ӣ��������Ϊ�ǣ�����
��  �� �� �� �� �� ء
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 53);
	check_count(me, 53);
	return;
}
