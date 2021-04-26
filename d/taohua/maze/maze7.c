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
		"east" : __DIR__"maze36",
//		"south" : __DIR__"",
		"west" : __DIR__"maze46",
		"north" : __DIR__"maze4",
	]));

	set("item_desc", ([
	"shibei" : "
����ʦ���꣬���ˣ����޾̡�
����������ʦ�����ɣ�����ס�
�����Ŷ�����ʦ�У����޾̣�����������
����������ʦ����ʬ���ס�
�������ģ�ʦ��Σ��޾̡�
�������壺�����ݣ���ִ�ԣ��޾̡�����˧ʦ��������ʬ�����ס�
������������������������мң�С�����á�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 7);
	check_count(me, 7);
	return;
}