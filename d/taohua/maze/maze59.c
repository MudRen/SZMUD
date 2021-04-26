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
		"east" : __DIR__"maze37",
		"south" : __DIR__"maze29",
		"west" : __DIR__"maze57",
		"north" : __DIR__"maze40",
	]));

	set("item_desc", ([
	"shibei" : "
���������ࡣ ������������󴨣����ꡣ
����������������׳������
�����Ŷ������������������
�������������乪���޻ڡ�
�������ģ�����Ⱥ��Ԫ���� �����𣬷�����˼��
�������壺�������ţ������ӣ��޾̡�
�����Ͼţ�����Ѫ��ȥ�ѳ����޾̡�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 59);
	check_count(me, 59);
	return;
}
