// Code of ShenZhou

inherit NPC;

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
                "���ַ���" : "��������ʦ����\n",
        ]));

        set("shen_type", -1);
        set("str", 25);
        set("int", 27);
        set("con", 26);
	set("dex", 25);

        set("max_qi", 800);
        set("max_jing", 450);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);
        set("combat_exp", 100000);

        set_skill("force", 90);
        set_skill("dodge", 90);
        set_skill("parry", 90);
        set_skill("staff", 90);
        set_skill("hand", 90);
        set_skill("jingang-chu", 100);
        set_skill("dashou-yin", 90);
        set_skill("xueshitiao", 100);
        set_skill("longxiang-banruo", 100);

        map_skill("force", "longxiang-banruo");
        map_skill("parry", "jingang-chu");
        map_skill("staff", "jingang-chu");
        map_skill("hand", "dashou-yin");
	map_skill("dodge", "xueshitiao");

        prepare_skill("hand", "dashou-yin");


        setup();
        carry_object("/d/qilian/obj/xiangmo-chu")->wield();
        carry_object("/d/qilian/obj/lamajiasha")->wear();	
}

/*void init()
{
        ::init();
        add_action("do_qiecuo", "qiecuo");
}
*/
int ask_me()
{
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

        if( ob->query_temp("marks/��1") ) {
        say(ob->name() + "�Դ����˵���ðɣ���" 
             "�Ҿ�ͬ���д꼸�аɣ��㵽Ϊֹ��\n");
	  remove_call_out("checking");
          call_out("checking", 1, me, ob);
          ob->set_temp("marks/��1", 0);
          return 1;
        }
        else
	  return 0;
}

int checking(object me, object ob)
{

        int my_max_qi, his_max_qi;
        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if (me->is_fighting()) 
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1; 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
	say(
                  "�����˵�������书ȷ�ǲ�һ�㣬����ʮ�������\n"
                  "�������������߰�ʮ���������ʮ�Ȼ����������ʮ�������������\n"
                  "��ʮ���ʦ���������Ǹ����Ĳ�ԭ�����ԡ�\n"
                );
                ob->set_temp("marks/��", 1);
                return 1;
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                say(
	"����ͳ���" + ob->name() + "�ٺټ�Ц���������»��ǻ�ȥ��������ɡ�\n"
                );
                return 1;
        }
        return 1;
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
