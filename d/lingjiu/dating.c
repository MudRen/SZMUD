//ROOM dating.c

inherit ROOM;

void create()
{
	set("short", "������");
        set("long",@LONG
����ǡ����չ���������������ȫ���Ծ�ʯ���ɣ�ʯ��֮�侹�ް��
��϶�����˳��档���ڴ������ĸ�ʯ������Ϊ��Ӳ�Ļ���ʯ���ơ�
LONG
	);
        set("exits", ([
		"north" : __DIR__"changl15",
		"south" : __DIR__"damen",
        ]));

	set("objects",([
		CLASS_D("lingjiu")+"/xuzhu" : 1,
	]));
	set("valid_startroom", 1);
	setup();
        "/clone/board/lingjiu_b"->foo();  
}
void init()
{
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" || arg == "xu") return 0;


        if ( !ob=present(arg, environment(me)) ) return 0;
        if ( ob->query("family/family_name") == "���չ�" && me->query("family/fa
mily_name") != "���չ�" ) {
           message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ\n", ob, me);

           if ( ob1=present("xu zhu", environment(me)) ) {
                message_vision("$Nһ����Ц���󵨿�ͽ�����������չ�����ɱ�ˣ��������չ����۸�ô��\n", ob1);
                ob1->kill_ob(me);
           }
           if ( !ob1 ) return 0;
           return 1;
	} 
}
