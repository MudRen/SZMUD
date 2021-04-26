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
		"east" : __DIR__"maze57",
		"south" : __DIR__"maze3",
		"west" : __DIR__"maze61",
		"north" : __DIR__"maze51",
	]));

	set("item_desc", ([
	"shibei" : "
�����棺��������������󴨡�
�������ţ�����Ϊ������Ԫ�����޾̡�
��������������֮��ʮ��֮�긥��Υ�����꼪�� �������ڵۣ�����
������������֮�����£��޾̡� �������У��湫�ù硣
�������ģ����У��湫�ӡ� ����Ϊ��Ǩ����
�������壺���ڻ��ģ�����Ԫ���� ���ڻ��ҵ¡�
�����Ͼţ�Ī��֮�����֮��������㣬�ס�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 42);
	check_count(me, 42);
	return;
}
