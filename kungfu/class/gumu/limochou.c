// Code of ShenZhou
// Xuanyuan 7/14/2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int do_look(string);
int ask_me();
int ask_sanwu();
int auto_perform();
int auto_throw();
void create()
{
        set_name("��Ī��", ({ "li mochou", "li", "mochou" }));
        set("long", "�����ü�Ϊ��ò���������Ŀ�����˲���������\n");
	set("nickname", "��������");
        set("gender", "Ů��");
        set("rank_info/respect", "����");
        set("age", 27);
        set("attitude","heroism");
        set("str", 30);
        set("dex", 35);
        set("con", 17);
        set("int", 25);
        set("shen_type", -1);

        set_skill("strike", 300);
        set_skill("cuff", 300);
	set_skill("gumu-shenfa", 300);
	set_skill("chilian-shenzhang", 300);
	set_skill("meinu-quan", 300);
        set_skill("force", 300);
        set_skill("dodge", 300);
	set_skill("whip",300);
	set_skill("throwing",300);
	set_skill("jueqing-bian",300);
        set_skill("wudu-xinfa",300);

	map_skill("dodge", "gumu-shenfa");
	map_skill("strike", "chilian-shenzhang");
	map_skill("cuff", "meinu-quan");
        map_skill("force", "wudu-xinfa");
	map_skill("whip","jueqing-bian");

	prepare_skill("strike", "chilian-shenzhang");

        set("jiali",50);
        set("combat_exp", 2000000);

        set("max_qi", 2800);
        set("max_jing", 4200);
        set("neili", 4000);
        set("max_neili", 4000);

        create_family("��Ĺ��",3,"����");

	set("canuse_sanwu",1);

        set("inquiry", ([
            "name" : "վԶ�㣡",
            "here" : "�Ҳ��Ǳ����ˣ���֪����",
            "��" : "����������������˼֮�ࡢ���֮�⣿",
            "½չԪ" : "�����Ǹ������С������ʲô��",
	    "�����" : (: ask_me :),
            "С��Ů" : "�����ҵ�ʦ�á����������ʲô��",
            "�ֳ�Ӣ" : "�����ҵ�ʦ�棬�������ʵ�����ʣ�С���������㡣",
		"����������" : (: ask_sanwu :),
       ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
            "��Ī���������裬�������񣬸�����������䣬���Ǻ��ֱ������������\n",
            "��Ī�����������ϵر�˫�ɿͣ��ϳἸ�غ����\n",
            "��Ī�����������Ȥ�����࣬���и��гն�Ů����\n",
            "��Ī���������Ӧ�����������ƣ�ǧɽĺѩ��ֻӰ��˭ȥ����\n",
            "��Ī����Ɐ�У��������ǰ�Թ�������������·����į������ġ���������ƽ������\n",
            "��Ī���������л�Щ��ർ���ɽ��������ꡣ��\n",
            "��Ī���������Ҳ�ʣ�δ���ˣ�ݺ�����Ӿ��������\n",
            "��Ī�������ǧ����ţ�Ϊ����ɧ�ˣ����ʹ�����������𴦡���\n",
        }) );
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
                (: auto_throw :),
	}) );
        carry_object("/clone/weapon/fuchen")->wield();
        carry_object("/d/wudang/obj/greenrobe")->wear();
        carry_object("/d/zhongnan/obj/bpzhen")->set_amount(7);
}

void init()
{
        ::init();
        add_action("do_look","look");
        add_action("do_look","hug");
        add_action("do_look","mo");
        add_action("do_look","18mo");
        add_action("do_look","kiss");

}

int ask_me()
{
        object me;
 
        me = this_player();
	   message("vision",
   HIY "��Ī����Цһ���������������ȥ������\n"
       "��Ī�����ɱ��" + me->name() +"\n"
   NOR, environment(), this_object() );
                   kill_ob(this_player());
   return 1;
}
  
int ask_sanwu()
{
        object ob = this_player();
        
        if (ob->query("family/family_name") != "��Ĺ��") {
                command("say �ã������㿴��ʲô�ǡ����������֡���");
		kill_ob(this_player());
                command("perform sanwu");
                return 1;
        }
	if (ob->query("family/master_name") != "��Ī��") {
                command("say �ã������㿴��ʲô�ǡ����������֡���");
		kill_ob(this_player());
                command("perform sanwu");
		return 1;
		}     
        if (ob->query("canuse_sanwu") > 0 ) {
                command("say �㲻���Ѿ�ѧ������");
                return 1;
        }
        if (ob->query_skill("whip",1) < 100) {
                command("say Ҫʹ�������ľ�����Ҫ����ı޷����㻹�Ƕ���ϰ��ϰ��˵�ɡ�");
                return 1;
        }
        if (ob->query_skill("jueqing-bian",1) < 100) {
                command("say Ҫʹ�������ľ�����Ҫ����ı޷����㻹�Ƕ���ϰ��ϰ������޷�����˵�ɡ�");
                return 1;
        }
        	command("say �ã��Ҿͽ������С����������֡���\n");

        ob->set("canuse_sanwu", 1);
        return 1;
}
int do_look(string target)
{
        object me;
 
        me = this_player();
        if (target=="li" || target=="li mochou" || target=="mochou" ) 
           if ((string)me->query("gender") == "����") {
		   message("vision",
   HIY "��Ī���ŭ���ȵ��������������Щ����ĳ����ˣ�ȥ���ɣ�\n"
       "��Ī�����ɱ��" + me->name() +"����\n"
   NOR, environment(), this_object() );
                   kill_ob(this_player());
           }
}       
/*
void attempt_apprentice(object ob)
{
	mapping fam = ob->query("family");
	if (!fam || fam["family_name"] != "��Ĺ��"){
                command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                return;
                }
	if (ob->query("gender") != "Ů��") {
		command("say ��ֻ��Ů���ӣ�"+RANK_D->query_respect(ob)+"��ذɡ�");
		return; 
		}

	if (fam["family_name"] == "ؤ��" && ob->query("rank") > 1 )  {
		command("say " + RANK_D->query_respect(ob) + "��ؤ����֣�ˡ�Ҳ������㡣");
		return;
        	}

	if (ob->query("combat_exp") >= 10000 && ob->query("family") ) {
		command ("say " + RANK_D->query_respect(this_player())
                                + "��" + fam["family_name"]  + "���书���֣��ҿɲ���������");
		return;
                }
	if (ob->query_kar() > 20) {
                command("say �����ͷ���һ���������ӣ�ԭ�λ������������֮�ˡ�");
                return;
                }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("recruit " + ob->query("id"));
}
*/

#include "/kungfu/class/gumu/auto_perform.h";
#include "/clone/npc/auto_throw.h";
