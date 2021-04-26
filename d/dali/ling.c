// Code of ShenZhou
// Room: /d/newdali/ling.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������к�÷���꣬���Ѱ�ʴ�ݾ��������Ƥ�����ʰ�쵣���
���ڵأ��������죬�罾�������壬���������������Ƭ�����
���巼Ϯ�ˣ���ֲ֪�Ժδ����ഫ��Ϊ��÷���ɻ�ȻҲ���������
����̶��
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"quan1",
		"south" : __DIR__"maze1",
		"southwest" : __DIR__"droad4",
		]));
	set("no_clean_up", 0);
       set("fjing", 2);

	setup();
	replace_program(ROOM);
}
