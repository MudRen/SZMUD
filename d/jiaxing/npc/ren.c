// Code of ShenZhou
// Jay 8/9/96
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������",({ "ren woxing","ren" }) );
        set("gender", "����");
        set("age", 55);
	set("long",
		"�����׳��봹����ǰ���������������������ı������ݡ�\n");
      //  set("nickname","");
        set("title","�������ǰ����");
        set("combat_exp", 1800000);
        set("shen_type", 0);
        set("attitude", "peaceful");
        set_skill("unarmed", 180);

	set_skill("force",180);
        set_skill("parry", 180);
        set_skill("dodge", 180);
	set_skill("huagong-dafa",180);
	set_skill("sword",150);
	map_skill("force","huagong-dafa");

	set("max_neili",5000);
	set("neili",5000);
	set("jiali",100);
       setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}


void greeting(object me)
{
  object book, kao;

        if (kao=present("liaokao",me))
		destruct(kao);
	command("thank "+me->query("id"));
	command("say ��л����������Ҳŵ������ѡ�");
	if (!present("kuihua baodian",me)) {
	 command("say ����һ���̵ֽĴ���֮���飬�������Ŀ����ж���");
	 book = new(__DIR__"obj/baodian");
	 book->move(me);
	 command("chat ����Ӣ�ۣ�Ψ"+me->query("name")+"���Ҷ���");
	}
	return;
}

	
