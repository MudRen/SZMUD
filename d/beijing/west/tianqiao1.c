//Cracked by Roath
// Room: /d/beijing/west/tianqiao1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǳ�����������ֵĵط������߻��ӣ����̾�������������
���������ܽ�������ģ�˵�鳪���ģ��ٻ�С�ԣ��������У�������
������Ի�������Ҳ������ز�¶����ʿ����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"chaguan",
	"north" : __DIR__"quanjude",
	"west" : __DIR__"caishikou",
	"east" : __DIR__"tianqiao2",
	]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
