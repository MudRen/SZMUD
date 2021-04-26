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
		"east" : __DIR__"maze4",
		"south" : __DIR__"maze46",
		"west" : __DIR__"maze27",
		"north" : __DIR__"maze48",
	]));

	set("item_desc", ([
	"shibei" : "
�����ƣ�Ԫ�࣬����󴨡� �ȼ����գ�������ա�
�����������ɸ�֮�ƣ����ӣ����޾̣����ռ���
�����Ŷ�����ĸ֮�ƣ������ꡣ
�����������ɸ�С�лޣ��޴�̡�
�������ģ�ԣ��֮�ƣ������ߡ�
�������壺�ɸ�֮�ƣ�������
�����Ͼţ���������������¡� 
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 18);
	check_count(me, 18);
	return;
}
