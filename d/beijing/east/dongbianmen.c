//Cracked by Roath
// Room: /d/beijing/east/dongbianmen.c

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
  "up" : __DIR__"dongbianmenlou",
  "southwest" : __DIR__"guangqudajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
