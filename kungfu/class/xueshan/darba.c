// Code of ShenZhou

inherit NPC;
int auto_perform();
int ask_me();
int do_qiecuo();

void create()
{
set_name("�����", ({ "darba", "dar", "ba" }));
        set("long",
"���ǽ��ַ����Ķ����ӣ��ѵ÷����塢�����洫��������������һ�����Ź��� \n"
"�����˵ã������θ��ݣ�ȴʹһ�������ĳߵĴ���ħ�ơ�\n");
        set("gender", "����");
        set("age", 35);
        set("attitude", "heroism");
        set("class","lama");
        set("inquiry",([
               "����"  : (: ask_me :),
                "���ַ���" : (: ask_me :),
        ]));

        set("shen_type", -1);
        set("str", 25);
        set("int", 27);
        set("con", 26);
	set("dex", 25);

        set("max_qi", 1500);
	set("qi", 1500);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 60);
        set("combat_exp", 250000);

        set_skill("force", 130);
        set_skill("dodge", 130);
        set_skill("parry", 130);
        set_skill("staff", 130);
        set_skill("hand", 130);
        set_skill("jingang-chu", 130);
        set_skill("dashou-yin", 130);
        set_skill("shenkongxing", 130);
        set_skill("longxiang-banruo", 130);

        map_skill("force", "longxiang-banruo");
        map_skill("parry", "jingang-chu");
        map_skill("staff", "jingang-chu");
        map_skill("hand", "dashou-yin");
	map_skill("dodge", "shenkongxing");

        prepare_skill("hand", "dashou-yin");

	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        setup();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
        if (clonep()) carry_object("/clone/weapon/xiangmo-chu");
//	if (ob = carry_object("/d/qilian/obj/xiangmo-chu")) //ob->wield();
}

/*void init()
{
        ::init();
        add_action("do_qiecuo", "qiecuo");
}
*/
int ask_me()
{
	if( this_player()->query("family/family_name") != "ѩɽ��"
        && this_player()->query("family/family_name") != "Ѫ����")
	return 0;

	if( !present("xiangmo chu", this_object())){
	say("�����ҡ��ҡͷ������û��������˵�ˣ��������������Ұɡ�\n");
	return 1;
	}

	if( this_player()->query("jlfw")){
	say("�����˵����ʦ��Ҫ��ʦ�������ҿ�û�á�\n");
	return 1;
	}

        say(
"����Ϳ���" + this_player()->name() + "һ�۲�м��˵��������ʦ�������ȹ���\n"
"��һ�أ���λ" + RANK_D->query_respect(this_player()) + "�ǲ����Ⱥ����д�һ�£�\n");
        this_player()->set_temp("marks/��1", 1);
        return 1;
}

int accept_fight()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        if( ob->query_temp("marks/��1") 
	&& present("xiangmo chu", me)) {
        say(ob->name() + "�Դ����˵���ðɣ���" 
             "�Ҿ�ͬ���д꼸�аɣ��㵽Ϊֹ��\n");
	  command("wield chu");
	  me->set_temp("challenger", ob);
          ob->set_temp("marks/��1", 0);
	  me->set("qi", (int)me->query("max_qi"));
	  me->set("eff_qi", (int)me->query("max_qi"));
	  me->set("neili", (int)me->query("max_neili"));
          return 1;
        }
        else
	  return 0;
}

int chat()
{
	object me = this_object();
	object ob = me->query_temp("challenger");
        int my_max_qi, his_max_qi;

	if ( !objectp(ob) ) return ::chat();

        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if (me->is_fighting(ob)) return ::chat();

	me->delete_temp("challenger");
        if ( !present(ob, environment()) ) return ::chat(); 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
	say(
                  "�����˵�������书ȷ�ǲ�һ�㣬����ʮ�������\n"
                  "�������������߰�ʮ���������ʮ�Ȼ����������ʮ�������������\n"
                  "��ʮ���ʦ���������Ǹ����Ĳ�ԭ�����ԡ�\n"
                );
                ob->set_temp("marks/��", 1);
		ob->set("jlfw", 1);
                return ::chat();
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                say(
	"����ͳ���" + ob->name() + "�ٺټ�Ц���������»��ǻ�ȥ��������ɡ�\n"
                );
                return ::chat();
        }
        return ::chat();
}
/* init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
	if (ob->query("shen") > 10000) 
                        remove_call_out("do_killing");
                        call_out("do_killing",4,ob);
			this_object()->kill_ob(ob);
                }
}
void do_killing(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        this_object()->kill_ob(ob);
}
*/
void attempt_apprentice(object ob)
{
        command("say  �����ɲ���������ͽ��");
        //command("recruit " + ob->query("id"));
}
int accept_kill(object me)
{
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	if (present("xiangmo chu", this_object())){
	command("wield chu");
	}
        kill_ob(me);
        return 1;
}
int auto_perform()
{
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if ( !objectp(weapon) ) {
        if ( present("xiangmo chu", me))
        command("wield chu");
        return 1;
        }
}
