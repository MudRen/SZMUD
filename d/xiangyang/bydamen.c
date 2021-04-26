// Code of ShenZhou
// Room: /d/xiangyang/bydamen.c

inherit ROOM;

void create()
{
	set("short", "��Ӫ����");
	set("long", @LONG
����վ�ڱ�Ӫ���ſڣ�����һ���ŵ�Ӫ�������Կ��������Ʒ��Ĺٱ�������
�ӽ������ţ������治ʱ�����ź������ϰ������ǲ������ڴ˹ۿ��ģ���������
�鷳��øϿ��߿���
LONG
	);
	set("outdoors", "xiangyang");
	set("no_sleep_room", 1);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -1, "y" : -1 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"xijie1",
  "west" : __DIR__"bingy2",
  "south" : __DIR__"bingying",
]));

	setup();
	replace_program(ROOM);
}
