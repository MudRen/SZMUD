// Code of ShenZhou
// Room: /d/xiangyang/duofota.c

inherit ROOM;

void create()
{
	set("short", "�౦����");
	set("long", @LONG
����������һƽ̨���Ͻ�����С�������������������ȣ�������������ʮ��
�ף��²�Ϊ�˷����������Ͽ̸������Ĳ㣬��Ϊͭ�Ʊ��顢���ǣ�������������
öСͭ�壬�紵���죬�ö���������������Χ���������ܼ⡢���������ͤʽС
���������ھ��з���ͷ��񣬹���ʮ�˷���������
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -15, "y" : -4 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"guangde",
]));

	setup();
	replace_program(ROOM);
}
