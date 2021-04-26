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
		"east" : __DIR__"maze64",
		"south" : __DIR__"maze32",
		"west" : __DIR__"maze21",
		"north" : __DIR__"maze28",
	]));

	set("item_desc", ([
	"shibei" : "
��������Ԫ�����ࡣ
��������������ֺ�������񣬵�������ӣ��޾̡�
�����Ŷ�������ʵ���ҳ��м��������ܼ�������
��������������������������಻ʳ��������ڣ��ռ���
�������ģ������㣬�������������ף��ס�
�������壺���ƶ����磬���ꡣ
�����Ͼţ������磬�󼪣��޲�����
��  �� � �� ��  
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 50);
	check_count(me, 50);
	return;
}
