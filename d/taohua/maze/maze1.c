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
		"east" : __DIR__"maze12",
		"south" : __DIR__"maze43",
//		"west" : __DIR__"",
//		"north" : __DIR__"",
	]));

	set("item_desc", ([
	"shibei" : "
����Ǭ��Ԫ���࣬�����ꡣ

�������ţ�Ǳ�������á�
�����Ŷ�����������������ˡ�
������������������ǬǬ��Ϧ���������޾̡�
�������ģ���Ծ��Ԩ���޾̡�
�������壺�������죬�������ˡ�
�����Ͼţ������лڡ�
�����þţ���Ⱥ�����ף�����
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();

	me->add_temp("taohua/count",1);
	check_count(me,1);
	return;
}
