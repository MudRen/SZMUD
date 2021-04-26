// Code of ShenZhou
// Room: /d/village/eexit.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ǻ�ɽ���£���ȻԶ���سǣ�ȴû��ʲ��ɽ���ݿ��ڸ�����û��
������һ��С��ׯ�������������˼Ҳ��࣬�����ǹ����ճ������������
Ϣ��������������м��Ʒ��ӡ�������һ��Сɽ��
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	"east" :__DIR__"nwroad1",
	"north" : __DIR__"shack",
        "westup" : "/d/qilian/liupan",
]));
	
        set("objects", ([ __DIR__"npc/kid": 2 ]) );
        set("no_clean_up", 0);
        set("outdoors", "xx" );

	set("cost", 1);
        setup();
}
int valid_leave(object me, string dir)
{
    if ( dir == "westup" && me->query_condition("hz_job") )
           return notify_fail("����Ѳɽ���񣬲�������ְ�أ�\n");

    return ::valid_leave(me, dir);
}

