// Code of ShenZhou
// Room: /d/newdali/baiyiminju.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����Ǵ����һ���壬���ɢ���ڲ�ɽ���������������������ʯ���ݳɣ�
��߷�񡣳��������죬�Ҽһ����������Ի�ľ�����ſڣ��ڴ��һ�����ġ���
ɽ����������Ұ���������ۻ��֡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dahejie1",
]));
set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/oldman" : 1,
  __DIR__"npc/miaonu2" : 2,
]));

	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
