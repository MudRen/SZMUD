// Code of ShenZhou
// Room: /d/xixia/xiaolou.c

inherit ROOM;

void create()
{
	set("short", "С¥");
	set("long", @LONG
����һ������¥��ľ�ƽ������˵��ǽ�̻Իͣ�������ǧ����������
ס������ײ���һ����س��������ɫ��Բ������¥�и�С��̨����¥
¥�������������������������⣬�ͻʳǴ��Ľ�ͬΪȫ�Ƕ��ɿ�����
������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"jjdayuan",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yahuan" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
