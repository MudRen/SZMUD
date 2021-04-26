// Code of ShenZhou
// Npc: /kungfu/class/emei/jinghui.c ����ʦ̫
// Date: xbc 99/06/22
// Modified by xQin 8/00

inherit NPC;
inherit F_MASTER;

string ask_for_huansu();
string ask_for_join();
int auto_perform();

void create()
{
        set_name("����ʦ̫", ({
                "jinghui shitai",
                "jinghui",
                "shitai",
	}));
	set("long",
		"����һλ���������ʦ̫����ǧ�������С�\n"
		"�������ʦ̫�İ˴��ֱ�����֮�ģ����ó�������ָ����\n"
	);

	set("gender", "Ů��");
	set("attitude", "friendly");
	set("class", "bonze");

        set("inquiry",([
                "����"  : (: ask_for_join :),
                "����" : (:ask_for_huansu:),
        ]));

	set("age", 38);
	set("shen_type", 1);

	set("str", 26);
	set("int", 20);
	set("con", 20);
	set("dex", 25);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1300);
	set("max_neili", 1300);
	set("jiali", 70);
	set("combat_exp", 600000);
	set("score", 1000);

        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
        set_skill("finger", 110);
        set_skill("tiangang-zhi", 110);
	set_skill("strike", 90);
	set_skill("jinding-zhang", 90);
        set_skill("sword", 110);
        set_skill("emei-jian", 110);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("zhutian-bu", 100);
        set_skill("persuading", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);

        map_skill("force", "linji-zhuang");
        map_skill("finger", "tiangang-zhi");
        map_skill("strike", "jinding-zhang");
        map_skill("sword", "emei-jian");
        map_skill("parry", "tiangang-zhi");
        map_skill("dodge", "zhutian-bu");

	prepare_skill("finger", "tiangang-zhi");
	prepare_skill("strike", "jinding-zhang");

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

	message("vision", "����ʦ̫����"+me->name()+"���˼��仰��\n", environment(me), ({me}) );

        switch(random(2)) {
		case 0:
		write("����ʦ̫˵�����ݴ��ţ���������������ʦ��
	    ��һ��һ����Ա�����������л�������𣿡����ݴ��Ŵ������Ͼ��롣
	    �ǹ�Ա����Щ�����ֻ���˵������֪ʶΪʲô��������أ�
	    ���ݴ����������ش������أ�\n\n");

		if ((int)me->query_skill("mahayana", 1) > 60 +random(5)) {
			write("���Ȼ������һ�������������������¡�\n");
			write("��˵�����ݴ��Żش��������Ҳ��������˭ȥ�̻��㣿\n\n");
			message("vision", me->name()+"����һ�£�������ʦ̫˵�˼��仰��\n",
				environment(me), ({me}) );

                	command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
                	command("say ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ��ö�������\n");
                	command("recruit " + me->query("id"));
		}
		else {
			write("��������ã�Ҳ���������еĵ���\n");
			command("say �����ӷ����ѧЩ�𷨺��������Ұɡ�\n");
		}
		break;

		case 1:
                write("����ʦ̫˵�����ݴ��ţ���������������ʦ��
	    ��һ��һ��ɮ�����������ӻ��з���û�У�������˵���ޡ���
	    ɮ��˵����������������ϣ����з��ԣ�Ϊʲô����ȴû�У�
            ���ݴ����������ش������أ�\n\n");

                if ((int)me->query_skill("mahayana", 1) > 60 +random(5)) {
                        write("�����һ�������������ʡ�\n");
                        write("��˵�����ݴ��Żش������Ϊ����ҵʶ����ʶ��֮ҵ���ڡ�\n\n");
                        message("vision", me->name()+"����һ�£�������ʦ̫˵�˼��仰��\n",
                                environment(me), ({me}) );

                        command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
                        command("say ϣ�������Դȱ�֮�ģ����ǻ�֮����Ŭ�����ƣ� �ö�������\n");
                        command("recruit " + me->query("id"));
                }
		else {
                	write("��������ã�Ҳ���������еĵ���\n");
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
	&& ob->query("family/master_id") == "jinghui shitai"
	&& ob->query("shen") < -100)  {
       	 	message_vision( "$n����$N˵��������ô����������£�\n", ob, this_object() );
		command("say �Ҷ��������������������ɣ�" + "�Ե���Ҫ���ϡ��Ҳ����������㣬��ȥ�ɡ�\n");
                command("expell " + ob->query("id"));
                return;
        }

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jinghui shitai"
        && ob->query("class") !=  "bonze" )                  {
		message_vision( "$n����$N˵�������Ȼ�����ף�����ȥ�����׼�ʦ��ѧ�հɡ�\n");
                ob->delete("family/master_name");
                ob->delete("family/master_id");
                return;
        }
}
#include "/kungfu/class/emei/nun.h"
#include "/kungfu/class/emei/jing3.h"
#include "/kungfu/class/emei/auto_perform.h"
