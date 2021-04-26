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
		"east" : __DIR__"maze39",
		"south" : __DIR__"maze23",
		"west" : __DIR__"maze5",
		"north" : __DIR__"maze20",
	]));

	set("item_desc", ([
	"shibei" : "
�����ȣ����� ԭ��Ԫ���꣬�޾̡� ��������������ס�
�������������ڱ�֮���޾̡� ����ӯ󾣬��������������
������������֮���ڣ��꼪��
������������֮���ˡ�
�������ģ����֮���꼪��
�������壺�Աȣ�����������ʧǰ�ݡ� ���˲��룬����
������������֮���ף��ס�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 8);
	check_count(me, 8);
	return;
}
