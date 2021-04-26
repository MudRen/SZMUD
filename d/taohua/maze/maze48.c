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
		"east" : __DIR__"maze29",
		"south" : __DIR__"maze18",
		"west" : __DIR__"maze3",
		"north" : __DIR__"maze57",
	]));

	set("item_desc", ([
	"shibei" : "
�����������ز��ľ�����ɥ�޵ã�������������������δ���پ�������ƿ��
        �ס�
�������������಻ʳ���ɾ����ݡ�
�����Ŷ����������֣��ͱ�©��
�������������Ͳ�ʳ��Ϊ�����������ü��������������丣��
�������ģ������ڣ��޾̡�
�������壺��������Ȫʳ��
����������������Ļ�������޼���
����  �� �� �� �� ��
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 48);
	check_count(me, 48);
	return;
}
