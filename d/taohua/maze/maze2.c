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
		"east" : __DIR__"maze15",
//		"south" : __DIR__"",
		"west" : __DIR__"maze11",
		"north" : __DIR__"maze23",
	]));

	set("item_desc", ([
	"shibei" : "
��������Ԫ���࣬������֮�ꡣ ���������������Ժ�����������ϵ���
      ����ɥ�� ���꣬����
������������˪���������
����������ֱ�������󣬲�ϰ�޲�����
�������������¿��ꡣ ������£��޳����ա�
�������ģ����ң��޾̣�������
�������壺���ѣ�Ԫ����
����������ս���Ұ����Ѫ���ơ�
���������������ꡣ
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 2);
	check_count(me, 2);
	return;
}
