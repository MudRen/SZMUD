// Code of ShenZhou
// Room: /d/qilian/lanzhou.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ��ǣ����������ľ������ģ�Ҳ���Ļ����ġ����ݵ��Ļ���
���ҷ�ɣ����д�ͳ���͡�����������Ӱ�죬Ҳ�лؽ̵�ͶӰ�����𾩳ǡ�
���ݣ�ϸ�����в��㣬������֮��ȴ�й�֮��
LONG
	);
	set("no_clean_up", 0);
	set("cost", 2);
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/xlama" : 1,
  "/d/taishan/npc/shu-sheng" : 1,
  "/kungfu/class/wudang/daotong" : 1,
]));
	set("outdoors", "qilian-shan");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"lanzhou-beimen",
  "east" : __DIR__"dangpu",
  "west" : __DIR__"weststreet",
  "south" : __DIR__"lanzhou-nanmen",
  "northeast" : __DIR__"biaoju",
]));

	setup();
	replace_program(ROOM);
}
