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
		"east" : __DIR__"maze22",
		"south" : __DIR__"maze7",
		"west" : __DIR__"maze18",
		"north" : __DIR__"maze29",
	]));

	set("item_desc", ([
	"shibei" : "
�����ɣ��ࡣ ������ͯ�ɣ�ͯ�����ҡ� ���ɸ棬�����£����򲻸档��
����    �ꡣ
�������������ɣ��������ˣ���˵�����������ߡ�
�����Ŷ������ɼ����ɸ������ӿ˼ҡ�
��������������ȢŮ������򣬲��й�����������
�������ģ����ɣ��ߡ�
�������壺ͯ�ɣ�����
�����Ͼţ����ɣ�����Ϊ�ܣ������ܡ�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 4);
	check_count(me, 4);
	return;
}
