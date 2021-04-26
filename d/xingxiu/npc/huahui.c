// Code of ShenZhou
// npc: /d/xingxiu/npc/huahui.c
// Jay 6/30/96

inherit NPC;

void create()
{
        set_name("����", ({ "hua hui", "hua" }) );
        set("gender", "����" );
        set("age", 68);
	set("nickname","һָ����");
        set("long", 
            "��������ɫ���ۣ�����������Ѫ��������ҲѪ�����죬"
	    "���θߴ�֮�������ٱȳ��˸�����ߡ�"
	    "ʮ��ָ�ױ���ָ����������Ҳ������Ѫ��\n");
        set("str", 35);
        set("dex", 30);
        set("con", 27);
        set("int", 25);
        set("shen_type", 0);

        set_skill("unarmed", 100);
        set_skill("dodge", 95);
	set_skill("hammer",100);
	set_skill("parry",100);
        set("combat_exp", 200000);

        set("attitude", "heroism");

        set("max_qi", 1000);
        set("eff_qi", 1000);
        set("qi", 1000);
        set("max_jing", 600);
        set("jing", 600);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 80);
 
        set("inquiry", ([
            "�߶�����" : "��Ȼ��µ����ҾͲ������ˣ��Ҿ��ǡ�",
	    "������" : "������뵰�������ҵ������ɡ�",
	    "��ҿ�": "�����ҵ���ͽ����ɲ�Ҫ�����κ��ˡ�",
	    "������": "�ҵò�������������Ҳ���롣",
	    "name" : "�ҽ��߶�...���ǽ������ϣ��ջ����ԡ�",
	    "here" : "������Ǹ߲��Թ���",
 	    "�߲��Թ�" : "������ǡ�",
       ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
             "����������һ�������������˶��룬Ҫ��һֻѩ���ͺ��ˡ�\n",
        }) );
        carry_object(__DIR__"obj/wcloth")->wear();
        carry_object(__DIR__"obj/liuxing")->wield();
}

int accept_object(object who, object ob)
{
    object hammer;

     if((string)ob->query("name")=="ѩ��") {
           if( who->query_temp("marks/xuelian") ) {
                 write("����Ц��Ц��˵����ո�����һֻ����ֻ���Լ����Űɡ�\n");
		 command ("give xuelian to "+who->query("id"));
                 return 1;
           }
           else {
                 command("say ��л��λ" + 
                       RANK_D->query_respect(who) + "��ȡ�");
		if (who->query_skill("hammer",1)<15) {
		 	command("say �ҿ����Ǹ�ѧ��֮�ˣ��ͽ��㼸"+
		"�й���ɡ����ǽ����ָ��Ѩ����ȭ��������Ҳ�ð��������"+
		"Ч���ҽ���һ�����Ǵ��ɡ�");
		who->improve_skill("hammer",226);	
		}
		else if (present("liuxing chui", this_object())){
		command("say �ұ��������һ�����Ǵ�����ϧ���´����������ס�");
//		hammer = new(__DIR__"obj/liuxing");
//		hammer->move(this_object());
		command("say ����һ�����Ǵ��ɡ�");
		command ("give chui to " + who->query("id"));		
		who->set_temp("marks/xuelian",1);
                  return 1;
		}
		else
		command("joythank " + who->query("id"));
		return 1;
            }
      }
    return 0;
}

 

   
