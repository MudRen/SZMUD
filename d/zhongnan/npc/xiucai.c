// Code of ShenZhou
// xiucai.c �����
// ryu, 11/1/96
// modified by aln 2 / 98

inherit NPC;

void create()
{
	set_name("�����", ({ "lao xiucai", "xiucai" }));
	set("long", "һ�������ʵ��������ţ���������ɽ�����Լ���ѧ����\n");
	set("gender", "����");
	set("age", 65);

	set_skill("literate", 30);

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	set("combat_exp", 2000);
	set("shen_type", 1);
	setup();
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/��"))
		return 0; 
	ob->add_temp("mark/��", -1);
	return 1;
}

int accept_object(object who, object ob)
{ 
        object wage;

        if( base_name(ob) == "/d/hangzhou/obj/mh_book" ) {
                if( !ob->query("checked") ) {
                       command("say �Ȿ��ʷδ����������׫����������һ���ܶ�ɡ�");
                       return 0;
                }

                if( time() < (int)query("mh_time") + 300 ) {
                       command("say �Ҹ��õ���һ�����㻹�Ǹ����˰ɡ�");
                       return 0;
                }

                command("joythank " + who->query("id"));
                set("mh_time", time());
                wage = new("/clone/money/silver");
                wage->set_amount(3 + random(5));
                wage->move(who);
                message_vision("$N����һ�����Ӹ�$n��\n", this_object(), who);
                remove_call_out("destroy_it");
                call_out("destroy_it", 1, ob);
                return 1;
        }
                       
	if (who->query_skill("literate", 1) > 30){
                message_vision("�����̾�˿�����$N˵��������������ʦ�ɣ��Ҷ���������īˮ�Ѿ��̲������ˡ�\n", who);
                return 0;
        }
	if (!(int)who->query_temp("mark/��"))
		who->set_temp("mark/��", 0);
	if (ob->query("money_id") && ob->value() >= 200) {
		message_vision("�����ͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
		who->add_temp("mark/��", ob->value() / 50);
		return 1;
	}
	return 0;
}
void destroy_it(object obj)
{
        destruct(obj);
}

