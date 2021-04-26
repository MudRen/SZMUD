// Code of ShenZhou
// Room: /d/xiangyang/shanfang.c
// xQin 2/00
inherit ROOM;

void create()
{
        set("short", "�ŷ�");
        set("long", @LONG
�������ŷ�������Ѿ���������ػصض��Ͳ��ȡ�����һ��ľ�������Ǵ�С�̵���
��ʢ�͵㣬���Ϳ����ڴ��ò�(serve) ����Щ�ҳ��ˡ�
LONG
	);
        set("exits", ([
                "west" : __DIR__"neitang",
        ]));

        set("no_fight", 1);
        set("ricewater", 30);
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("soup", me) || present("rice", me))
        return notify_fail("Ѿ������һ˫���ۣ��Բ���Ҫ�����߰���\n");
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_serve","serve");
}

int do_serve()
{
        object me;
        object food;
        object water;
        me=this_player();
        if(present("rice",this_player()) ) 
                return notify_fail("Ѿ���������������ã����˷�ʳ�\n");
        if(present("rice",this_object()) ) 
                return notify_fail("Ѿ���������������ã����˷�ʳ�\n");
        if (query("ricewater")>0)
        {
                message_vision("Ѿ����$Nһ������׷���һ��Ұ������\n",me);
                food=new(__DIR__"obj/rice");
                water=new(__DIR__"obj/soup");
                food->move(me);
                water->move(me);
                add("ricewater",-1);
        }
        else 
                message_vision("Ѿ����$NǸ����: �ˣ�������һ��������ɣ����˶��Թ��ˡ�\n",me);
        return 1; 

        setup();
        replace_program(ROOM);
}
