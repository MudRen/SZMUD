// Code of ShenZhou
// /kungfu/class/quanzhen/pi.c
// pi.c  Ƥ����
// sdong 08/01/98
// Modified by xQin 8/00

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_for_join();

int do_kneel();

int auto_perform();

void create()
{
        set_name("Ƥ����", ({ "pi qingxuan", "pi" }));
        set("long",
                  "����һλ���ǿ����׳���ʿ���ƺ������ա�\n"
                );
        set("gender", "����");
        set("age", 36);
        set("attitude", "heroic");
        set("shen_type", 1);
        set("str", 20);
        set("int", 28);
        set("con", 28);
        set("dex", 20);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("max_jingli", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 40000);
        set("score", 6000);

        set_skill("force", 40);
        set_skill("xiantian-gong", 40);
        set_skill("dodge", 40);
        set_skill("jinyangong", 40);
        set_skill("cuff", 40);
        set_skill("chunyang-quan", 40);
        set_skill("strike", 40);
        set_skill("sanhua-juding", 40);
        set_skill("parry", 40);
        set_skill("sword", 40);
        set_skill("quanzhen-jian", 40);
        set_skill("literate", 40);
        set_skill("taoism", 40);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyangong");
        map_skill("cuff", "chunyang-quan");
        map_skill("strike", "sanhua-juding");
        map_skill("parry", "quanzhen-jian");
        map_skill("sword", "quanzhen-jian");

        prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "sanhua-juding");

        create_family("ȫ���", 4, "����");

        set("class", "taoist");

        set("inquiry",([
        	"����"  : (: ask_for_join :),
        	"����"  : "����ƶ�������������㻹��ȥ���ƽ����˰ɡ�",
         ]));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
        mapping fam;


        if ((int)ob->query("shen") < 0) {
                command("say ��ȫ������������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }

                  if( ob->query("family/family_name") == "ȫ���"
                  && ob->query("generation") <= this_object()->query("generation") )
                  {
                                         command("say " + RANK_D->query_respect(ob) + "��ƶ������ҵ� !");
                                         return;
                  }


                  if( ob->query("family/family_name") != "ȫ���"
                  &&  (ob->query("combat_exp",1) >= 10000 )        )
                  {
                                         command ("say �����ٷ�ʩ���Ǳ��ɵ��书���֣������ɲ���������");
                                         return;
                  }
        


                  if( (string)ob->query("class")!="taoist" )
                  {
                                         command ("say �����ٷ�ƶ���������������׼ҵ��ӡ��ˡ�");
                  }
                  else    command ("say �����ٷ�");


        command("say �ðɣ�ƶ�����������ˡ�");
        command("recruit " + ob->query("id"));
}

string ask_for_join()

{
                  object me;

                  me = this_player();
                  
	if( me->query("quit/taoist"))
	{
	return "��λ"+RANK_D->query_respect(me)+"�Ѿ����ף��������Ե��������ǿ��\n";
	}

	if( (string)me->query("class")=="taoist" )
        return "��������ͬ�����ιʸ�ƶ���������Ц��\n";

        if( (string)me->query("class")=="bonze" )
        return "��λ"+RANK_D->query_respect(me)+"����������ţ��ιʸ�ƶ���������Ц��\n";

        me->set_temp("pending/join_taoist", 1);

        add_action("do_kneel", "zhenxin");
        return "�����ٷ�ʩ������Ҫ���ң�(type ���� or zhenxin)\n";
}


int do_kneel()
{
                  object ob;
                  object me = this_player();


                  string *prename =
                        ({ "��" });
                  string *postname =
                        ({ "��","��" });
                  string name, new_name;

                  if( !me->query_temp("pending/join_taoist") )
                                         return 0;

                  message_vision(
                                         "$N���������ع���������˵����������Ը����ѧ������\n\n"
                                         "$n��$N��ͷ������������ӣ��߸������������ָ�$Nһ�׵��ۡ�\n\n",
                                         me, this_object() );
                  name = me->query("name");
                  new_name = name[0..01]+prename[random(sizeof(prename))] + name[2..3];
                  command("say �ӽ��Ժ���ĵ�������" + new_name + "��");
                  command("smile");
                  me->delete_temp("pending/join_taoist");
                  me->set("name", new_name);
                  me->set("class", "taoist");
                  me->set("PK_record", me->query("PKS") );
                  me->set("shen_record", me->query("shen"));
                  //me->set("shen", 0);

                  ob=new("/d/wudang/obj/greyrobe");
                  ob->move(me);

                  return 1;
}


	
			      
			
