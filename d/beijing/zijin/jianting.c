//Cracked by Roath
// Room: /d/beijing/zijincheng/jianting.c

inherit ROOM;

void create()
{
	set("short", "��ͤ");
	set("long", @LONG
��������û��һ�ȴ���,�ϱ�������ʮ���ȸ�����,��Χ�ǿ�
���Ĺ㳡,������ϰ���������.�����ʿ����,�ʵ��ڴ��ļ���.ͤ
�ڶ������·���Ǭ¡.�ξ�ʥѵʯ��,ѵ������Ӱ�˼Σ,��������.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"guang4",
  "south" : __DIR__"gzxd3",
  "east" : __DIR__"yuchashanfang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
