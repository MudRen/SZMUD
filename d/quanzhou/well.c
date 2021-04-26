// Code of ShenZhou
// room: well.c
// Jay 4/8/96

inherit ROOM;

int do_use(string);
int do_zuan(string);

void create()
{
        set("short", "����");
        set("long", @LONG
������һ�ڿݾ��С����߼�����ʲôҲ�����塣
LONG
        );
	switch(random(2)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/spider" : 1]));
                break;
        case 1:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
	}
        set("exits", ([
                "up" : __DIR__"houyuan",
                "down" : __DIR__"well1",
        ]));

        set("no_clean_up", 0);

	set("cost", 2);
        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
             "���ȼ�˻��ۣ����־�������һ���ѷ죬�ƺ�������(zuan)��ȥ��\n"
             );
             this_player()->set_temp("marks/��1", 1);
             return 1;
       }
}

int do_zuan(string arg)
{
        object me;
        me = this_player();

        if (me->query_temp("marks/��1") ) {
            message("vision", me->name() + "����һ�²����ˡ�\n",
                    environment(me), ({me}) );
            me->move(__DIR__"midao");
            message("vision", me->name() + "�Ӿ������˳�����\n",
                    environment(me), ({me}) );
            this_player()->delete_temp("marks/��1");

            return 1;
        }
        else {
            write("�������Ķ���?!\n");
            return 1;
        }
}

