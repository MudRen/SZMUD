// Code of ShenZhou
// xiucai.c �����

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIY"�����"NOR, ({ "lao xiucai", "xiucai", "lao" }));
	set("long", "һ������ţ������￪���ڿ�Ϊ����\n");
	set("gender", "����");
	set("age", 60);

	set_skill("literate", 40);

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

int accept_kill(object me)
{
        command("say ���컯��֮�¾�������ɱ�ˣ�û��������\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}
