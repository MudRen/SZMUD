// Code of ShenZhou
// Room: /d/dali/taihejie6.c

inherit ROOM;

void create()
{
	set("short", "̫�ͽֿ�");
	set("long", @LONG
������������ֱͨ�ʹ����ţ��Ǵ�����ڵ���Ҫ�ֵ���ͨ��
ȫ����Ȼ�Ĵ����ʯ�̳ɡ������������ﲻ�����ֵ�������Կ�
��һ�����ʯ����        
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taihejie5.c",
  "west" : __DIR__"shibei.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
