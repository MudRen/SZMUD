// Code of ShenZhou
// Room: /d/dali/tianlong6.c

inherit ROOM;

void create()
{
	set("short", "Сͤ");
	set("long", @LONG
����һ��СС�İ˽���ͤ��ͤ��ֻ��һ��ʯ��������ʯ�ʡ�
ͤ������վ�˸�����ɮ�ˣ���Ȼֻ�Ǳ�Ӱ, ���Ըе�һ������
��ѹ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tianlong2.c",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
