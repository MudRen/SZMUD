//Cracked by Roath
// Room: /d/beijing/east/guangqumen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǳ���������������г�����ĳ���--�����ţ�����
�ĳ�ǽ����Ե���΢�ƾɣ��ر�Ҳ�����ڳ�ɭ�ϣ����Ͼ�����
�صأ����Ȳ������ؾ�����ȫ��������ѵ�����أ���֮һ����
�䣬����װ�������ö࣬����Ҳʤ��һ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guangqudajie",
  "up" : __DIR__"guangqumenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
