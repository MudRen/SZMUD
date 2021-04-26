// Code of ShenZhou
// azi.c ����
#include "/kungfu/class/xingxiu/auto_perform.h"
inherit NPC;
inherit F_MASTER;
int do_incense();
int auto_perform();
void create()
{
	set_name("����", ({ "azi" }));
	set("nickname", "������Сʦ��");
	set("long", 
		"�����Ƕ�������Ӱ��ϡ�\n"
		"������������������������͸��һ��а����\n");
	set("gender", "Ů��");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 24);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 10);
	set("combat_exp", 50000);
	set("score", 10000);
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	set("inquiry", ([
                "��" : (: do_incense :),
                "����" : (: do_incense :),
        ]) );


	set_skill("force", 40);
  	set_skill("huagong-dafa", 25);
	set_skill("dodge", 30);
	set_skill("feixing-shu", 60);
	set_skill("poison", 40);
	set_skill("zhaixinggong", 40);
	set_skill("claw", 40);
	set_skill("sanyin-zhua", 40);
	set_skill("strike", 30);
	set_skill("chousui-zhang", 40);
	set_skill("parry", 20);
	set_skill("staff", 20);
  	set_skill("literate", 30);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-zhua");
	map_skill("parry", "chousui-zhang");

	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-zhua");

	create_family("������", 2, "����");

	setup();
	carry_object("/d/xingxiu/obj/xxqingxin-san");
	carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
	carry_object("/d/xingxiu/obj/blzhen");
	carry_object("/d/xingxiu/obj/lianxin");
}

void attempt_apprentice(object me)
{
	if( me->query("family/family_name") == "ؤ��"
        && me->query("combat_exp") >= 10000 ) {
		command ("say ����������޽л��ӣ��ҿɲ������㡣");
                return;
	}
	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + me->query("id"));
}
int do_incense()
{
	if( this_player()->query("family/family_name") != "������"){
        say("���Ϻ���һ��˵���ⶫ���ɲ��Ǹ����õġ�\n");
        return 1;
        }
	if (//this_player()->query("marks") == "����˿"||
	this_player()->query("marks") == "���ߵ�"||
	this_player()->query("marks") == "����"||
	this_player()->query("marks") == "ɳ���"||
	this_player()->query("marks") == "Ы�ӿ�") {
	say("���ϲ��ͷ���˵�����Ҳ��ǽ���ȥ��" +this_player()->query("marks")
	+ "���𣿶��������͸��㡣\n");
	return 1;
	}
	switch( random(4) )//�ĳ�4�ˣ�������5 troy 2001.12
        {
	
            case 0:
	say("��������¶��һ˿΢Ц��˵�����������ʮ���ߵ������Ҿ͸��㡣\n");
	this_player()->set("marks", "���ߵ�");
	break;
	case 1:
	say("��������¶��һ˿΢Ц��˵�����������������������Ҿ͸��㡣\n");
        this_player()->set("marks", "����");
        break;
        case 2:
	say("��������¶��һ˿΢Ц��˵��������������Ы�ӿ������Ҿ͸��㡣\n");
        this_player()->set("marks", "Ы�ӿ�");
        break;
        case 3:
	say("��������¶��һ˿΢Ц��˵���������������ɳ��������Ҿ͸��㡣\n");
        this_player()->set("marks", "ɳ���");
        break;
        /*case 4:
	say("��������¶��һ˿΢Ц��˵�����������������˿�����Ҿ͸��㡣\n");
        this_player()->set("marks", "����˿");
        break;*/
	}
	return 1;
}
int accept_object(object who, object ob)
{
	object obj;

	if ( userp(ob) ) {
	command("grin");
	command("say �������������������ɵúã�");
	message_vision("$N˵������ʬ��һ������$n���ؿڡ�\n", this_object(), ob);
	ob->receive_wound("qi", ob->query("max_qi")+100, "������ɱ����");
	return 1;
	}
	/*if ((string)ob->query("name")=="����˿" &&
        this_player()->query("marks") == "����˿"
		&&!userp(ob)) {
	command( "hehe");
	this_player()->add("azi", 1);
        call_out("destroy_it", 1, ob);
	if( (int)this_player()->query("azi")>=3){
	command( "say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
	command( "say ��֦��ú���ȥ�ðɡ�");
	obj = new("/d/xingxiu/obj/incense");
	obj->move(this_player());
	this_player()->delete("azi");
	this_player()->delete("marks"); 
	}
	return 1;
    }*/
	if ((string)ob->query("name")=="���ߵ�" &&
        this_player()->query("marks") == "���ߵ�" 
		&&!userp(ob)) {
        command( "hehe");
        this_player()->add("azi", 1);
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("azi")>=10){
        command( "say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
        command( "say ��֦��ú���ȥ�ðɡ�");
        obj = new("/d/xingxiu/obj/incense");
        obj->move(this_player());
        this_player()->delete("azi");
	this_player()->delete("marks");
	}
        return 1;
    }
	if ((string)ob->query("name")=="����" &&
        this_player()->query("marks") == "����" 
		&&!userp(ob)) {
        command( "hehe");
        this_player()->add("azi", 1);
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("azi")>=5){
        command( "say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
        command( "say ��֦��ú���ȥ�ðɡ�");
        obj = new("/d/xingxiu/obj/incense");
        obj->move(this_player());
        this_player()->delete("azi");
	this_player()->delete("marks");
	}
        return 1;
    }
	if ((string)ob->query("name")=="Ы�ӿ�" &&
        this_player()->query("marks") == "Ы�ӿ�" 
		&&!userp(ob))  {
        command( "hehe");
        this_player()->add("azi", 1);
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("azi")>=5){
        command( "say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
        command( "say ��֦��ú���ȥ�ðɡ�");
        obj = new("/d/xingxiu/obj/incense");
        obj->move(this_player());
        this_player()->delete("azi");
	this_player()->delete("marks");
	}
        return 1;
    }
	if ((string)ob->query("name")=="ɳ���" &&
        this_player()->query("marks") == "ɳ���" 
		&&!userp(ob))  {
        command( "hehe");
        this_player()->add("azi", 1);
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("azi")>=3){
        command( "say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
        command( "say ��֦��ú���ȥ�ðɡ�");
        obj = new("/d/xingxiu/obj/incense");
        obj->move(this_player());
        this_player()->delete("azi");
	this_player()->delete("marks");
	}
        return 1;
    }
	else { return 0;}
}
void destroy_it(object ob)
{
	if(ob)
	destruct (ob);
}
