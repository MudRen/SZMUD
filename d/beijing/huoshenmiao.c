//Cracked by Roath
// Room: /d/beijing/huoshenmiao.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�������ưܵĻ��������ۺ�������ӵĻ���ү��������
�С�����������ȥ���Կ�����¥����ŵ����޽���¥ʱ������֣���
��������������������ү���ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"out" : __DIR__"jingshan",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
