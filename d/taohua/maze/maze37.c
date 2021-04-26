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
//		"east" : __DIR__"",
		"south" : __DIR__"maze63",
		"west" : __DIR__"maze59",
		"north" : __DIR__"maze55",
	]));

	set("item_desc", ([
	"shibei" : "
�������ˣ���Ů�ꡣ
�������ţ����мң�������
���������������죬���������꼪��
�������������ˡ��������������������������ߡ�
�������ģ����ң��󼪡�
�������壺�����мң���������
�����Ͼţ��������磬�ռ���
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
	
	me->add_temp("taohua/count", 37);
	check_count(me, 37);
	return;
}
