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
		"east" : __DIR__"maze38",
		"south" : __DIR__"maze62",
		"west" : __DIR__"maze35",
		"north" : __DIR__"maze31",
	]));

	set("item_desc", ([
	"shibei" : "
�����ã�С�࣬���꼪��
������������������˹����ȡ�֡�
�����������ü��Σ������ʣ���ͯ���ꡣ
�����������÷���Σ�ɥ��ͯ�ͣ�������
�������ģ����ڴ��������ʸ������Ĳ��졣
�������壺����һʸ��������������
�����Ͼţ�����䳲��������Ц������� ɥţ���ף��ס�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 56);
	check_count(me, 56);
	return;
}
