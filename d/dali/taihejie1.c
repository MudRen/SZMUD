// Code of ShenZhou
// Room: /d/newdali/taihejie1.c

inherit ROOM;

void create()
{
	set("short", "̫�ͽֿ�");
	set("long", @LONG
������������ֱͨ�ʹ����ţ��Ǵ�����ڵ���Ҫ�ֵ���ͨ��ȫ����Ȼ��
�����ʯ�̳ɡ����ݰ����ۣ������������ﲻ����������һ�ɷ����Ļʳ�
����
LONG	);

	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"southgate.c",
  "north" : __DIR__"crossing.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}









