//Cracked by Roath
// xiakedao/ybting.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "ӭ����");
        set("long", @LONG
ʯ��·����һ��Сͤ��ͤ������һ��ʯ�����������š�ӭ������
�����֡��ּ���ʯ���֣�������������ָд���ġ�
LONG );

      set("exits", ([
		     "south" : __DIR__"xiaolu",
		     "north" : __DIR__"xiaolu2",
      ]));

        set("objects", ([ 
            __DIR__ + "npc/huashan" : 1,
      ]));
        set("outdoors", "xiakedao" );
        set("cost", 0);

//        "/clone/board/xkd_b"->foo();

        setup();
}
void init()
{     object greeter;
        object greeter2;
        string longdesc = "ʯ��·����һ��Сͤ��ͤ������һ��ʯ�����������š�ӭ������
�����֡��ּ���ʯ���֣�������������ָд���ġ�";
        object me = this_player();
        if (interactive(me)) 
        {       if ( (!(me->query("xkd/hosted") ) )&& (!(me->query_temp("xkd/guested"))) )
                {       longdesc += "һ����ͤ�ڵ�ͷ��\n��Щʲ�ᣬ�������æӭ�˹�����\n";
                        this_object()->set("long", longdesc);
                        greeter = present("long dizi", environment(me));
                        if (! (greeter) )
                        {       greeter = new(__DIR__"npc/longx.c"); 
                                greeter->set_temp("xkd/guest", getuid(me));
                                me->set_temp("xkd/guested", 1);
                        }
                        else
                        {       if ((string)greeter->query_temp("xkd/guest") != getuid(me))
                                {       greeter2 = new(__DIR__"npc/longx.c"); 
                                        greeter2->set_temp("xkd/guest", getuid(me));
                                        me->set_temp("xkd/guested", 1);
                                }
                        }
                        greeter->move(environment(me));
                }
        }

}

