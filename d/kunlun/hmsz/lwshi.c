// kunlun ��λ����
// by earl
inherit ROOM;
int do_use(string arg);
void create()
{
        set("short", "��λ����");
        set("long", @LONG
���ںڰ���ʲôҲ��������
LONG
);
set("invalid_startroom", 1);
        setup();
}
void init()
{
        add_action("do_use", "use");
}
int do_use(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire",me)) return 0;
        if( arg=="fire" ) {
        remove_call_out("close");
        call_out("close", 5, this_object());
             write(
"��ȡ������һ�Σ�����ǰȥ��ȼ�����е�һֻ��ѣ�Ҳ��֪��ʲô���ء�\n");
        set("long", @LONG
�����﹩�����Ŵ�ɽ����λ,��������һ�ж��Ǹղ��úõġ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"didao"+random(11),
                "south" : __DIR__"didao"+random(11),
                "east" : __DIR__"didao"+random(11),
                "west" : __DIR__"didao"+random(11),
        ]));
           if ( objectp(ob=present("fire", this_player())) )     {
            destruct(ob);
        return 1;
       }
        return notify_fail("�����ȼʲô��\n");
        }
}

void close(object room)
{
        message("vision","��һ�����ǽ�ϵĻ�Ѿ�Ϩ���ˡ�\n", room);
        set("long", @LONG
���ںڰ���ʲôҲ��������
LONG
);
        room->delete("exits");
}
