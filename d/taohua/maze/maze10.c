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
		"east" : __DIR__"maze25",
		"south" : __DIR__"maze58",
		"west" : __DIR__"maze33",
//		"north" : __DIR__"",
	]));

	set("item_desc", ([
	"shibei" : "
�����ģ��Ļ�β���������ˣ��ࡣ
�������ţ����ģ����޾̡�
�����Ŷ����ĵ�̹̹�������꼪��
���������������ӣ������ģ��Ļ�β�������ˣ��ס� ����Ϊ�ڴ����
�������ģ��Ļ�β�����ڡ����ռ���
�������壺�����ģ�������
�����Ͼţ����Ŀ��飬����Ԫ����
����  �� �� �� ��
���� �� ��˷ �� ����
����  �� Ȳ �� �� 
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 10);
	check_count(me, 10);
	return;
}
