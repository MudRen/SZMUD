// Code of ShenZhou
// Room: /d/xixia/jiangjunfu.c

inherit ROOM;

void create()
{
	set("short", "�󽫾���");
	set("long", @LONG
�����������󽫾����������ĸ��ڣ��ڶ���ֵ����У�����������š�
һɫ���ܴ��ݣ�����Уξ����ȥ�뺷���£��˿����������ֵĿ����䵶��
����ǰ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jjdayuan",
  "north" : __DIR__"dongdajie",
]));
	set("objects", ([
		__DIR__"npc/xiaowei" : 2,
	]));
	
	set("outdoors", "xixia");

	setup();
}
int valid_leave(object me, string dir)
{
   if (dir =="south" ) {
        if (present("xiao wei", environment(me)))
                return notify_fail("Уξ��ס�����ȥ·��\n");
        }
   return ::valid_leave(me, dir);
}
