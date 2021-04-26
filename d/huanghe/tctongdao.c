// Code of ShenZhou
// /d/huanghe/tctongdao.c

#define TIECHA "/d/huanghe/obj/tiecha"

inherit ROOM;

void create()
{
        set("short", "ͨ��");
        set("long", @LONG
һ��������ͨ������ǽ�ϵ���ţ�;����߳����ɣ��㼴ת�䡣����ͨ
��һƬ�ž����Ե�ʮ����ɭ�ɲ�������������������Ѳ�ߡ�
LONG );

        set("exits", ([
		"up"    : __DIR__"tckitchen",
		"north" : __DIR__"tcdating",
        ]));

    	set("cost", 1);

        set("objects",([
               __DIR__"npc/tc_bangzhong" : 1,
        ]));


        setup();

        // replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object ob, obj;

        if( dir != "north" )
                return ::valid_leave(me, dir);

        if( !(ob = present("tiecha bangzhong", environment(me))) )
                return ::valid_leave(me, dir);

        if( !living(ob) )
                return ::valid_leave(me, dir);

        if( me->query_temp("bangs/fam") == "�����"
        ||  me->query("fam") == "�����" )
                return ::valid_leave(me, dir);

        if( (obj = present("tie cha", me)) ) {
                message("vision", "����˵������������������������������\n", this_object());
                destruct(obj);
                return ::valid_leave(me, dir);
        }

        message_vision("$N����$n��ǰ��˵���������Ǳ����صأ���������\n", ob, me);
        return notify_fail("");
}

