// Code of ShenZhou
// Room: /d/newdali/tusi3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������裬���³����ŵ����桢ì��ꪵȱ����������Ĵ�¥��
�£�������ʵ�����ÿ���ǰ�����һ�������������������Ϣ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tusi2",
]));
set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/datusi" : 1,
  __DIR__"npc/touren" : 2,
]));

	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
