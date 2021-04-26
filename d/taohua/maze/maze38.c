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
		"east" : __DIR__"maze21",
		"south" : __DIR__"maze54",
		"west" : __DIR__"maze56",
		"north" : __DIR__"maze58",
	]));

	set("item_desc", ([
	"shibei" : "
�����С�¼���
�������ţ�������ɥ�������Ը����������޾̡�
�����Ŷ�����������޾̡�
��������������ҷ����ţ�������������棬�޳����ա�
�������ģ�£���Ԫ�򣬽��ڣ����޾̡�
�������壺�����������ɷ������ξ̡�
�����Ͼţ�£� ������Ϳ���ع�һ���� ����֮������˵֮�����˿ܻ�
          �ţ��������򼪡�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 38);
	check_count(me, 38);
	return;
}
