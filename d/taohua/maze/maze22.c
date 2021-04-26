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
		"south" : __DIR__"maze36",
		"west" : __DIR__"maze4",
		"north" : __DIR__"maze63",
	]));

	set("item_desc", ([
	"shibei" : "
�����ڣ��ࡣ С����������
�������ţ�����ֺ���ᳵ��ͽ��
���������������롣
����������������磬���꼪��
�������ģ�������磬�����磬�˿ܻ��š�
�������壺������԰�������ꧣ��ߣ��ռ���
�����Ͼţ����ڣ��޾̡�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 22);
	check_count(me, 22);
	return;
}
