// Code of ShenZhou
// Room: /d/xiangyang/huajing.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ������������ʯ��С���ϣ����Ի�����ʢ�����Ż���
�������������أ�һƬ���ף��ϱ߾����Ứ԰��
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : -5 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"neitang",
  "south" : __DIR__"huayuan",
]));

	setup();
	replace_program(ROOM);
}
