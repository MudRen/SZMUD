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
		"east" : __DIR__"maze30",
		"south" : __DIR__"maze40",
		"west" : __DIR__"maze50",
		"north" : __DIR__"maze47",
	]));

	set("item_desc", ([
	"shibei" : "
����δ�ã��࣬С����ã����β����������
�������������β���ߡ�
�����Ŷ���ҷ���֣��꼪��
����������δ�ã����ף�����󴨡�
�������ģ��꼪�����������÷��������������ڴ����
�������壺�꼪���޻ڣ�����֮�⣬���ڣ�����
�����Ͼţ����������ƣ��޾̣�����ף�����ʧ�ǡ�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 64);
	check_count(me, 64);
	return;
}
