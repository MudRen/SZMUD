// Code of ShenZhou
// npc: /d/xingxiu/npc/alamuhan.c
// Jay 3/17/96

inherit NPC;

int ask_me();
int do_qiecuo();

void create()
{
        set_name("������", ({ "li wenxiu", "li", "wenxiu" }));
        set("long", "��һ����˵Ĵ�磬ȴ�Ǻ��˵�ģ����\n");
        set("gender", "Ů��");
        set("age", 17);

        set_skill("unarmed", 30);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("whip", 40);

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 20);

        set("combat_exp", 15000);
        set("attitude","friendly");
	set("horse_count", 1);
        set("inquiry", ([
		"�߲��չ�" : "��˵������ɽ�Ǳߡ�",
                "����׷" : (: ask_me :),
		"����" : (: ask_me :),
                "��" : (: ask_me :),
        ]) );

        set("shen_type", 1);
        setup();
        carry_object(__DIR__"obj/wcloth")->wear();
        carry_object(__DIR__"obj/changbian")->wield();
}

/*void init()
{
        ::init();
        add_action("do_qiecuo", "qiecuo");
}
*/
int ask_me()
{
        if ((int)this_player()->query_temp("marks/��")) {
                say(
"�������" + this_player()->name() + "˵�����⺢����ô�ϲ��ű����\n");
                return 1;
        } 
	
	if (query("horse_count") < 1){
                say(
"�������" + this_player()->name() + "˵������̫���ˣ����������ˣ���������������\n");
                return 1;
	}
	else{
        say(
"�����㿴��" + this_player()->name() + "һ�ۣ�˵����\n"
"������������ı޷�ҲС�е����������λ" + RANK_D->query_respect(this_player()) + "\n"
"�벻������д꼸��?\n");
        this_player()->set_temp("marks/��1", 1);
        return 1;
        }
}

int accept_fight()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        if( ob->query_temp("marks/��1") ) {
        say(ob->name() + "��������˵���ðɣ���" 
             "�Ҿ�ͬ���д꼸�аɣ��㵽Ϊֹ��\n");
          me->set_temp("challenger", ob);
          ob->set_temp("marks/��1", 0);
          return 1;
        }
        else
	  return 0;
}

int chat()
{
	object me = this_object();
	object ob = me->query_temp("challenger");
        object horse;
        int my_max_qi, his_max_qi;

	if( !objectp(ob) ) return ::chat();

        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if (me->is_fighting(ob)) return ::chat();
	
	me->delete_temp("challenger");
	
	if (me->is_fighting()) return ::chat();

        if ( !present(ob, environment()) ) return ::chat(); 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
                say(
                  "������˵����ԭ��ѧ��Ȼ��һ�㣬СŮ��ʮ���������Щ������ҲҪ����ԭȥ��\n"
                  "����һƥ�������Ա���ġ�\n"
                );
		horse = new("/clone/horse/yilima");
                horse->move("/d/xingxiu/saimachang");
		horse->set_lord(ob);
		horse->set_leader(ob);
                ob->set_temp("marks/��", 1);
                message_vision("$N����$nһƥ��\n", me, ob);
		add("horse_count", -1);
                return ::chat();
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                say(
                   "���������" + ob->name() + "Ʋ��Ʋ�죬˵������ԭ��ѧ������ˡ�\n"
                );
                message("vision",
                   ob->name() + "�������㹧�������ؿ���һ��ͷ���뿪������\n", environment(ob), ({ob}) );
                ob->move("/d/xingxiu/beijiang");
                message("vision",
                   ob->name() + "��������ͷɥ�����߻�����\n", environment(ob), ({ob}) );
                return ::chat();
        }
        return ::chat();
}
