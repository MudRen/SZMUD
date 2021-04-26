// Code of ShenZhou
// Room: /d/xiangyang/bingying2.c

inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�������ڱ�Ӫ�У������������鵽�����ǹٱ���Ϊ��Ӧ����ʱ�������ɹŴ�
�������ڴ�ͷ�佫��ָ�����жӼӽ���������ǽ������������������ɫ����Ѱ��
�����ܡ�����ʿ�����������������Χ�˹��������ƿ�����̫�
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -2, "y" : -1 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"bydamen",
  "south" : __DIR__"lianwuc",
]));

	setup();
	replace_program(ROOM);
}
