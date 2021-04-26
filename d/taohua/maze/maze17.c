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
		"east" : __DIR__"maze28",
		"south" : __DIR__"maze21",
		"west" : __DIR__"maze58",
		"north" : __DIR__"maze25",
	]));

	set("item_desc", ([
	"shibei" : "
�����棺Ԫ�����꣬�޾̡�
�������ţ������壬�꼪�� ���Ž��й���
����������ϵС�ӣ�ʧ�ɷ�
����������ϵ�ɷ�ʧС�ӡ� ������ã������ꡣ
�������ģ����л����ס������ڵ����������ξ̡� 
�������壺���ڼΣ�����
������������ϵ֮���˴�ά֮�� ���ú�����ɽ��
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 17);
	check_count(me, 17);
	return;
}
