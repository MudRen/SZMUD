// Code of ShenZhou
inherit NPC;
void create()
{
        set_name("����", ({ "pu yi" }));
        set("str", 20);
        set("gender", "����");
        set("age", 18);
        set_max_encumbrance(100000000);
        set("combat_exp", 250);
        set("attitude", "friendly");
        

        setup();
}
int accept_object(object who,object ob)
{
        string *money_list= ({
        "����",
	"�ƽ�",
	"��Ԫ��"
        });
if (who->query("combat_exp") < 5000)
        return notify_fail("�㻹̫С��������������ģ�\n");

 if ( member_array(ob->query("name"), money_list) != -1 )
	{
        call_out("destroy", 1, ob);
	command("smile");
	if( ob->value() >= 50000 )
        {
 	who->set_temp("dalibook",2);
	who->add_temp("dalibookimprove", (int)ob->value()/2000);
	log_file("QUESTS", sprintf("%s(%s) paid %d ���ƽ� to learn from teacher.\n",
        who->query("name"), getuid(who), (int)ob->value()/10000));

	return 1;
	}
	return 1;
	}
}
