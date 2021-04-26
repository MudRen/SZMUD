// Code of ShenZhou
// Npc: /kungfu/class/emei/jingxuan.c ����ʦ̫
// Date: shan 96/09/24
// Modified by xQin 8/00
inherit NPC;
inherit F_MASTER;

string ask_for_huansu();
string ask_for_join();
string ask_for_job();
int auto_perform();

void create()
{
        set_name("����ʦ̫", ({
                "jingxuan shitai",
                "jingxuan",
                "shitai",
        }));
        set("long",
"�����Ƕ����ɴ���Ӿ���ʦ̫���ڰ˴��ֱ����������е�һ�����ý����͵�����\n"
"����ĸߴ���̬���ͣ�����Ů�ӣ�ȴ��Ѱ�����ӻ����˰��ͷ��\n"
        );

	set("gender", "Ů��");
	set("attitude", "friendly");
	set("class", "bonze");

        set("inquiry",([
                "����"  : (: ask_for_join :),
                "����" : (:ask_for_huansu:),
                "��������" : (:ask_for_job:),
        ]));

	set("age", 50);
	set("shen_type", 1);

	set("str", 26);
	set("int", 20);
	set("con", 20);
	set("dex", 26);

	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 80);
	set("combat_exp", 700000);
	set("score", 5000);

        set_skill("force", 120);
        set_skill("linji-zhuang", 120);
        set_skill("strike", 100);
        set_skill("jinding-zhang", 100);
        set_skill("finger", 100);
        set_skill("tiangang-zhi", 100);
        set_skill("sword", 120);
        set_skill("emei-jian", 120);
        set_skill("blade", 100);
        set_skill("yanxing-dao", 100);
        set_skill("parry", 100);
        set_skill("dodge", 120);
        set_skill("zhutian-bu", 120);
        set_skill("persuading", 120);
        set_skill("literate", 101);
        set_skill("mahayana", 120);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
        map_skill("sword", "emei-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "jinding-zhang");
        map_skill("dodge", "zhutian-bu");

        prepare_skill("strike", "jinding-zhang");
        prepare_skill("finger", "tiangang-zhi");
	
	create_family("������", 4, "����");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	setup();

	carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();
}


int do_nod(string arg)
{
        object me = this_player();

        if( !me->query_temp("pending/kao") )
                return 0;

	command("smile");
	command("say �ҽ�������������\n");

	message("vision", "����ʦ̫����"+me->name()+"���˼��仰��\n",
                        environment(me), ({me}) );

        switch(random(2)) {
		case 0:
                write("����ʦ̫˵���޺�������ס�ڶ���ɽ�Ӹ�Ժ�
            ��ɮ��������ʲô���������⣿����˵�����к��棬���︡Ž��
            ɮ���ʣ�����ô��᣿���޺������������ش������أ�\n\n");

		if ((int)me->query_skill("mahayana", 1) > 60 + random(10)) {
			write("��������һ����������������ʡ�\n");
			write("��˵��ңָ��ɣ���Ǳߡ�\n\n");
			message("vision", me->name()+"����һ�£�������ʦ̫˵�˼��仰��\n",
				environment(me), ({me}) );

                	command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
                	command("say ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������\n");
                	command("recruit " + me->query("id"));
		}
		else {
			write("��������ã�Ҳ�ⲻ�������е�����\n");
			command("say �����ӷ����ѧЩ�𷨺��������Ұɡ�\n");
		}
		break;

		case 1:
                write("����ʦ̫˵����ӡ�������ڻ����¿�����
            ��ӡ������һ�������ɮԲ��ʲô�ǹŷ�δ�ң�
            Բ��˵��ͥǰ�����ӡ���ӡ����������˵��ʲô��\n\n");

                if ((int)me->query_skill("mahayana", 1) > 60 + random(10)) {
                        write("��������һ������������������ʡ�\n");
                        write("����������˵��һ��Ͷ�ھ��֡����ⲻ֪��ҲͶ��һ�Σ���\n\n");
                        message("vision", me->name()+"����һ�£�������ʦ̫˵�˼��仰��\n",
                                environment(me), ({me}) );

                        command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
                        command("say ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������\n");
                        command("recruit " + me->query("id"));
                }
		else {
                        write("��������ã�Ҳ�ⲻ�������е�����\n");
                	command("say �����ӷ����ѧЩ�𷨺��������Ұɡ�\n");
		}
               	break;
	}
        return 1;

} 
 
void init()
{
        object ob;

        add_action("do_kneel", "kneel");

        ::init();
        add_action("do_nod","nod");

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingxuan shitai"
	&& ob->query("shen") < -100) 
	{
       	 	message_vision(
                "$n����$N˵��������ô����������£�\n",
                ob, this_object() );
		command("say �Ҷ��������������������ɣ�" +
                        "�Ե���Ҫ���ϡ��Ҳ����������㣬��ȥ�ɡ�\n");
                command("expell " + ob->query("id"));
                return;
        }

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingxuan shitai"
        && ob->query("class") !=  "bonze" )                 
	{
		message_vision(
                        "$n����$N˵�������Ȼ�����ף�����ȥ�����׼�ʦ��ѧ�հɡ�\n");
                ob->delete("family/master_name");
                ob->delete("family/master_id");
                return;
        }
}

#include "/kungfu/class/emei/jing3.h"
#include "/kungfu/class/emei/auto_perform.h"
#include "/kungfu/class/emei/nun.h"
#include "/kungfu/class/emei/pers_job.h"

