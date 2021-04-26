// Code of ShenZhou
// Room: /d/xixia/ypgate.c

inherit ROOM;

void create()
{
	set("short", "һƷ�ô���");
	set("long", @LONG
����������һƷ�õ����ڵأ������ڶ���ֵı��棬��һ���ߴ��
ʯͷ����������ȥ���֮�����ſ���������ʿվ�ţ��Ȳ��ߴ�Ҳ���뺷��
�ͻʹ��ſڵ�������Զ�������Ǻ����ſڵ����۱�Ҳ���в��磬������
�����յ��������㲻�ѿ����������������ĸ��֣�˭��֪����һƷ��
�������¸���Ϊ����Ч����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dayuan",
  "south" : __DIR__"xidajie",
]));
	set("objects", ([
		__DIR__"npc/ypshi" : 4,
	]));
	set("outdoors", "xixia");
	set("cost", 1);

	setup();
}
int valid_leave(object me, string dir)
{
   if (dir =="north" ) {
        if (present("wu shi", environment(me))
	&& !me->query_temp("xixia/һƷ��") && me->query("yipin/done") < 10 ) 
                return notify_fail("һƷ����ʿ��ס�����ȥ·��\n");
	}
   return ::valid_leave(me, dir);
}

