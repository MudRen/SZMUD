// Code of ShenZhou
// Room: /d/xiangyang/huajing2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ������������ʯ��С���ϣ����Ի�����ʢ�����Ż���
�������������أ�����һƬ���ף�������һ�������᷿�������м�
Сի��
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 4, "y" : -6 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"huilang1",
  "south" : __DIR__"shuzhai",
  "west" : __DIR__"huayuan",
]));

	setup();
	replace_program(ROOM);
}
