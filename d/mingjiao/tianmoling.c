// Code of ShenZhou
// Room: /d/mingjiao/tianmoling.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "��Ħ��");
	set("long", @LONG
��������һ����ΰ�ĸ�ɽ��������ǿ�����겻�ϣ����Դ�ɽ��������
ƶ񤣬��ʯ����м�ֻ��ϡϡ����İ���ľ���Ӳݡ����൹�������дУ�
�γ��������ĶԱȡ���˵�˵ض������࣬����ͣ��̫�á�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"jxiaochang",
  "westup" : __DIR__"shangang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
