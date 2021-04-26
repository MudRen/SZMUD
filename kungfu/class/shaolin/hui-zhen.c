// Code of ShenZhou
// Npc: /kungfu/class/shaolin/hui-zhen.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
int auto_perform();

void create()
{
	set_name("��������", ({
		"huizhen zunzhe",
		"huizhen",
		"zunzhe",
	}));
	set("long",
		"����һλ���ް߰׵���ɮ����һϮ�಼������ġ�������Ըߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 600);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 400000);
	set("score", 100);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 80);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("cuff", 70);
	set_skill("luohan-quan", 70);
        set_skill("club", 70);
        set_skill("weituo-gun", 70);
	set_skill("strike", 80);
	set_skill("sanhua-zhang", 80);
        set_skill("hand", 90);
        set_skill("qianye-shou", 90);
	set_skill("sword", 120);
	set_skill("damo-jian", 120);
	set_skill("parry", 80);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("club", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
        map_skill("hand", "qianye-shou");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");

	prepare_skill("hand", "qianye-shou");

        set_temp("apply/damage", 50);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 30);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	create_family("������", 38, "����");

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
	mapping mine;
	object me, room;

	me = this_player();

	::init();
	if (!mapp(mine = me->query("family"))) 
		return;

	if(!( room = find_object("/d/shaolin/cjlou")) )
	room = load_object("/d/shaolin/cjlou");
	
	if ( file_name(environment(this_object())) == "/d/shaolin/cjlou1" ){
	if( (mapp(mine = me->query("family")) && mine["family_name"] != "������")
	|| ((!present("daoyi chanshi", room)) && (!present("letter", me))))
	{
		  command("say �󵨿�ͽ������ɱ�˴���ؾ��󣬿���!\n");
	        //  call_out("kill_ob", 0, this_player()); 

	 	//  COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));  
                  kill_ob(this_player());
                  perform_action("sword.sanjue");

		  return;
	}
   }
	return;
}

int accept_kill(object ob)
{
	this_object()->kill_ob(ob);

	return 1;
}

int auto_perform()
{
        object me = this_object();
        object ob, weapon, target;
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

        if ( !objectp(target)) return 0;

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "sword" )
                        return perform_action("sword.sanjue");
        }
        if (!present("changjian", me)){
        ob = new("/d/shaolin/obj/changjian");
        ob->move(me);
        message_vision("$NͻȻת�������ó�һ��������\n", me);
        command("wield changjian");
        return 1;
        }
}
