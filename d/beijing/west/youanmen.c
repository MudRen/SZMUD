//Cracked by Roath
// Room: /d/beijing/west/youanmen.c

inherit ROOM;

void create()
{
	set("short", "�Ұ���");
	set("long", @LONG
���Ǳ���������������г�����ĳ���--�Ұ��ţ�����
�ĳ�ǽ����Ե���΢�ƾɣ��ر�Ҳ�����ڳ�ɭ�ϣ����Ͼ�����
�صأ����Ȳ������ؾ�����ȫ��������ѵ�����أ���֮һ����
�䣬����װ�������ö࣬����Ҳʤ��һ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"youanmenlou",
  "north" : __DIR__"youandajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
