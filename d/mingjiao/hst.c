// Code of ShenZhou
// Room: /d/mingjiao/hst.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "��ɽͤ");
	set("long", @LONG
���ʶ�����ɽ��Ȥ����Ŀϸ�������顱�����ɰ��ƣ��ް����ڣ�����
���������㵭Ȼ������ɽ����̧����ȥ��ɽ��ˮ������ľ�ڱ����������£�
�����أ�����أ��ڽ���һ�壬��Ҳ�ֲ�������ֻ�ŵ����ص����ֺ�һ˿
˿���㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xiaochang",
  "southeast" : __DIR__"qingyun",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
