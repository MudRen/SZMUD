//Cracked by Roath
// Room: /d/beijing/east/guozijianjie.c

inherit ROOM;

void create()
{
	set("short", "���Ӽ���");
	set("long", @LONG
���ǹ��Ӽ���Ĺ��Ӽ��֣����𾩳�������������
�Ĵ��������������Щ��·�����˴�����ʱ�򣬲���һ
�㷷������֮����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  	"north" : __DIR__"guozidamen",
	"west" : __DIR__"zhongtianlou",
	"east" : __DIR__"yonghegong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
