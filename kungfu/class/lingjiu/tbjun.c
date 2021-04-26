// By Xuanyuan 11/18/2001

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int auto_perform();
string ask_me(string name);
void greeting(object);
void init();
void create()
{
	set_name("����˪", ({ "cheng qingshuang", "cheng"}));
	set("long",
	    "���ǡ����չ�������Ų��о��첿�ĸ����졣\n"+
	    "�������������չ�����\n");
	set("title", "���첿������");
	set("gender", "Ů��");
	set("age", 20);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("per", 23);
	set("class", "scholar");
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 1300);
	set("max_qi", 1300);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 20);

	set("combat_exp", 300000);
	set("combat_exp", 700000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);
	set_skill("literate",100);
	set_skill("music",100);

	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("tianyu-qijian",100);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");

        set("inquiry", ([
		"weapon" : (: ask_me, "ljjian1" :),
		"����" : "����Ҫʲô�����أ�\n",
        ]));
	set("wuqi_count", 10);

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
	create_family("���չ�",4,"����");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
 	carry_object("/clone/weapon/changjian")->wield();
 	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        add_money("silver",25);
}
string ask_me(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "���չ�")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ�����������������������Ҫ�ˣ� ����̰�����У�";

	if (query("wuqi_count") < 1)
		return "��Ǹ�������ò���ʱ�������Ѿ������ˡ�";

	ob = new("/clone/weapon/changjian");
	ob->move(this_player());

	add("wuqi_count", -1);

	message_vision("����˪��$Nһ��" + ob->query("name") + "��\n", this_player());

	return "��ȥ�ɡ��ú��������������չ���";
}
void init()
{
        object ob;
 
        ::init();
 
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
       if ((string)ob->query("family/family_name") == "���չ�") 
             {
               message_vision("����˪����$N���ͷ��΢΢Ц��Ц��\n",ob);
               return;
              }
        if (!(string)ob->query("family/family_name"))
             {
               message_vision("����˪����$N΢Ц˵����������ʦ�İɣ����Ұɡ�\n",ob);
               return;
              }
}
#include "/kungfu/class/lingjiu/tianbu.h"
#include "/kungfu/class/lingjiu/auto_perform.h"