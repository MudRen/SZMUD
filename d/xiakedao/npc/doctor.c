//Cracked by Roath
// doctor.c ҽ��
// Ssy

#include <ansi.h>
inherit NPC;

void greeting(object);


void create()
{
	set_name("ҽ��", ({ "doctor", "yizhe"}));
	set("long", 
	    "һλ�׷���������ߡ���˵���������ǽ�����һλ��������ҽ��\n"
            "���Դ��������͵��Ϻ���������������˭Ҳ��֪������������ô�ˡ�\n"
            "��������������ģ���Ҫ�����������˵Ļ����²���ô���ס�\n");
	set("gender", "����");
	set("age", 74);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("race", "����");	
	set("max_qi", 150);
	set("eff_qi", 150);
	set("qi", 150);
	set("max_jing", 150);
	set("eff_jing", 150);
	set("jing", 150);
	set("max_neili", 150);
	set("eff_neili", 150);
	set("neili", 150);
	set("max_jingli", 150);
	set("eff_jingli", 150);
	set("jingli", 150);
	set("combat_exp", 1000);

	set_skill("force", 5);
	set_skill("dodge", 5);
	set_skill("parry", 5);
	set_skill("cuff", 5);
	set_skill("sword", 5);
	
	set("inquiry", ([
			"����"   : 	"�����ھ�úܣ�����ЪЪ�ա�\n",
			"heal"   :      "�����ھ�úܣ�����ЪЪ�ա�\n",
		]));

	setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();

}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	
        int wound = (me->query("eff_qi")*100)/(me->query("max_qi"));
	if (wound < 20)
	  {
	    command("walkby " + me->query("id"));
	    command("say " + RANK_D->query_respect(me) + "��ô�˵�����������\n");
	  }
	else if (wound < 100)
	  {
	    command("sigh");
	    command("say " + RANK_D->query_respect(me) +
"����������û��ϵ����������Ե��ͷ��ô�ܳɴ����أ�");
	  }
	else
	  {
	    command("hehehe " + me->query("id"));
	  }
}

int accept_object(object me, object obj)
{
        call_out("accept_obj", 1, me, obj);
        return 1;
}

int accept_obj(object me, object obj)
{
        object ke;
        if( obj->query("name")=="Ҭ��") 
	  {
	     command("thumb "+ me->query("id"));
	     command("say " + RANK_D->query_respect(me) +
"��ô֪����ϲ����Ҭ�ӣ����ðգ��Ҹ��㿴���ˡ���\n");
	     message_vision("$Nȡ��ЩҩƷ���������������а�����$n����ذ�����һ�£���Ȼ�����ֻش���\n", this_object(), me);
	     message_vision("$NЦ���������С�ˣ����ҿ����㲻����ô��\n", this_object(), me);
	     me->set("eff_qi", me->query("max_qi"));
	     return 1;
	  }
	else 
	  {
             command("? "+ me->query("id"));
	     return 0;
	  }
}
 
