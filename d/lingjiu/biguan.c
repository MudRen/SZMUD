// ROOM : biguan.c
inherit ROOM;
void create()
{
  set("short","�չ���");
  set("long",@LONG
������ɽͯ�ѱչ������ĵط���ֻ��һ����Ľ�С, ò�紦�ӵ�ʮ��
�����Ů����ϥ�������������������µ���ɽͯ�ѡ�������������״���
�ӣ�ǧ��Ҫ���״����
LONG
    );
  set("exits",([
      "south" : __DIR__"men3",
     ]));
  set("objects",([
		"/kungfu/class/lingjiu/tonglao" : 1,
     ]));
 setup();
}
void init()
{
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" || arg == "tong lao") return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;
        if ( ob->query("family/family_name") == "���չ�" && me->query("family/fa
mily_name") != "���չ�" ) {
           message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ\n", ob, me);

           if ( ob1=present("tong lao", environment(me)) ) {
                message_vision("$Nһ����Ц���󵨿�ͽ�����ҵ����ҵ�������ɱ�ˣ��������չ����۸�ô��\n", ob1);
                ob1->kill_ob(me);
           }
           if ( !ob1 ) return 0;
           return 1;
} 
}