//Cracked by Roath
// Room: /d/beijing/west/xiaohutong2.c

inherit ROOM;

void create()
{
	set("short", "С��ͬ");
	set("long", @LONG
����һ���������Ｋ������С��ͬ����Ϊ�ش�ƫƧ����������
���࣬���Ͽ�����Ҳ��̫�ɾ���һ�йη�ͳ�������ϱ�������
�ġ���������¯��������ī�С�������ָ����С��ͬ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"nantianmen",
  "southwest" : __DIR__"shizilukou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
