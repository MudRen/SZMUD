// Code of ShenZhou
// zhu.c ����
// CLEANSWORD 1996/2/2
// Jay 9/11/96, added degree
//wzfeng 99/11/29 fixbug

#include <ansi.h>
inherit NPC;

string ask_degree();

void create()
{
	set_name("����", ({ "zhu xi", "zhu" }));
        set_color("$YEL$");
	set("long", "����������Ϊ������һ����ѧ�ң��������īˮ�Ⱥ���Ҫ�\n");
	set("gender", "����");
	set("age", 65);
        set("max_jing", 2000);
        set("max_qi", 2000);
  set_skill("literate", 800);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 140);
	set_temp("apply/defense", 140);
	set_temp("apply/damage", 30);

	set("combat_exp", 40000);
	set("shen_type", 1);

	set("inquiry", ([
		"ѧλ" : (:ask_degree:),
		"�ƾ�" : (:ask_degree:),
	]));

	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"����˵��������֮�£�Ī������������֮����Ī��������\n",
		"����˵���������ˣ�С�������ɣ����������δ������֮��\n",
		"����˵������ѧ֮�����������¡���������ֹ�����ơ� \n",
		"����˵����������֪���������ģ�������ң��ι�ƽ���¡�\n",
	}) );
       carry_object("/d/city/obj/cloth")->wear();

}

private void go_home()
{
	if( !living(this_object()) ) return;
        message_vision("$N��ɫ���ŵ��뿪�ˡ�\n", this_object());
        this_object()->move("/d/city/shuyuan");
	message_vision("$N�첽���˹�����\n", this_object());
}
	

void init()
{
        if( environment() != load_object("/d/city/shuyuan") ) {
		remove_call_out("go_home");
		call_out("go_home", 1);
	}
}	

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/��"))
		return 0; 
	ob->add_temp("mark/��", -1);
        if (ob->query("potential") > 1) ob->add("potential",-1);
	return 1;
}

int accept_object(object who, object ob)
{
        object wage;

        if (who->query_temp("biao/zhu") && ob->name()=="����") {
                who->delete_temp("biao/zhu");
		who->delete_temp("apply/short");
                command( "say ƫ����λ"+RANK_D->query_respect(who)+"�ˣ��������������ͷ�ʺá�");
                wage = new("/clone/money/silver");
                wage->set_amount(1);
                wage->move(who);
                message_vision("�����$Nһ��������Ϊ���ڵĳ��͡�\n", who);
                remove_call_out("destroy_it");
                call_out("destroy_it", 1, ob);
                return 1;
        }
	if (ob->query("id") == "hui mo") {
		command("jump");
		command("say ����֮�ˣ��������������Ҳ��");

		if (who->query("���Ǿ�") && !who->query("���Ǿ�/����")) {
	//		command("whisper " + who->query("id") +"�Ժ���"+
		tell_object(who, "�������ĸ����㣺�Ժ���"+
				"��������ѧ�Ҷ�������һ����������Ż�ֻ����"
			+"����������֪�����˶����ҾͲ����ˡ�\n");
			who->set("���Ǿ�/����",1);
		}	
		return 1;
	}

	if (who->query_temp("offend_zhu")) {
		message_vision("����ҡҡͷ��$N˵������ʦ������ľ���ɵ�Ҳ��\n", who);
		return 0;
	}
	if (who->query_skill("literate", 1) < 30){
		message_vision("����ҡҡͷ��$N˵������ȥ������������ѧѧʶ�֣��ٵ���������ɡ�\n", who);
		return 0;
	}
//add by wzfeng  
	if (environment() != load_object("/d/city/shuyuan")){
		message_vision("����Ц�Ŷ�$N˵����������Ժ�����Ұɣ�������ѧϰ����ĺõط���\n", who);
		return 0;
	}
	
	if (!(int)who->query_temp("mark/��"))
		who->set_temp("mark/��", 0);
	if (who->query_skill("literate", 1) < 60 
	&& ob->query("money_id") && ob->value() >= 100) {
		message_vision("����ͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
		who->add_temp("mark/��", ob->value() / 2);
		if (who->query("���Ǿ�/����")) 
                who->add_temp("mark/��", ob->value() / 2);
		return 1;
	}
	if (who->query_skill("literate", 1) >= 60
	&& who->query_skill("literate", 1) < 90
        && ob->query("money_id") && ob->value() >= 100) {
                message_vision("����ͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
                who->add_temp("mark/��", ob->value() / 5);
                if (who->query("���Ǿ�/����")) 
                who->add_temp("mark/��", ob->value() / 8);
                return 1;
        }
	if (who->query_skill("literate", 1) >= 90
	&& who->query_skill("literate", 1) < 120
        && ob->query("money_id") && ob->value() >= 100) {
                message_vision("����ͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
                who->add_temp("mark/��", ob->value() / 16);
                if (who->query("���Ǿ�/����"))
                who->add_temp("mark/��", ob->value() / 16);
                return 1;
        }
	if (who->query_skill("literate", 1) >= 120
        && ob->query("money_id") && ob->value() >= 100) {
                message_vision("����ͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
                who->add_temp("mark/��", ob->value() / 32);
                if (who->query("���Ǿ�/����"))
                who->add_temp("mark/��", ob->value() / 32);
                return 1;
        }
	return 0;
	//         ѧ�ѽ���Ϊԭ����1/50  (by Yujie)
}

void destroy_it(object obj)
{
        destruct(obj);
}

int accept_kill(object me)
{
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

string ask_degree()
{
     object me = this_player();

     string title,newtitle;
     int index,level;

     	title = me->query("title");
     	if (title) {
       		index = strsrch(title,"��");
		if (index>1) 
			title = title[0..(index-1)];
  		else if (index!=-1)
			return ("��ĳƺ�̫�֣���û���ġ�\n");
	}	
	me->set("title",title);

	level = me->query_skill("literate",1);
	if (level < 1 )
		newtitle = "��ä";
	else if (level < 10)
		newtitle = "ѧͯ";
	else if (level < 20)
		newtitle = "ͯ��";
	else if (level < 30)
		newtitle = "����";
	else if (level <40)
		newtitle = "���";
	else if (level < 50)
		newtitle = "����";
	else if (level <60)
		newtitle = "��Ԫ";
	else if (level < 70)
		newtitle = "��ʿ";
	else if (level < 80)
		newtitle = "��Ԫ";
	else if (level < 90)
		newtitle = "��ʿ";
	else if (level < 100)
		newtitle = "����ʿ";
	else if (level < 110)
		newtitle = "����";
	else if (level < 120)
		newtitle = "̽��";
 	else if (level < 130)
		newtitle = "����";
	else if (level < 140)
		newtitle = "״Ԫ";
        else if (level < 150)
                newtitle = "����";
        else if (level < 160)
                newtitle = "ѧʿ";
        else if (level < 170)
                newtitle = "�ڸ��ѧʿ";
        else if (level < 180)
                newtitle = "�ڸ��׸�";
        else if (level < 190)
                newtitle = "��̳����";
        else if (level < 200)
                newtitle = "��ѧ����ʦ";
	else newtitle = "ʥ��";

	if (title && title!="") title = title+"��" + newtitle;
	else title = newtitle;
//	me->set("title", title);

	title = title + " " + me->query("name") + 
		"(" + capitalize(me->query("id")) + ")";
	me->set_temp("apply/short", ({title}));

	return "ƾ���µ�ѧʶ�����Ϸ򿴣��������һ��"+newtitle+"��\n";
}

void unconcious()
{
        object obj, me = this_object();
        object ob = this_player();

	ob->delete_temp("mark/��");
	ob->set_temp("offend_zhu", 1);

	me->disable_player(" <���Բ���>");
	me->set("jing", 0);
	me->set("qi", 0);
	COMBAT_D->announce(me, "unconcious");

	call_out("revive", random(100 - query("con")) + 30);
}

varargs void revive(int quiet)
{
        remove_call_out("revive");
        while( environment()->is_character() )
                this_object()->move(environment(environment()));
        this_object()->enable_player();
        COMBAT_D->announce(this_object(), "revive");
}
