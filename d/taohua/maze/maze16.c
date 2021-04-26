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
		"east" : __DIR__"maze62",
		"south" : __DIR__"maze20",
		"west" : __DIR__"maze34",
		"north" : __DIR__"maze35",
	]));

	set("item_desc", ([
	"shibei" : "
����ԥ����������ʦ��
������������ԥ���ס�
��������������ʯ�������գ��꼪��
������������ԥ���ڡ� ���лڡ�
�������ģ���ԥ�����еá����ɡ� ��������
�������壺�꼲���㲻����
����������ڤԥ�������壬�޾̡�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 16);
	check_count(me, 16);
	return;
}
