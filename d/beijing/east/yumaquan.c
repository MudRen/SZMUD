//Cracked by Roath
// Room: /d/beijing/east/yumaquan.c

inherit ROOM;

void create()
{
	set("short", "����Ȧ");
	set("long", @LONG
���ǵ��������յ������Ȧ��Ȧ������֮�����ǧ��������
��ѡ�����ԣ�ƥƥ���������񾱡���ͦ���˻�����ס�������
�磬��һ�㷲����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wangfudajie2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
