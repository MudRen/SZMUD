//Cracked by Roath
// Room: /d/beijing/zijincheng/jinghemen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������Ӻ������Ͷ�������һ����,���������Ͻ����е���������Ҳû
ʲô��ͬ�����߾��ǽ�̩��,������ͨ����������ͨ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jiaotaidian",
  "east" : __DIR__"tongdao5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
