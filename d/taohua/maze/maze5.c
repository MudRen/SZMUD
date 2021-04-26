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
		"east" : __DIR__"maze8",
		"south" : __DIR__"maze26",
//		"west" : __DIR__"",
		"north" : __DIR__"maze9",
	]));

	set("item_desc", ([
	"shibei" : "
�����裺���ڣ���࣬�꼪�� ����󴨡�
�������ţ����ڽ��� ���ú㣬�޾̡�
�����Ŷ�������ɳ�� С���ԣ��ռ���
���������������࣬�¿�����
�������ģ�����Ѫ������Ѩ��
�������壺���ھ�ʳ���꼪��
��������������Ѩ���в���֮������������֮�ռ���
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 5);
	check_count(me, 5);
	return;
}
