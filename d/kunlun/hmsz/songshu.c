// songshu.c (kunlun)

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�ó��������ϵ�����������֦��Ҷï�������ϳ�����̦�������Ҳ��������һͻ̨(tai)������������׵�ɽ�ȡ�
LONG
        );
        set("cost", 2);
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return 0;
        if( arg=="tai")
        {
        if (me->query_skill("dodge") < 40){
                    write("����ͼ����ͻ̨���������������ݣ�ֻ�����ա�\n");
                return 1;
                }
                else {
                    write("��һ����˳������������ͻ̨��\n");
                    message("vision",
                             me->name() + "һ����˳������������ȥ��\n",
                             environment(me), ({me}) );
//me->move( __DIR__"tutai" ); // where is tutai? mariner
                    message("vision",
                             me->name() + "����������������\n",
                             environment(me), ({me}) );
                return 1;
         }
     }
}
