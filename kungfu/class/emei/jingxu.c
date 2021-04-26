// Code of ShenZhou
// Npc: /kungfu/class/emei/jingxu.c ����ʦ̫
// Date: xbc 99/09/24
// Modified by xQin 8/00
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_for_huansu();
string ask_for_update();
string ask_for_join();
int auto_perform();

void create()
{
        set_name("����ʦ̫", ({
                "jingxu shitai",
                "jingxu",
                "shitai",
	}));
	set("long",
		"����һλ���������ʦ̫���ڻ��������С�\n"
		"�������ʦ̫�İ˴��ֱ�����֮��������ָ�����Ʒ���\n"
	);

	set("gender", "Ů��");
	set("attitude", "friendly");
	set("class", "bonze");

        set("inquiry",([
                "����"  : (: ask_for_join :),
        ]));

	set("age", 38);
	set("shen_type", 1);

	set("str", 26);
	set("int", 20);
	set("con", 20);
	set("dex", 25);

	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 1300);
	set("max_neili", 1300);
	set("jiali", 70);
	set("combat_exp", 650000);
	set("score", 1000);

        set_skill("force", 120);
        set_skill("linji-zhuang", 120);
        set_skill("strike", 120);
        set_skill("jinding-zhang", 120);
        set_skill("finger", 120);
        set_skill("tiangang-zhi", 120);
//        set_skill("sword", 120);
//        set_skill("emei-jian", 120);
//        set_skill("blade", 120);
        set_skill("literate", 101);
        set_skill("parry", 100);
        set_skill("dodge", 110);
        set_skill("zhutian-bu", 110);
        set_skill("persuading", 120);
        set_skill("mahayana", 120);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
//        map_skill("sword", "emei-jian");
//        map_skill("blade", "yanxing-dao");
        map_skill("parry", "jinding-zhang");
        map_skill("dodge", "zhutian-bu");

	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");

	create_family("������", 4, "����");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	set("inquiry",([
		"����"  : (: ask_for_update :),
		"update"  : (: ask_for_update :),
		"����" : (:ask_for_huansu:),
	]));
	setup();

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
                write("����ʦ̫˵����к�����ס�ڶ���ɽ��
            �и�ɮ��������ʲô��ʤ�壿�����˵��ֱ����ᰡ�
            ɮ�����ʣ������£�������֮�£���Σ����������������塣
            ɮ�����ʣ�ʲô�Ƿ𷨣�������˵��������ǰ���˹ġ�
            ��ɮ˵�����Ҳ���������к����������ش������أ�\n\n");

		if ((int)me->query_skill("mahayana", 1) > 60 + random(8)) {
			write("��������һ�������������������¡�\n");
			write("��˵��������ǧ��ĺ��˰١�\n\n");
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
                write("����ʦ̫˵������������ڶ���ɽ���ҡ�
            ������������죬�и�ɮ�˳����ʣ�ʲô�Ƿ𷨴��⣿
            �������˵���ճ���֪�����ʣ������ĵ��ǰ�ƣ�
            ɮ�����ʣ�ʲô��˫�徳������������������ش������أ�\n\n");

                if ((int)me->query_skill("mahayana", 1) > 60 + random(8)) {
                        write("��������һ������������������ʡ�\n");
                        write("������ҹ��ˮ���ֺ�����������ǰɽ��\n\n");
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

/*	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("ask_for_update");
		call_out("ask_for_update", 1, ob);
	}*/
        ::init();
        add_action("do_nod","nod");

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingxu shitai"
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
	&& ob->query("family/master_id") == "jingxu shitai"
        && ob->query("class") !=  "bonze" )                 
	{
		message_vision(
                        "$n����$N˵�������Ȼ�����ף�����ȥ�����׼�ʦ��ѧ�հɡ�\n",ob,this_object());
                ob->delete("family/master_name");
                ob->delete("family/master_id");
                return;
        }
}

string ask_for_update()
{
	object me = this_player();
	mapping subpoint = me->query_learned();

	if( environment(me) != environment(this_object()) ) return "";

	if( me->query("emj_converted") ) return "�����Ѿ�������¹��ˣ�";
	if( (int)me->query_skill("huifeng-jian") < 1 ) return "�㲢�����ö��ҵĽ�������";

	me->set_skill("emei-jian", me->query_skill("huifeng-jian", 1));
	me->improve_skill("emei-jian", subpoint["huifeng-jian"]);
	me->delete_skill("huifeng-jian");
	me->set("emei/emj_converted", 1);
	return HIY"��ϲ�����Ľ����Ѿ�����Ϊ���µĶ��ҽ���2000�棬�ɵİ汾Ҳ��\n"
		"ͬʱɾ�����뼴ʱװ�������µĶ��ҽ���"NOR+CYN"(ָ�enable sword emei-jian)��\n"NOR
		HIY"��������κ����ʣ�����°汾�����κε����л�����ϵ�������\n"
		"�������������ڴ˴�����ѯ�ʣ�ȡ����ͻ����񲿼�����Ա����ϵ��\n"
		"�ٴθ�л���Զ����ɵĻݹˡ�\n"NOR;
}

#include "/kungfu/class/emei/jing3.h"
#include "/kungfu/class/emei/auto_perform.h"
#include "/kungfu/class/emei/nun.h"

