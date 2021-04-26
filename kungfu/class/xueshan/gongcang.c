// Code of ShenZhou
// Summer 9/26/1996.
inherit F_MASTER;
inherit NPC;

string ask_for_join();

void create()
{
	set_name("���������", ({ "changqi lama", "changqi", "lama" }));
	set("long", 
"һ���׷����ƽ����������������������������������ң�Ѱ����ʦ��\n"
"�㼣�鲼�ຣ�����ࡢ����˿�ء��ڶ�ʮ��ǰ�������£��������ء�\n");
	set_weight(10000000);
	set("gender", "����");
	set("age", 60);
	set("attitude", "peaceful");
	set("class","lama");
	set("inquiry",([
                "���"  : (: ask_for_join :),
                "����"  : (: ask_for_join :),
	]));

	set("shen_type", 1);
	set("str", 25);
	set("int", 27);
	set("con", 26);
	set("dex", 25);
	
	set("max_qi", 600);
	set("max_jing", 450);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 30);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 50);
	set_skill("dodge", 60);
	set_skill("parry", 50);
	set_skill("staff", 45);
        set_skill("lamaism", 80);
	set_skill("cuff", 40);
	set_skill("necromancy", 60);
	set_skill("jingang-chu", 55);
	set_skill("yujiamu-quan", 50);
	set_skill("shenkongxing", 60);
	set_skill("longxiang-banruo", 50);

	map_skill("force", "longxiang-banruo");
	map_skill("parry", "jingang-chu");
	map_skill("staff", "jingang-chu");
	map_skill("cuff", "yujiamu-quan");
	map_skill("dodge", "shenkongxing");
	
	prepare_skill("cuff", "yujiamu-quan");

	create_family("ѩɽ��", 12, "����");

	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
}
void attempt_apprentice(object ob)
{
	if (ob->query("gender") == "Ů��") {
		command("say Ůʩ����ذɣ����²���Ůͽ��");
	return; 
	}
	
	 if ((string)ob->query("family/family_name") == "ؤ��" && ob->query("rank") > 1 ) {
                command("say " + RANK_D->query_respect(ob) + "��ؤ����֣�ˡ�Ҳ������㡣");
                return;
        }
	if( ob->query("family/family_name") != "ѩɽ��" 
	&& ob->query("family/family_name") != "Ѫ����"
	&& ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                        +ob->query("family/family_name")+"���֣����ɿɲ���������");
                return;
        }
        command("say �ðɣ��Ҿ��������ˣ��ɲ�Ҫ����ȥ��ĸ������͡�");
        command("recruit " + ob->query("id"));
}
void init()
{
	::init();
        add_action("do_kneel", "kneel");
}

string ask_for_join()
{
        object me;

        me = this_player();

	if( (string)me->query("class")=="lama" )
                return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶɮ�������Ц��\n";

	if( me->query("family/family_name") != "ѩɽ��"
        && me->query("family/family_name") != "Ѫ����"
	&& me->query("combat_exp") >= 10000 ) 
                return "��λ" +RANK_D->query_respect(this_player()) + "��"
                        +me->query("family/family_name")+"���֣��ι��������³��ң�\n";

        if( (string)me->query("gender") == "Ů��" )
                return "�����ӷ����գ����գ�Ůʩ������������ҷ𣬿�ȥ��ɽ����
�ܽ䡣\n";

        me->set_temp("pending/join_lama", 1);
        return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n"
;
}
int do_kneel()
{
	object me = this_player();
	if( !me->query_temp("pending/join_lama") )
                return 0;

        message_vision(
                "$N˫�ֺ�ʮ�����������ع���������\n\n"
                "$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n"
,
                me, this_object() );
	command("smile");
        me->delete_temp("pending/join_lama");
        me->set("class", "lama");
}
