// Code of ShenZhou
// Room: /d/qilian/gulang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���˳ǽ������ܣ��������䣬�������ں����������ˡ�����������������
ëƤ��ɢ�أ������������Ƥ����һ�����żҿڣ���һ�������ǹ����ˣ�����
������������ʮ������ˮ�Ӽ������ݡ�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/taishan/npc/dao-ke" : 1,
]));
	set("cost", 1);
	set("outdoors", "qilian-shan");
	set("exits", ([ /* sizeof() == 5 */
  "northeast" : "/d/xixia/dacaigou",
  "west" : __DIR__"xiaojiaqiao",
  "north" : __DIR__"sishu",
  "south" : __DIR__"yongdeng",
  "east" : __DIR__"fur-shop",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
