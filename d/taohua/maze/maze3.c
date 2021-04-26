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
		"east" : __DIR__"maze48",
		"south" : __DIR__"maze27",
		"west" : __DIR__"maze60",
		"north" : __DIR__"maze42",
	]));

	set("item_desc", ([
	"shibei" : "
�����ͣ�Ԫ���࣬�����꣬���ã��������������
�������ţ��ͻ��������꣬�����
����������������磬������硣 �˿ܻ��ţ�Ů���겻�֣�ʮ�����֡�
������������¹���ݣ�Ω�������У����Ӽ������ᣬ���ߡ�
�������ģ�������磬����ţ��޲�����
  �����壺����࣬С�꼪�������ס�
����������������磬��Ѫ���硣
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 3);
	check_count(me, 3);
	return;
}
