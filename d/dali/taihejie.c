// Code of ShenZhou
// Room: /d/dali/taihejie.c

inherit ROOM;

void create()
{
	set("short", "̫�ͽֿ�");
	set("long", @LONG
������������ֱͨ�ʹ����ţ��Ǵ�����ڵ���Ҫ�ֵ���
ͨ��ȫ����Ȼ�Ĵ����ʯ�̳ɡ������������ﲻ����        
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"taihejie1.c",
  "south" : __DIR__"southgate.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
