//Cracked by Roath
// Room: /d/beijing/east/wangfudajie3.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
���Ƿ������ֵ�������֣���ֽ����������ˮ��������
����Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�С
�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : __DIR__"wangfudajie2",
	"east" : __DIR__"gongyuan",
	"west" : __DIR__"libu",
	"southwest" : "/d/beijing/zijincheng/dongchangan",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
