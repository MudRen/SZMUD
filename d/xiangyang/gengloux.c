// Code of ShenZhou
// Room: /d/xiangyang/gengloux.c

inherit ROOM;

void create()
{
	set("short", "��¥��");
	set("long", @LONG
����һ���������ȥ��ͨ��¥�������ҷ���Щ�и�ʣ����һ�Լ���������
�����ż�������ɢɢ�����ˣ�����һ������ͷ��˯�����������������֣�û��
�������������
LONG
	);
        set("coordinates", ([ "x" : 1, "y" : 2 ]) );
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"genglou",
  "west" : __DIR__"beijie1",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
