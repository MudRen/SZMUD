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
		"east" : __DIR__"maze63",
		"south" : __DIR__"maze4",
		"west" : __DIR__"maze48",
		"north" : __DIR__"maze59",
	]));

	set("item_desc", ([
	"shibei" : "
��������ϰ�������ڣ�ά�ĺ࣬�����С�
����������ϰ�������ڿ����ڣ��ס�
�����Ŷ��������գ���С�á�
������������֮���������������ڿ����ڣ����á�
�������ģ��׾���������󾣬��Լ��뻣����޾̡�
�������壺����ӯ��ֻ��ƽ���޾̡�
 �� ���������ûա��ۣ����ڴԼ������겻�ã��ס�
���� �� ��Ѩ �� ���� �� ��
���� �� �� �� ī
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 29);
	check_count(me, 29);
	return;
}
