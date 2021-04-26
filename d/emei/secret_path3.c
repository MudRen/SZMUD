// Code of ShenZhou
// /d/emei/secret_path3.c
// xbc 02/07/1997

inherit ROOM;

int do_use(string arg);
int do_zuan(string arg);

void create()
{
        set("short", "�ص�");
        set("long", @LONG
����һ���������ص���ֻ�м�յ�����ƣ����߼�����ʲôҲ�����塣
LONG
        );

        set("exits", ([
                "up" : __DIR__"secret_path2",
                "down" : __DIR__"secret_path4",
        ]));

        set("no_clean_up", 0);

	set("cost", 3);
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
             "���ȼ�˻��ۣ����ص�������һЩ��\n"
             );
             return 1;
       }
}

int do_zuan(string arg)
{
      object me;
      me = this_player();

      message_vision(
      "$N��ûͷ��Ӭһ�����ص���Ϲ�꣬���һͷײ��ǽ�ϡ�\n", this_player());
      if (random(2)==1) {
         write("��������κ����ģ��ƺ�ײɵ�ˡ�\n");
         if (me->query_skill("literate", 1) )
             me->set_skill("literate", me->query_skill("literate", 1)-1);
      }
      else {
         me->set("qi",10);
         me->unconcious();
      }
      return 1;
}

