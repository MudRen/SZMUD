//ROOM damen.c

inherit ROOM;

void create()
{
	set("short", "����������");
        set("long",@LONG
�����ͨ�����չ����������Ĵ��š��������Ҹ���һͷʯ�������
���ߴ��������࣬��๾�צ���񿥷Ƿ��������������ƺ���ʱҪ�ڿն�ȥ��
LONG
	);
        set("outdoors", "lingjiu");
        set("exits", ([
		"north" : __DIR__"dating",
		"south" : __DIR__"dadao2",
        ]));

	set("objects",([
		CLASS_D("lingjiu") + "/meijian" : 1,
		CLASS_D("lingjiu") + "/lanjian" : 1,
	]));
	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("job_status")==1) 	
	return notify_fail
                ("������������Ҫ�Σ���������ְ�أ�\n");

	if (  (dir == "north")
           && ((string)me->query("family/family_name") != "���չ�")
	   && ( objectp(present("meijian", environment(me)))
	   ||   objectp(present("lanjian", environment(me))) ) )

	 return notify_fail
		("÷��˫�������ס�㣬˵�����������չ�������أ���\n");
	return ::valid_leave(me, dir);
}
void init()
{
        add_action("do_kill","kill");
        add_action("do_exercise", "exercise");
        add_action("do_exercise", "dazuo");
        add_action("do_exercise", "respirate");
        add_action("do_exercise", "tuna");
        add_action("do_exercise", "lian");
        add_action("do_exercise", "practice");
        add_action("do_exercise", "study");
        add_action("do_exercise", "du");
        add_action("do_exercise", "sleep");
}

int do_kill(string arg)
{
        object ob, ob1, ob2, me = this_player();

        if ( !arg || arg == "") return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;
        if ( ob->query("family/family_name") == "���չ�" && me->query("family/family_name") != "���չ�" ) {
           message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ\n", ob, me);

           if ( ob1=present("mei jian", environment(me)) ) {
                message_vision("$Nһ����Ц���󵨿�ͽ�����������չ�����ɱ�ˣ��������չ����۸�ô��\n", ob1);
                ob1->kill_ob(me);
           }
           if ( ob2=present("lan jian", environment(me)) ) {
                message_vision("$Nһ����Ц���󵨿�ͽ�����������չ�����ɱ�ˣ��������չ����۸�ô��\n", ob1);
                ob2->kill_ob(me);
           }
           if ( !ob1 ) return 0;
           if ( !ob2 ) return 0;
           return 1;
	} 
}

int do_exercise(string arg)
{
        object me = this_player();

	if ( me->query("job_status")==1)
        {
                tell_object(me, "�㻹��ר�����Űɣ�\n");
                return 1;
        }
        
        return 0;
}