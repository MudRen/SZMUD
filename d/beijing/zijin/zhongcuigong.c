//Cracked by Roath
// Room: /d/beijing/qianqing/jinghemen.c

inherit ROOM;

void create()
{
    set("short", "�Ӵ⹬");
	set("long", @LONG
������֮һ,�����������������Ǿ�ס�ĵط�.�̷�����ʱ����
ĸ��Тȫ�ɻʺ��ڴ˹���,�Ժ�Ȱ�̫��Ҳ����ס��.

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east"  : __DIR__"gzxd10",
  "west" : __DIR__"tongdao6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
