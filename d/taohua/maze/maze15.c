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
		"east" : __DIR__"maze19",
//		"south" : __DIR__"",
		"west" : __DIR__"maze2",
		"north" : __DIR__"maze52",
	]));

	set("item_desc", ([
	"shibei" : "
����ǫ���࣬�������ա�
����������ǫǫ���ӣ�����󴨣�����
������������ǫ���꼪��
������������ǫ���ӣ����ռ���
�������ģ��޲���������ǫ��
�������壺�����������ڣ������ַ����޲�����
������������ǫ��������ʦ�����ع���
����  �� �У�Ϊ
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 15);
	check_count(me, 15);
	return;
}
