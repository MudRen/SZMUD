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
		"east" : __DIR__"maze13",
		"south" : __DIR__"maze47",
		"west" : __DIR__"maze44",
//		"north" : __DIR__"",
	]));

	set("item_desc", ([
	"shibei" : "
�����ϣ����ڣ��ϡ� ���м��� ���ס� �������ˣ�������󴨡�
�����������������£�С���ԣ��ռ���
�����Ŷ��������ϣ�����ͣ����������ٻ�������
����������ʳ�ɵ£��������ռ���������£��޳ɡ�
�������ģ������ϣ����������尲�꣬����
�������壺��Ԫ����
�����Ͼţ�����֮�������ճ�����֮��

��  �� �ϰ� �¸�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 6);
	check_count(me, 6);
	return;
}
