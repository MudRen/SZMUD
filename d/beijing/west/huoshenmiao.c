//Cracked by Roath
// Room: /d/beijing/west/huoshenmiao.c

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
	"west" : __DIR__"jingshanjie",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
