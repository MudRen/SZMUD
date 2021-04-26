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
		"south" : __DIR__"maze49",
		"west" : __DIR__"maze6",
//		"north" : __DIR__"",
	]));

	set("item_desc", ([
	"shibei" : "
����ͬ�ˣ�ͬ����Ұ���ࡣ ����󴨣��������ꡣ
�������ţ�ͬ�����ţ��޾̡�
����������ͬ�����ڣ��ߡ�
����������������ç��������꣬���겻�ˡ�
�������ģ�����ܭ�����˹�������
�������壺ͬ�ˣ��Ⱥ�������Ц�� ��ʦ��������
�����Ͼţ�ͬ���ڽ����޻ڡ�
\n",
	]));

	set("cost", 10);
	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 13);
	check_count(me, 13);
	return;
}
