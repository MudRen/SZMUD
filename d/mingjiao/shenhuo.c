// Code of ShenZhou
// Room: /d/mingjiao/shenhuo.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�˷�������ƣ���ؼ�ʯ���г�ɫ���Ʋ����£��۶��ɺ������ս�Ǳ
֮ʱ������Ⱦ�죬��˷��໥���͡����÷嶥�������ݻ𺣡�Զ����ȥ��
����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shanlu76",
  "southdown" : __DIR__"shangang",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
