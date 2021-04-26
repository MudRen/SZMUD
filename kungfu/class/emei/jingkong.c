// Code of ShenZhou
// Npc: /kungfu/class/emei/jingkong.c ����ʦ̫
// Date: xbc 99/09/24
// Modified by xQin 8/00
inherit NPC;
inherit F_MASTER;
string ask_for_huansu();
string ask_for_join();
int auto_perform();

void create()
{
        set_name("����ʦ̫", ({
                "jingkong shitai",
                "jingkong",
                "shitai",
	}));
	set("long",
		"����һλ���������ʦ̫�������������С�\n"
		"�������ʦ̫�İ˴��ֱ�����֮�ģ����õ������Ʒ���\n"
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
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 70);
	set("combat_exp", 600000);
	set("score", 1000);

        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
	set_skill("finger", 110);
	set_skill("tiangang-zhi", 110);
        set_skill("strike", 100);
        set_skill("jinding-zhang", 100);
        set_skill("blade", 110);
        set_skill("yanxing-dao", 110);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("zhutian-bu", 90);
        set_skill("persuading", 110);
        set_skill("mahayana", 110);
        set_skill("literate", 120);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
//        map_skill("sword", "emei-jian");
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

        carry_object("/clone/weapon/gangdao")->wield();
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

        switch(random(3)) {
		case 0:
                write("����ʦ̫˵����ˮ��ʦ��ס�����������֣���ʱ�а�ˮ�¡�
            �и�ɮ��������ʲô����ʦ�����⣿����ˮ��ʦ�������ش������أ�\n\n");

		if ((int)me->query_skill("mahayana", 1) > 60 + random(5)) {
			write("��������һ�������������������¡�\n");
			write("��˵��������Ҥլ��һ����Ǭ����\n\n");
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
                write("����ʦ̫˵����ˮ��ʦ��ס�����������֣���ʱ�а�ˮ�¡�
            �и�ɮ����������������һ·��Ӧ̸���£�����ˮ��ʦ�������ش������أ�\n\n");

                if ((int)me->query_skill("mahayana", 1) > 60 + random(5)) {
                        write("��������һ�������������������¡�\n");
                        write("����������ǧ�غ����ۣ���������˹顣\n\n");
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

		case 2:
                write("����ʦ̫˵����ˮ��ʦ��ס�����������֣���ʱ�а�ˮ�¡�
            �и�ɮ��������ʲô�Ǵ˾��������ԣ�����ˮ��ʦ�������ش������أ�\n\n");

                if ((int)me->query_skill("mahayana", 1) > 60 ) {
                        write("��������һ�������������������¡�\n");
                        write("����������ʯŮ�ɿ��죬������ţҹ��Ƶ��\n\n");
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
	&& ob->query("family/master_id") == "jingkong shitai"
	&& ob->query("shen") < -100) 
	{
       	 	message_vision(
                "$n����$N˵��������ô����������£�\n",
                ob, this_object() );
		command("say �Ҷ��������������������ɣ�" +
                        "�Ե���Ҫ���ϡ��Ҳ����������㣬��ȥ�ɡ�\n");
                command("expell " + ob->query("id"));
		ob->delete("emei_shen");
                return;
        }

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingkong shitai"
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

