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
//		"east" : __DIR__"",
		"south" : __DIR__"maze30",
		"west" : __DIR__"maze47",
		"north" : __DIR__"maze13",
	]));

	set("item_desc", ([
	"shibei" : "
������������ڣ�Ԫ�����꣬������
�������ţ����û�ţ֮�
���������������˸�֮���������޾̡�
�������������ף��������������ͣ����ڡ�
�������ģ����������ڸ���������
�������壺���˻��䣬δռ���ڡ�
�������������ӱ��䣬С�˸��棬���ף����꼪��
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 49);
	check_count(me, 49);
	return;
}
