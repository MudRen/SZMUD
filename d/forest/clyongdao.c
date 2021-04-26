// Code of ShenZhou
// changle/clyongdao.c
// by aln 2 / 98

inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
��������ͨ��һ��ʯ�ң��Ա߱���ÿ����Զ����һյ�͵ƣ�ͷ
���Ǹ߸ߵĹ������Ե���Щ��ɭ�ɲ�������������������أ������˵�
��������ǰ����
LONG );

        set("exits", ([
	       "east" : __DIR__"clshishi",
	       "west" : __DIR__"clhuayuan",
        ]));

	set("cost", 0);

        set("objects",([
               __DIR__"npc/cl_bangzhong" : 1,
        ]));

        setup();

        // replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object ob;

        if( dir != "east" )
                 return ::valid_leave(me, dir);

        if( !(ob = present("changle bangzhong", environment(me))) )
                 return ::valid_leave(me, dir);

        if( !living(ob) )
                return ::valid_leave(me, dir);

        message_vision("$N����$n��ǰ��˵���������ǹ�Ѻ������ͽ�ĵط�������ذɡ�\n", ob, me);
        return notify_fail("");
}
