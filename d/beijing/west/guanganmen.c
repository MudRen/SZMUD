//Cracked by Roath
// Room: /d/beijing/west/guanganmen.c

inherit ROOM;

void create()
{
	set("short", "�㰲��");
	set("long", @LONG
���Ǳ���������������г�����ĳ���--�㰲�ţ�����
�ĳ�ǽ����Ե���΢�ƾɣ��ر�Ҳ�����ڳ�ɭ�ϣ����Ͼ�����
�صأ����Ȳ������ؾ�����ȫ��������ѵ�����أ���֮һ����
�䣬����װ�������ö࣬����Ҳʤ��һ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanganmenlou",
  "east" : __DIR__"guangandajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
