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
		"east" : __DIR__"maze23",
		"south" : __DIR__"maze11",
//		"west" : __DIR__"",
		"north" : __DIR__"maze5",
	]));

	set("item_desc", ([
	"shibei" : "
    �������꣬����ʳ��������󴨡�
�������ţ��������ѡ�
�����Ŷ�����˵����
���������������������ꡣ Ի������������������
�������ģ�ͯ��֮����Ԫ����
�������壺����֮��������
�����Ͼţ�����֮�飬�ࡣ
��  �� �� �� ��

\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 26);
	check_count(me, 26);
	return;
}
