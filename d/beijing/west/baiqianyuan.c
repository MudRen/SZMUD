//Cracked by Roath
// Room: /d/beijing/west/baiqianyuan.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
���ǰ׼Ҵ�լ��ǰԺ���ط���Ȼ���󣬵���ɨ��ʮ��
���࣬Ժ���м����ż����Ჱ������������Ѿ����˰ٶ�
���ˡ�Ժ���������᷿��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"lingtang",
	"south" : __DIR__"baidamen",
	"east" : __DIR__"baidongxiang",
	"west" : __DIR__"baixixiang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
