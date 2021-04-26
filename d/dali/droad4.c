// Code of ShenZhou
// Room: /d/newdali/droad4.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ�������������ܵ���������
�˼�������Ω�����ߵ��·�棬΢�紵����Ҷ��ɳɳ���졣
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ling",
  "west" : __DIR__"southgate",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
