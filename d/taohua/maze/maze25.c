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
		"east" : __DIR__"maze44",
		"south" : __DIR__"maze17",
		"west" : __DIR__"maze10",
//		"north" : __DIR__"",
	]));

	set("item_desc", ([
	"shibei" : "
  ��������Ԫ���࣬�����ꡣ ��������򣬲�����������
�������ţ�������������
���������������񣬲����������������
��������������֮�֣���ϵ֮ţ������֮�ã�����֮�֡�
�������ģ����꣬�޾̡�
�������壺����֮������ҩ��ϲ��
�����Ͼţ���������������������
��  ��  �� ܳ ����

\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 25);
	check_count(me, 25);
	return;
}
