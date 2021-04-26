// Code of ShenZhou
// Room: /d/shaolin/ruzhou.c

inherit ROOM;

void create()
{
	set("short", "���ݳ�");
	set("long", @LONG
���ݳ��Ǳ����Ĵ�ǣ������Ǳ��ұ���֮�ء��������ڴ�פ
���ر����̲��������������ˣ����������𸽽�ɽ�ϵĲݿܡ���
��һ�Ӷӹٱ�����ȥȥ��һ��ɭ������������������������֮
һ����ɽ��
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  "/d/city/npc/wujiang" : 1,
  "/d/city/npc/bing" : 3,
]));
	set("cost", 1);
	set("outdoors", "shaolin");
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : "/d/beijing/yidao1",
  "west" : __DIR__"shijie1",
  "south" : __DIR__"yidao3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
