// Code of ShenZhou
// Room: /d/village/sexit.c

inherit ROOM;

void create()
{
        set("short", "�ϴ��");
        set("long", @LONG
�����ǻ�ɽ���£���ȻԶ���سǣ�ȴû��ʲôɽ���ݿ��ڸ�����û��������
һ��С��ׯ�������������˼Ҳ��࣬�����ǹ����ճ������������Ϣ���������
�������С���ӣ������ϻ�ɽ��ɽ·�ˡ�
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"sroad1",
        "south" : __DIR__"hsroad3",
]));
        
        set("objects", ([ __DIR__"npc/dog": 1,
                 ]) );
        set("no_clean_up", 0);
        set("outdoors", "village" );

        set("cost", 1);
        setup();
//      replace_program(ROOM);
}

void init()
{
        object me = this_player();

        if ( interactive(me) && me->query("huashan/job_pending") ) {
                me->set_temp("hz_job/sexit", 1);
        }
}

int valid_leave(object me, string dir)
{
    if ( dir == "south" && me->query_condition("hz_job") )
           return notify_fail("����Ѳɽ���񣬲�������ְ�أ�\n");

    return ::valid_leave(me, dir);
}
