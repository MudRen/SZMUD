// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;

void create()
{
        set("short", "���˶�");
        set("long", @LONG
��������߳ߣ�������߰������㿴�����Ƿ������κ�
���ֻ�ж��ڶ��Ű�����ߵ�ɽ��ࡣ
LONG
        );
        set("exits", ([
                "down" : __DIR__"xrdong",
        ]));

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

"���ȼ�˻��ۣ���������ʯ������һ���ѷ죬�ƺ�������(zuan)��ȥ��\n");
        this_player()->set_temp("marks/��", 1);
             return 1;
       }
}

int do_zuan(string arg)
{
        object me = this_player();
        
        if (me->query_temp("marks/��") ) {
/*        if(me->query_encumbrance() * 10 / me->query_max_encumbrance() >
10/100)
                return notify_fail("��Я����̫�ණ�����겻��ȥ��\n");
*/
        message("vision", me->name() +
"����һ�²�֪��ʲô�ط����ȥ�ˡ�\n",
                    environment(me), ({me}) );
            me->move("/d/xingxiu/icecave1");
            message("vision", me->name() + "��ʯ�������˳�����\n",
                    environment(me), ({me}) );
            this_player()->set_temp("marks/��", 0);
        return 1;
        }
        else {
            write("�������Ķ���?!\n");
            return 1;
        }
}

