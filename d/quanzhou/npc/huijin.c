// Code of ShenZhou
// huijin �۽�

inherit NPC;

string ask_me();

void create()
{
	set_name("�۽�����", ({ "hui jin", "hui", "jin" }));
	set("nickname", "��������");
//	set("long", 
//	");
	set("gender", "����");
	set("age", 38);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("int", 26);
	set("con", 15);
	set("dex", 19);
	
	set("max_qi", 520);
	set("max_jing", 500);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 5000);

	set_skill("force", 80);
	set_skill("dodge", 88);
	set_skill("parry", 100);
	set_skill("blade", 100);
	set_skill("strike", 85);
	set_skill("hand", 95);
	set_skill("claw", 80);
	set_skill("cuff", 95);
	set_skill("club", 50);
	set_skill("literate", 80);
	set_skill("xiuluo-dao", 100);
	set_skill("zui-gun",55);
	set_skill("shaolin-shenfa", 85);
	set_skill("jingang-quan", 90);
	set_skill("hunyuan-yiqi", 80);
	set_skill("buddhism", 85);

	map_skill("cuff", "jingang-quan");
	map_skill("force", "hunyuan-yiqi");
	map_skill("parry", "xiuluo-dao");
	map_skill("blade", "xiuluo-dao");
	map_skill("club", "zui-gun");
	map_skill("dodge", "shaolin-shenfa");
	
	prepare_skill("cuff", "jingang-quan");

	create_family("������", 38, "����");

	set("inquiry", ([
	    "����" : (: ask_me :),
	    "�ձ�����" : (: ask_me :),
	    "����" : (: ask_me :),
	    "��������" : "ƶɮ��ƽ��ʹ�����ܣ���������������ͬ������������������š�",
	]));

	setup();
	carry_object("/clone/weapon/jiedao")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
	object obj, me = this_object();

	::init();
	if( strsrch(file_name(environment()), "/d/quanzhou/") == -1 ) {
		message_vision("$N�첽���˹�����\n$N��ɫ���ŵ��뿪�ˡ�\n", me);
                this_object()->move("/d/quanzhou/ganlu");
		message_vision("$N�첽���˹�����\n", me);
		return;
	}
	else if( obj = present("lang ren", environment(me)) ) {
                call_out("kill_ob", 1, obj);
		call_out("checking", 1, me, obj);
		me->set_leader(0);
		if ( !me->query("said") ) message_vision("$N��ȵ���������ӣ��������ɣ�\n", me);
		me->set("said", 1);
		remove_call_out("home2");
	}
}

string ask_me()
{
        object me = this_object(), leader = this_player();

	me->set_leader(leader);

	message_vision("$N��Ȼ��ŭ��\n", me);
	call_out("home2", 100, me);
	return "�����ȥ��\n";
}

int accept_fight(object ob)
{
        object me = this_object();
        int my_max_qi = me->query("max_qi");

        if ( me->query("qi")*100 / my_max_qi <= 80 ) {
                call_out("checking1", 1, me, ob);
                return 0;
        }

        remove_call_out("checking");
        call_out("checking", 1, me, ob);

        return 1;
}

int accept_kill(object ob)
{
        object me = this_object();

	remove_call_out("checking");
        call_out("checking", 1, me, ob);

        return 1;
}

int checking(object me, object ob)
{
        int my_max_qi = me->query("max_qi");
        object weapon;

	if (me->query("said")) me->delete("said");

	if (me->is_fighting()) {
           if ( (me->query("qi")*100 / my_max_qi) <= 80 ) {
                command("exert recover");
           }

           call_out("checking", 1, me, ob);
           return 1;
        }

	if (!me->is_fighting()) {
		call_out("home", 1, me);
        }

	if(!objectp(ob) || !present( ob, environment())) {
		command("haha");
                message_vision("$NͷҲ���ص����ˡ�\n", me);
                me->move("/d/quanzhou/ganlu");
		return 1;
	}

	return 1;
}

int home(object me) 
{
	object obj;

	obj = present("lang ren", environment(me));
	if ( !obj && present("corpse", environment(me)) ) {
		command("haha");
                message_vision("$NͷҲ���ص����ˡ�\n", me);
                me->move("/d/quanzhou/ganlu");
        }
	else {
		kill_ob(obj);
		call_out("checking", 1, me, obj);
	}

	return 1;
}

int home2(object me)
{
	object obj;

	if ( !me->is_fighting() && !obj = present("lang ren", environment(me)) ) {
		message_vision("$N��ŭ˵�������Ǵ��ĸ�ƶɮ����Ц�ɣ���ô������ô�ö��������ձ����ˣ�\n", me);
		message_vision("$N���Ĺĵ����ˡ�\n", me);
		me->move("/d/quanzhou/ganlu");
	}

	return 1;
}
