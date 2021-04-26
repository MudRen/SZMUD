// Code of ShenZhou
// Room: /d/xiangyang/xijie1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����������ʯ������ٱ�ƵƵ����ΧѲ�ߡ���������ɭ�ϣ�����·��
���Կ첽�й�������ͣ�����ϱ��������������ź�֮����ԭ��������Ӫ���ϱ߿�
����һ�����ʵĹ�¥������ʾ���ټ���ʿ��
LONG
	);
        set("coordinates", ([ "x" : -1, "y" : 0 ]) );
	set("no_clean_up", 0);
	set("no_sleep_room", 1);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"guangc",
  "west" : __DIR__"xijie2",
  "south" : __DIR__"bydamen",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
