// Code of ShenZhou
// Summer 9/26/1996.

inherit NPC;
int do_huanyuan();
void create()
{
	set_name("���ײ�", ({ "ge lunbu", "ge", "lunbu" }));
	set_weight(300000000);
	set("long", 
"�������ڵĽ���ɮ�����ð�������������ŷ��ƣ����Ż��ۣ�ͷ����ñ��\n"
"������ɱ֮����\n");
	set("gender", "����");
	set("age", 20);
	set("attitude", "heroism");
	set("class","lama");
	set("shen_type", -1);
	
	set("max_qi", 500);
	set("max_jing", 450);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);
	set("combat_exp", 80000);
	set("score", 5000);

	set_skill("force", 50);
	set_skill("dodge", 55);
	set_skill("parry", 60);
	set_skill("strike", 60);
	set_skill("staff", 60);
	set_skill("cuff", 60);
	set_skill("jingang-chu", 70);
	set_skill("longxiang-banruo", 60);
	set_skill("yujiamu-quan", 60);

	map_skill("cuff", "yujiamu-quan");
        map_skill("force", "longxiang-banruo");
        map_skill("parry", "jingang-chu");
        map_skill("staff", "jingang-chu");

	prepare_skill("cuff", "yujiamu-quan");

        set("inquiry", ([
                "��Ը" : (: do_huanyuan :),
		"����" : (: do_huanyuan :),
		"����" : (: do_huanyuan :),
        ]) );

        setup();
	carry_object("/d/qilian/obj/fachu")->wield();
        carry_object(__DIR__"obj/lamajiasha")->wear();
}


int do_huanyuan()
{
        say("���ײ�˵��������ʲ��Т����үѽ? \n");
	return 1;
}
int accept_object(object who, object ob)
{
	if (ob->name()!="���͹�") {
	write("���ײ�����¶���Ի�ı��顣\n");
	command ("shake");
        return 1;
	}
	write(
	"���ײ�һ��������ү����ʩ��������롣\n");
        this_player()->set_temp("marks/��", 1);
        return 1;
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && !query_temp("leading")) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	
	if (ob->query_temp("mark/comin"))
                say( "���ײ�˫�ֺ�ʲЦ�����˵������λ" + RANK_D->query_respect(ob)
                                + "���������գ�\n");
	else
                say( "���ײ�˫�ֺ�ʲЦ�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����б�\n");
}
void destroy (object ob)
{
        destruct(ob);
        return;

}
