//Cracked by Roath
// Room: /d/beijing/qianqing/jinghemen.c

inherit ROOM;

void create()
{
    set("short", "��Ǭ��");
	set("long", @LONG
���Ƕ�����֮һ��ԭ�������Ǿ�ס�ĵط������������������ᣬ
��δ���䡣�����ʱ���˾�ס����Щ�ط��Ѿ������˻ҳ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east"  : __DIR__"gzxd9",
  "west" : __DIR__"tongdao5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
