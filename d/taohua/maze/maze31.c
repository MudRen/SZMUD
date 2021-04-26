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
		"east" : __DIR__"maze58",
		"south" : __DIR__"maze56",
		"west" : __DIR__"maze45",
		"north" : __DIR__"maze33",
	]));

	set("item_desc", ([
	"shibei" : "
�����̣��࣬���꣬ȡŮ����
��������������Ĵ��
���������������裬�ף��Ӽ���
��������������ɣ�ִ���棬���ߡ�
�������ģ��꼪����������������Ӷ�˼��
�������壺��������޻ڡ�
�������������丨���գ��ࡣ
��  �� �� �� ÿ
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 31);
	check_count(me, 31);
	return;
}
