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
		"east" : __DIR__"maze53",
		"south" : __DIR__"maze8",
		"west" : __DIR__"maze9",
		"north" : __DIR__"maze16",
	]));

	set("item_desc", ([
	"shibei" : "
�����ۣ��¶����������ڡ�����
����������ͯ�ۣ�С���޾̣������ߡ�
�������������ۣ���Ů�ꡣ
���������������������ˡ�
�������ģ��۹�֮�⣬���ñ�������
�������壺�������������޾̡�
�����Ͼţ��������������޾̡�
��  �� خ �� ҳ
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 20);
	check_count(me, 20);
	return;
}
