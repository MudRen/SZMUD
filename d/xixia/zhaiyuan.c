// Code of ShenZhou
// Room: /d/xixia/zhaiyuan.c

inherit ROOM;

void create()
{
	set("short", "��լԺ");
	set("long", @LONG
���Ǹ������Ժ�ӣ�һɫ��ש�̵أ������Ƕ����᷿��ס��Ѿ�ߺ���
�ӣ����������������С¥��Ѿ���ǽ�����������æµ��
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yahuan" : 2,
]));
	set("cost", 1);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jjdayuan",
]));

	setup();
	replace_program(ROOM);
}
