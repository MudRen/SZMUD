// Code of ShenZhou
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW"������Է"NOR);
	set("long", @LONG
�����ǡ����ݡ�������Է����һ���������ķ��䣬������Ե�ǽ
���Ϲ���һ��������д������(tiaofu)�������ϡ����ߵ��¶���ͨ��
�ɹ������ͥ԰��
LONG
	);
	set("exits", ([
		"east" : "/d/city/duchang",
		"north" : "/d/city/qiyuan2",
		"south" : "/d/city/qiyuan3",
		"west" : "/d/city/qiyuan4",
	]));
	set("objects", ([
		"/kungfu/class/misc/hezudao" : 1,
	]));
	set("item_desc", ([
		"tiaofu" : 
			"		��������������������������		\n"
			"		���������岻������ӡ�����		\n"
			"		�����������޻ش��ɷ������		\n"
			"		��������������������������		\n\n",
	]));
	set("cost", 1);
    setup();
}
