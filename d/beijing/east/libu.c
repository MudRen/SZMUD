//Cracked by Roath
// Room: /d/beijing/east/libu.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������֮�ף����ܹ������ѡ�Σ��ʶ�����Ӫ˽���֮
�����أ�ÿ�������ſڶ��ڸ��Ƽ��������ǹ�����Ϊ����ı��
��ӣ����ؽڡ������پ�֮�ࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"east" : __DIR__"wangfudajie3",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
