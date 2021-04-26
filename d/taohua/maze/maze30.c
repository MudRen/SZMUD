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
		"south" : __DIR__"maze55",
		"west" : __DIR__"maze64",
		"north" : __DIR__"maze49",
	]));

	set("item_desc", ([
	"shibei" : "
�����룺���꣬�ࡣ ����ţ������
�������ţ��Ĵ�Ȼ����֮�޾̡�
�������������룬Ԫ����
�������������֮�룬�������裬�����֮ൣ��ס�
�������ģ�ͻ�������磬���磬���磬���硣
�������壺���������������������
�����Ͼţ����ó������м����ף�����˳��޾̡�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 30);
	check_count(me, 30);
	return;
}
