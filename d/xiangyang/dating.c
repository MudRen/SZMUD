// Code of ShenZhou
// Room: /d/xiangyang/dating.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ����Ĵ���������ΰ��������ţ�����ͭ����������
�������ŷ硣����һ����̴ľ�������̹���ϸ�����Ǿ�Ʒ���ϱ�һ
�������ߵ�ֱͨ�����á�
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : -3 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"neitang",
  "out" : __DIR__"guofu",
]));

	setup();
	replace_program(ROOM);
}
