// Code of ShenZhou
// Room: /d/mingjiao/nvxiu.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "Ů����");
	set("long", @LONG
����������һ�����㣬����ǽ����һ����ľ��ױ̨������һԲ��ͭ����
�����Ǽ����ɴ�����ɴ���ڣ����������ھ��ޡ�������������Ů����Χ��
ľ��������Ц�����һλ��Ȼ����һ�죬��ͷЦ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"zoulang46",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
