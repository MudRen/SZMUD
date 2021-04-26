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
		"east" : __DIR__"maze20",
		"south" : __DIR__"maze5",
//		"west" : __DIR__"",
		"north" : __DIR__"maze34",
	]));

	set("item_desc", ([
	"shibei" : "
����С�󣺺ࡣ ���Ʋ��꣬����������
�������ţ����Ե�������̣�����
�����Ŷ���ǣ��������
������������˵�������޷�Ŀ��
�������ģ����ڣ�Ѫȥ������޾̡�
�������壺�������磬�������ڡ�
�����Ͼţ�����ȴ����е��أ��������� �¼������������ס�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 9);
	check_count(me, 9);
	return;
}
