//Cracked by Roath
// Room: /d/beijing/west/bingqipu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�侩���ﳣ���ı����̣���������̫ƽ��������
������Ҳ�嵭�˲��٣����Ա�����Ҳ��ӪЩ�ճ�����������
�������ӽ��£����ﶫ��������������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"tianqiao4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
