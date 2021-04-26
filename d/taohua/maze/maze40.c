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
		"east" : __DIR__"maze55",
		"south" : __DIR__"maze59",
		"west" : __DIR__"maze32",
		"north" : __DIR__"maze64",
	]));

	set("item_desc", ([
	"shibei" : "
�����⣺�����ϣ������������������� ������������
�����������޾̡�
�����Ŷ�������������û�ʸ���꼪��
�������������ҳˣ��¿��������ߡ�
�������ģ����Ĵ������˹�ڡ�
�������壺����ά�н⣬����������С�ˡ�
���������������������ڸ�ܭ֮�ϣ���֮���޲�����
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 40);
	check_count(me, 40);
	return;
}
