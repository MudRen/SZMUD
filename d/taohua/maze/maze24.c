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
		"east" : __DIR__"maze46",
//		"south" : __DIR__"",
		"west" : __DIR__"maze19",
		"north" : __DIR__"maze27",
	]));

	set("item_desc", ([
	"shibei" : "
���������ࡣ �����޼��������޾̡� �����������������������������
�������ţ�����Զ����ֻ�ڣ�Ԫ����
�����������ݸ�������
����������Ƶ�������޾̡�
�������ģ����ж�����
�������壺�ظ����޻ڡ�
    �������Ը����ף�����������ʦ�����д�ܣ�����������ף�����
          ʮ�꣬��������
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 24);
	check_count(me, 24);
	return;
}
