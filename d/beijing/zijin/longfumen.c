//Cracked by Roath
// Room: /d/beijing/zijincheng/longfumen.c

inherit ROOM;

void create()
{
	set("short", "¡����");
	set("long", @LONG
�������Ӻ���������������һ����,���߾��ǽ�̩��,������ͨ��
��������ͨ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tongdao2",
  "east" : __DIR__"jiaotaidian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
