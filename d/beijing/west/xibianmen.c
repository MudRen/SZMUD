//Cracked by Roath
// Room: /d/beijing/west/xibianmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǳ��������Ůǽ�������ƫ�ţ��˴���ǽ���������
�����ĳ�ǽҪ�Ͱ�һЩ���ؾ�Ҳ���٣��̲�Ҳ�������������
��ô�������ߴ��ŵĴ������ˮ������ٳּ�ҵ֮�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"guangandajie",
  "up" : __DIR__"xibianmenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
