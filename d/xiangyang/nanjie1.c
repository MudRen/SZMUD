// Code of ShenZhou
// Room: /d/xiangyang/nanjie1.c

inherit ROOM;

void create()
{
	set("short", "�Ͻ�");
	set("long", @LONG
�������������Ͻ֣��˴��䱸ɭ�ϣ������в���������Ѳ�ߡ������ɼ���һ
���󸮣�ȴ�ǽڶȾ���������ڵ�Ԫ˧����·�ϵ����˴󶼴ҴҶ��������Ҿͽ�
ͣ������ȥ��Զ��һ���ϴ�Ĺ㳡���������������ġ�
LONG
	);
        set("coordinates", ([ "x" : 0, "y" : -4 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"nanjie2",
  "north" : __DIR__"guangc",
  "west" : __DIR__"ysfdamen",
]));
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
